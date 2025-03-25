///usr/bin/env jbang "$0" "$@" ; exit $?
//DEPS info.picocli:picocli:4.7.5

/**
 * QuickCMakeBuild.java
 * A JBang (Java) script to run CMake builds with a progress bar, warning and error extraction.
 *
 * This script runs "cmake --build build" while displaying a progress bar.
 * It also extracts warnings and errors from the build output,
 * printing them above the progress bar.
 *
 * Usage:
 *   jbang QuickCMakeBuild.java [options]
 *
 * Options:
 *   -h, --help          Show help message and exit
 *   -V, --version       Print version information and exit
 *   -c, --clean         Clean only project source files (no building)
 *   -ca, --clean-all    Clean entire project, including dependencies (no building)
 *   -n, --new           Clean the build directory and rebuilds everything, including dependencies
 *   -pd, --preserve-deps Clean the build directory and rebuilds everything (excluding dependencies)
 *   -g, --graph         Generate dependency graph
 *   -s, --sanitiser     Enable sanitisers (address, undefined, thread, memory, leak)
 *   -v, --verbose       Enable verbose output (disables progress bar)
 *
 * Sanitisers:
 *   address             AddressSanitizer (ASan)
 *   kernel-address      Kernel AddressSanitizer (KASan)
 *   hw-address          Hardware AddressSanitizer (HWASan)
 *   undefined           UndefinedBehaviorSanitizer (UBSan)
 *   thread              ThreadSanitizer (TSan)
 *   memory              MemorySanitizer (MSan)
 *   leak                LeakSanitizer (LSan)
 *   all                 All compatible sanitisers (ASan, UBSan, LSan)
 *   all-kernel          All kernel sanitisers (KASan, UBSan, MSan, LSan)
 *   all-hardware        All hardware sanitisers (HWASan, UBSan, MSan, LSan)
 *
 * @author mikomikotaishi
 */

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.InputStreamReader;
import java.io.IOException;
import java.nio.file.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;
import java.util.stream.Collectors;

import picocli.CommandLine;
import picocli.CommandLine.*;

/**
 * Class used to call CMake build.
 */
@Command(name = "QuickCMakeBuild", mixinStandardHelpOptions = true, 
         description = "Build script for openJuice project",
         version = "0.0.1")
public class QuickCMakeBuild implements Callable<Integer> {

    private static class ANSI {
        private ANSI() {}

        public static final String RESET = "\033[0m";
        public static final String RED = "\033[31m";
        public static final String GREEN = "\033[32m";
        public static final String YELLOW = "\033[33m";
        public static final String BLUE = "\033[34m";
        public static final String CLEAR_LINE = "\033[K";
    }

    static class BuildOperationGroup {
        @Option(names = {"-c", "--clean"}, description = "Clean only project source files (no building)")
        boolean clean;

        @Option(names = {"-ca", "--clean-all"}, description = "Clean entire project, including dependencies (no building)")
        boolean cleanall;

        @Option(names = {"-n", "--new"}, description = "Cleans the build directory and rebuilds everything, including dependencies (mandatory for first build)")
        boolean buildNew;

        @Option(names = {"-pd", "--preserve-deps"}, description = "Cleans the build directory and rebuilds everything (excluding dependencies)")
        boolean preserveDeps;
    }

    @ArgGroup(exclusive = true)
    private BuildOperationGroup buildOperation = new BuildOperationGroup();

    @Option(names = {"-g", "--graph"}, description = "Generate dependency graph")
    private boolean generateGraph = false;

    @Option(names = {"-s", "--sanitiser", "--sanitizer"}, description = "Enable sanitisers (address, undefined, thread, memory, leak)")
    private List<String> sanitisers = new ArrayList<>();

    @Option(names = {"-v", "--verbose"}, description = "Enable verbose output (lacks progress bar or other graphical features)")
    private boolean verbose = false;

    /**
     * Gets the width of the console window in characters.
     * 
     * @return int: the console width or 80 if not available.
     */
    public static int getConsoleWidth() {
        try {
            String os = System.getProperty("os.name").toLowerCase();
            if (os.contains("win")) {
                Process p = Runtime.getRuntime().exec(new String[]{"cmd", "/c", "mode con"});
                try (BufferedReader reader = new BufferedReader(new InputStreamReader(p.getInputStream()))) {
                    String line;
                    while ((line = reader.readLine()) != null) {
                        if (line.contains("Columns"))
                            return Integer.parseInt(line.replaceAll("\\D+", "")) + 20;
                    }
                }
            } else {
                Process p = Runtime.getRuntime().exec(new String[]{"stty", "size"});
                try (BufferedReader reader = new BufferedReader(new InputStreamReader(p.getInputStream()))) {
                    String line = reader.readLine();
                    if (line != null)
                        return Integer.parseInt(line.split(" ")[1]) + 20;
                }
            }
        } catch (Exception e) {
            
        }
        return 80;
    }

    /**
     * Calculates the visible length of a string (excluding ANSI escape sequences).
     * 
     * @param s the string to measure.
     * @return int: the visible length.
     */
    public static int visibleLength(String s) {
        String ansiRegex = "\\x1B(?:[@-Z\\\\-_]|\\[[0-?]*[ -/]*[@-~])";
        return s.replaceAll(ansiRegex, "").length();
    }

    /**
     * Executes a shell command.
     * 
     * @param command list of command arguments.
     * @param verbose if true, prints the command output.
     * @param captureOutput if true, returns the command's output.
     * @return String: the output string if captured, otherwise null.
     * @throws IOException if an I/O error occurs.
     * @throws InterruptedException if interrupted.
     */
    public static String runCommand(List<String> command, boolean verbose, boolean captureOutput)
            throws IOException, InterruptedException {
        if (verbose)
            System.out.println("Running command: " + String.join(" ", command));
        ProcessBuilder pb = new ProcessBuilder(command);
        
        if (!verbose && !captureOutput) {
            pb.redirectOutput(ProcessBuilder.Redirect.DISCARD);
            pb.redirectError(ProcessBuilder.Redirect.DISCARD);
        }
        
        Process proc = pb.start();
        if (captureOutput) {
            try (BufferedReader reader = new BufferedReader(new InputStreamReader(proc.getInputStream()))) {
                String output = reader.lines().collect(Collectors.joining("\n"));
                proc.waitFor();
                return output;
            }
        } else {
            proc.waitFor();
            return null;
        }
    }

    /**
     * Recursively deletes the specified directory.
     * 
     * @param path the path to the directory.
     * @throws IOException if deletion fails.
     */
    public static void deleteDirectory(Path path) throws IOException {
        if (Files.exists(path)) {
            Files.walk(path)
                .sorted(Comparator.reverseOrder())
                .forEach(p -> {
                    try {
                        Files.delete(p);
                    } catch (IOException e) {
                        throw new RuntimeException(e);
                    }
                });
        }
    }

    /**
     * Cleans the build directories ("build" and "src/build") if they exist.
     * 
     * @param verbose if true, prints detailed messages.
     * @param preserveDeps if true, preserves the build/_deps directory
     */
    public static void cleanBuildDirectory(boolean verbose, boolean preserveDeps) throws InterruptedException {
        System.out.println(String.format("%sCleaning%s build files...", ANSI.RED, ANSI.RESET));
        
        Path buildDir = Paths.get("build");
        Path srcBuildDir = Paths.get("src/build");
        
        if (!Files.exists(buildDir) && !Files.exists(srcBuildDir)) {
            System.out.println("No build directory found. Nothing to clean.");
            return;
        }
        
        try {
            if (preserveDeps && Files.exists(buildDir)) {
                System.out.println(String.format("%sPreserving%s dependencies in build/_deps", ANSI.BLUE, ANSI.RESET));
                
                Set<String> extensionsToRemove = new HashSet<>(
                    Arrays.asList(".o", ".obj", ".a", ".so", ".dylib", ".dll", ".exe")
                );
                
                Files.walk(buildDir)
                    .filter(path -> !path.toString().contains("build" + File.separator + "_deps"))
                    .filter(path -> Files.isRegularFile(path))
                    .filter(path -> {
                        String filename = path.getFileName().toString();
                        for (String ext: extensionsToRemove)
                            if (filename.endsWith(ext)) 
                                return true;
                        return false;
                    })
                    .forEach(path -> {
                        try {
                            Files.delete(path);
                            if (verbose) 
                                System.out.println("Removed: " + path);
                        } catch (IOException e) {
                            System.err.println("Failed to delete: " + path);
                        }
                    });
                
                System.out.println(String.format("%sRegenerating%s build system files...", ANSI.GREEN, ANSI.RESET));
                ProcessBuilder pb = new ProcessBuilder("cmake", "-G", "Ninja", ".");
                pb.directory(buildDir.toFile());
                pb.redirectOutput(ProcessBuilder.Redirect.DISCARD);
                pb.redirectError(ProcessBuilder.Redirect.DISCARD);
                pb.start().waitFor();
                
                System.out.println(String.format("%sPreserved dependencies, only project files removed.%s", ANSI.GREEN, ANSI.RESET));
            } else {
                if (Files.exists(buildDir))
                    deleteDirectory(buildDir);
                if (Files.exists(srcBuildDir))
                    deleteDirectory(srcBuildDir);
                
                System.out.println(String.format("%sBuild directory fully cleaned.%s", ANSI.GREEN, ANSI.RESET));
            }
        } catch (IOException e) {
            System.err.println("Error cleaning build directory: " + e.getMessage());
            if (verbose)
                e.printStackTrace();
        }
    }

    /**
     * Runs CMake initialisation ("cmake -S . -G Ninja -B build").
     * 
     * @param verbose if true, shows full output.
     * @throws IOException if an I/O error occurs.
     * @throws InterruptedException if interrupted.
     */
    public static void runCMakeInit(boolean verbose, List<String> sanitisers) throws IOException, InterruptedException {
        if (verbose) {
            runCommand(Arrays.asList("cmake", "-S", ".", "-G", "Ninja", "-B", "build"), true, false);
            return;
        }

        List<String> cmakeCommand = new ArrayList<>(Arrays.asList("cmake", "-S", ".", "-G", "Ninja", "-B", "build"));

        boolean addressSan = false;
        boolean threadSan = false;
        boolean memorySan = false;
        boolean undefinedSan = false;
        boolean leakSan = false;
        boolean kernelSan = false;
        boolean hardwareSan = false;

        if (!sanitisers.isEmpty()) {
            cmakeCommand.add("-DENABLE_SANITIZERS=ON");
            
            for (String sanitiser: sanitisers) {
                switch (sanitiser.toLowerCase()) {
                    case "address":
                        if (threadSan || memorySan) {
                            System.out.println(String.format("%sError:%s AddressSanitizer (ASan) cannot be used with ThreadSanitizer (TSan) or MemorySanitizer (MSan).", ANSI.RED, ANSI.RESET));
                            return;
                        }
                        System.out.println(String.format("%sEnabling%s AddressSanitizer", ANSI.BLUE, ANSI.RESET));
                        addressSan = true;
                        break;
            
                    case "kernel-address":
                        System.out.println(String.format("%sEnabling%s Kernel AddressSanitizer (KASan)", ANSI.BLUE, ANSI.RESET));
                        kernelSan = true;
                        break;
            
                    case "hw-address":
                        System.out.println(String.format("%sEnabling%s Hardware AddressSanitizer (HWASan)", ANSI.BLUE, ANSI.RESET));
                        hardwareSan = true;
                        break;
            
                    case "undefined":
                        System.out.println(String.format("%sEnabling%s UndefinedBehaviorSanitizer (UBSan)", ANSI.BLUE, ANSI.RESET));
                        undefinedSan = true;
                        break;
            
                    case "thread":
                        if (addressSan || memorySan) {
                            System.out.println(String.format("%sError:%s ThreadSanitizer (TSan) cannot be used with AddressSanitizer (ASan) or MemorySanitizer (MSan).", ANSI.RED, ANSI.RESET));
                            return;
                        }
                        System.out.println(String.format("%sEnabling%s ThreadSanitizer", ANSI.BLUE, ANSI.RESET));
                        threadSan = true;
                        break;
            
                    case "memory":
                        if (addressSan || threadSan) {
                            System.out.println(String.format("%sError:%s MemorySanitizer (MSan) cannot be used with AddressSanitizer (ASan) or ThreadSanitizer (TSan).", ANSI.RED, ANSI.RESET));
                            return;
                        }
                        System.out.println(String.format("%sEnabling%s MemorySanitizer", ANSI.BLUE, ANSI.RESET));
                        memorySan = true;
                        break;
            
                    case "leak":
                        System.out.println(String.format("%sEnabling%s LeakSanitizer (LSan)", ANSI.BLUE, ANSI.RESET));
                        leakSan = true;
                        break;
            
                    case "all":
                        System.out.println(String.format("%sEnabling%s all compatible sanitisers", ANSI.YELLOW, ANSI.RESET));
                        addressSan = true;
                        undefinedSan = true;
                        leakSan = true;
                        break;
            
                    case "all-kernel":
                        System.out.println(String.format("%sEnabling%s all sanitisers (Kernel AddressSanitizer)", ANSI.YELLOW, ANSI.RESET));
                        kernelSan = true;
                        undefinedSan = true;
                        memorySan = true;
                        leakSan = true;
                        break;
            
                    case "all-hardware":
                        System.out.println(String.format("%sEnabling%s all sanitisers (Hardware AddressSanitizer)", ANSI.YELLOW, ANSI.RESET));
                        hardwareSan = true;
                        undefinedSan = true;
                        memorySan = true;
                        leakSan = true;
                        break;
            
                    default:
                        System.out.println(String.format("%sWarning:%s Invalid sanitiser specified: %s", ANSI.YELLOW, ANSI.RESET, sanitiser));
                }
            }            
            
            if (addressSan) {
                cmakeCommand.add("-DUSE_SANITIZER_ADDRESS=ON");
                cmakeCommand.add("-DUSE_SANITIZER_LEAK=ON"); 
            }
            if (kernelSan)
                cmakeCommand.add("-DUSE_SANITIZER_KERNEL=ON");
            if (hardwareSan)
                cmakeCommand.add("-DUSE_SANITIZER_HW=ON");
            if (undefinedSan)
                cmakeCommand.add("-DUSE_SANITIZER_UNDEFINED=ON");
            if (threadSan)
                cmakeCommand.add("-DUSE_SANITIZER_THREAD=ON");
            if (memorySan)
                cmakeCommand.add("-DUSE_SANITIZER_MEMORY=ON");
            if (leakSan && !addressSan) 
                cmakeCommand.add("-DUSE_SANITIZER_LEAK=ON"); 
            
        }
        
        System.out.println(String.format("%sInitialising%s openJuice build", ANSI.GREEN, ANSI.RESET));
        
        ProcessBuilder pb = new ProcessBuilder(cmakeCommand);
        pb.redirectErrorStream(false);
        Process proc = pb.start();
        
        boolean inDownload = false;
        int lastDownloadPercent = -1;
        String cloningRepo = null;
        
        Thread stderrThread = new Thread(() -> {
            try (BufferedReader reader = new BufferedReader(new InputStreamReader(proc.getErrorStream()))) {
                String line;
                while ((line = reader.readLine()) != null) {
                    line = line.trim();
                    Matcher cloneMatcher = Pattern.compile("Cloning into ['\"](.*?)['\"]").matcher(line);
                    if (cloneMatcher.find()) {
                        String repoName = cloneMatcher.group(1).replace("-src", "");
                        System.out.println(String.format("%sCloning%s %s dependency...", ANSI.BLUE, ANSI.RESET, repoName));
                    }
                }
            } catch (IOException e) {

            }
        });
        stderrThread.setDaemon(true);
        stderrThread.start();
        
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(proc.getInputStream()))) {
            String line;
            while ((line = reader.readLine()) != null) {
                line = line.trim();
                
                if (line.contains("compiler identification is"))
                    System.out.println("Detecting " + line);
                
                Matcher downloadMatcher = Pattern.compile("\\[download (\\d+)% complete]").matcher(line);
                if (downloadMatcher.find()) {
                    int percent = Integer.parseInt(downloadMatcher.group(1));
                    if (!inDownload) {
                        System.out.println(String.format("%sDownloading%s Boost library...", ANSI.BLUE, ANSI.RESET));
                        inDownload = true;
                    }
                    
                    if (percent != lastDownloadPercent) {
                        lastDownloadPercent = percent;
                        int barLength = 20;
                        int filled = (int)(barLength * (percent / 100.0));
                        
                        String bar = new String(new char[filled]).replace("\0", "=") + 
                                    (filled < barLength ? ">" : "") + 
                                    new String(new char[barLength - filled - (filled < barLength ? 1 : 0)]).replace("\0", " ");
                                    
                        System.out.print(String.format("\r%s[%s] %d%%%s", ANSI.CLEAR_LINE, bar, percent, ANSI.RESET));
                    }
                    
                    if (percent == 100) {
                        System.out.println();
                        inDownload = false;
                    }
                }
                
                Matcher cloneMatcher = Pattern.compile("Cloning into ['\"](.*?)['\"]").matcher(line);
                if (cloneMatcher.find()) {
                    String repoName = cloneMatcher.group(1).replace("-src", "");
                    cloningRepo = repoName;
                    System.out.println(String.format("%sCloning%s %s dependency...", ANSI.BLUE, ANSI.RESET, repoName));
                }
                
                if (line.startsWith("HEAD is now at") && cloningRepo != null) {
                    System.out.println(String.format("%sFinished%s cloning %s", ANSI.GREEN, ANSI.RESET, cloningRepo));
                    cloningRepo = null;
                }
                
                if (line.startsWith("-- Configuring done"))
                    System.out.println(String.format("%sFinalising%s build configuration...", ANSI.BLUE, ANSI.RESET));
                
                if (line.startsWith("-- Build files have been written"))
                    System.out.println(String.format("%sBuild system%s configured successfully", ANSI.GREEN, ANSI.RESET));
            }
        }
        
        proc.waitFor();
        stderrThread.join(1000);
        
        if (proc.exitValue() != 0)
            throw new IOException("CMake initialisation failed with exit code " + proc.exitValue());
    }

    /**
     * Parses a line for progress in the format [current/total].
     * 
     * @param line the input line.
     * @return int[]: an int array of length 2 {current, total} if found, otherwise null.
     */
    public static int[] parseCMakeProgress(String line) {
        Pattern p = Pattern.compile("\\[(\\d+)/(\\d+)]");
        Matcher m = p.matcher(line);
        if (m.find()) {
            int current = Integer.parseInt(m.group(1));
            int total = Integer.parseInt(m.group(2));
            return new int[]{current, total};
        }
        return null;
    }

    /**
     * Extracts the filename from a compilation command line.
     * 
     * @param line the input line.
     * @return the filename if found, otherwise null.
     */
    public static String extractFilename(String line) {
        Pattern p = Pattern.compile("Building CXX object (.+\\.cppm?)\\.o");
        Matcher m = p.matcher(line);
        if (m.find()) 
            return m.group(1).trim();
        return null;
    }

    /**
     * Detects warnings in a line.
     * 
     * @param line the input line.
     * @return the warning message if found, otherwise null.
     */
    public static String detectWarnings(String line) {
        Pattern p = Pattern.compile("([^:\\s]+:\\d+:\\d+: warning: .+)");
        Matcher m = p.matcher(line);
        if (m.find())
            return m.group(1);
        return null;
    }

    /**
     * Detects errors in a line.
     * 
     * @param line the input line.
     * @return the error message if found, otherwise null.
     */
    public static String detectErrors(String line) {
        Pattern p = Pattern.compile("([^:\\s]+:\\d+:\\d+: error: .+)");
        Matcher m = p.matcher(line);
        if (m.find())
            return m.group(1);
        return null;
    }

    /**
     * Detects "build stopped" messages in a line.
     * 
     * @param line the input line.
     * @return the build stopped message if found, otherwise null.
     */
    public static String detectBuildStopped(String line) {
        Pattern p = Pattern.compile("ninja: build stopped: (.+)");
        Matcher m = p.matcher(line);
        if (m.find())
            return m.group(0);
        return null;
    }

    /**
     * Runs CMake build ("cmake --build build") while displaying a progress bar.
     * The progress bar shows the percentage, file count ([current/total]) with space padding, and the current file.
     * Warnings and errors are printed above the progress bar.
     *
     * @param verbose if true, shows full build output instead of a progress bar.
     * @throws IOException if an I/O error occurs.
     * @throws InterruptedException if interrupted.
     */
    public static void runCMakeBuild(boolean verbose) throws IOException, InterruptedException {
        if (verbose) {
            runCommand(Arrays.asList("cmake", "--build", "build"), true, false);
            return;
        }
        System.out.println(String.format("%sBuilding%s openJuice...", ANSI.GREEN, ANSI.RESET));

        ProcessBuilder pb = new ProcessBuilder("cmake", "--build", "build");
        pb.redirectErrorStream(false);
        Process proc = pb.start();

        try (
            BufferedReader stdout = new BufferedReader(new InputStreamReader(proc.getInputStream()));
            BufferedReader stderr = new BufferedReader(new InputStreamReader(proc.getErrorStream()))
        ) {
            String firstLine = stdout.readLine();
            if (firstLine != null && firstLine.contains("ninja: no work to do")) {
                System.out.println(String.format("%sEverything up to date!%s No compilation needed.", ANSI.GREEN, ANSI.RESET));
                proc.waitFor();
                return;
            }

            final int barLength = 40;
            final String[] barRef = { 
                ">" + new String(new char[barLength-1]).replace("\0", " ") 
            };
            final int[] lastPercentageRef = { 0 };
            final int[] currentStepRef = { 0 };
            final int[] totalStepsRef = { 0 };
            final String[] currentFileRef = { null };
            Set<String> errorFiles = new HashSet<>();
            
            if (firstLine != null) {
                firstLine = firstLine.trim();
                int[] progress = parseCMakeProgress(firstLine);
                if (progress != null) {
                    currentStepRef[0] = progress[0];
                    totalStepsRef[0] = progress[1];
                    int percentage = (int)((currentStepRef[0] / (double)totalStepsRef[0]) * 100);
                    lastPercentageRef[0] = percentage;
                    int filled = (int)(barLength * (percentage / 100.0));
                    
                    barRef[0] = new String(new char[filled]).replace("\0", "=") + 
                               (filled < barLength ? ">" : "") + 
                               new String(new char[barLength - filled - (filled < barLength ? 1 : 0)]).replace("\0", " ");
                }
                
                String newFile = extractFilename(firstLine);
                if (newFile != null)
                    currentFileRef[0] = newFile;
            }

            CountDownLatch latch = new CountDownLatch(1);
            Thread stderrThread = new Thread(() -> {
                try {
                    String line;
                    while ((line = stderr.readLine()) != null) {
                        line = line.trim();
                        String errorMsg = detectErrors(line);
                        if (errorMsg != null) {
                            String errorFile = errorMsg.split(":")[0];
                            if (!errorFiles.contains(errorFile)) {
                                System.out.println();
                                errorFiles.add(errorFile);
                            }
                            System.out.println(String.format("\r%s%sError:%s %s", ANSI.CLEAR_LINE, ANSI.RED, ANSI.RESET, errorMsg));
                            updateProgressBar(barRef[0], lastPercentageRef[0], currentStepRef[0], 
                                              totalStepsRef[0], currentFileRef[0]);
                        }
                        String buildStopped = detectBuildStopped(line);
                        if (buildStopped != null) {
                            System.out.println(String.format("\r%s%sBuild stopped:%s %s", ANSI.CLEAR_LINE, ANSI.RED, ANSI.RESET, buildStopped));
                            updateProgressBar(barRef[0], lastPercentageRef[0], currentStepRef[0], 
                                             totalStepsRef[0], currentFileRef[0]);
                        }
                    }
                } catch (IOException e) {

                } finally {
                    latch.countDown();
                }
            });
            stderrThread.setDaemon(true);
            stderrThread.start();

            Runnable updateBar = () -> updateProgressBar(barRef[0], lastPercentageRef[0], 
                                                         currentStepRef[0], totalStepsRef[0], currentFileRef[0]);

            updateBar.run();

            String line;
            while ((line = stdout.readLine()) != null) {
                line = line.trim();
                
                String warningMsg = detectWarnings(line);
                if (warningMsg != null) {
                    System.out.println(String.format("\r%s%sWarning:%s %s (enable verbose for details)", ANSI.CLEAR_LINE, ANSI.YELLOW, ANSI.RESET, warningMsg));
                    updateBar.run();
                }
                
                String errorMsg = detectErrors(line);
                if (errorMsg != null) {
                    String errorFile = errorMsg.split(":")[0];
                    if (!errorFiles.contains(errorFile)) {
                        System.out.println();
                        errorFiles.add(errorFile);
                    }
                    System.out.println(String.format("\r%s%sError:%s %s", ANSI.CLEAR_LINE, ANSI.RED, ANSI.RESET, errorMsg));
                    updateBar.run();
                }

                int[] progress = parseCMakeProgress(line);
                if (progress != null) {
                    currentStepRef[0] = progress[0];
                    totalStepsRef[0] = progress[1];
                    int percentage = (int)((currentStepRef[0] / (double)totalStepsRef[0]) * 100);
                    if (percentage > lastPercentageRef[0]) {
                        lastPercentageRef[0] = percentage;
                        int filled = (int)(barLength * (percentage / 100.0));
                        
                        barRef[0] = new String(new char[filled]).replace("\0", "=") + 
                                   (filled < barLength ? ">" : "") + 
                                   new String(new char[barLength - filled - (filled < barLength ? 1 : 0)]).replace("\0", " ");
                                   
                        updateBar.run();
                    }
                }

                String newFile = extractFilename(line);
                if (newFile != null) {
                    currentFileRef[0] = newFile;
                    updateBar.run();
                }
                String buildStopped = detectBuildStopped(line);
                if (buildStopped != null) {
                    System.out.println(String.format("\r%s%sBuild stopped:%s %s", ANSI.CLEAR_LINE, ANSI.RED, ANSI.RESET, buildStopped));
                    updateBar.run();
                }
            }

            proc.waitFor();
            latch.await(1000, TimeUnit.MILLISECONDS);
            
            if (proc.exitValue() != 0) {
                System.out.println(String.format("\r%s%sBuild failed!%s Check the errors above or run with --verbose for details.", ANSI.CLEAR_LINE, ANSI.RED, ANSI.RESET));
                throw new IOException("Build failed with exit code " + proc.exitValue());
            } else {
                System.out.println();
            }
        }
    }
    
    /**
     * Updates the progress bar display.
     * 
     * @param bar The progress bar
     * @param percentage The percentage of files completed
     * @param current The current number of files completed
     * @param total The total number of files needed to handle
     * @param file The name of the current file being handled
     */
    private static void updateProgressBar(String bar, int percentage, int current, int total, String file) {
        int width = String.valueOf(total).length();
        String progressStr = String.format("[%s] %d%% [%"+width+"d/%"+width+"d] %sCompiling:%s %s", 
                          bar, percentage, current, total > 0 ? total : 1, 
                          ANSI.GREEN, ANSI.RESET, file != null ? file : "");
        
        String outputString = "\r" + ANSI.CLEAR_LINE + progressStr;
        
        if (visibleLength(outputString) > getConsoleWidth() - 1) {
            int visibleLimit = getConsoleWidth() - 1;
            StringBuilder sb = new StringBuilder();
            int visibleCount = 0;
            
            for (int i = 0; i < outputString.length(); ++i) {
                String substr = outputString.substring(i, i + 1);
                if (substr.equals("\033")) {
                    int j = i;
                    while (j < outputString.length() && outputString.charAt(j) != 'm') j++;
                    if (j < outputString.length()) {
                        sb.append(outputString.substring(i, j + 1));
                        i = j;
                    }
                } else {
                    sb.append(substr);
                    visibleCount++;
                    if (visibleCount >= visibleLimit) break;
                }
            }
            outputString = sb.toString();
        }
        
        System.out.print(outputString);
    }

    /**
     * Calls the script.
     * 
     * @return Integer: the return value of the script.
     */
    @Override
    public Integer call() {
        long startTime = System.currentTimeMillis();
        
        try {
            if (buildOperation.cleanall) {
                cleanBuildDirectory(verbose, false);
                return 0;
            } else if (buildOperation.clean) {
                cleanBuildDirectory(verbose, true);
                return 0;
            } else if (buildOperation.buildNew) {
                cleanBuildDirectory(verbose, false);
                runCMakeInit(verbose, sanitisers);
            } else if (buildOperation.preserveDeps) {
                cleanBuildDirectory(verbose, true);
                runCMakeInit(verbose, sanitisers);
            }
            
            runCMakeBuild(verbose);
            
            if (generateGraph) {
                System.out.println(String.format("%sGenerating%s dependency graph (output: graph.dot, dependencies.png)", ANSI.GREEN, ANSI.RESET));
                runCommand(Arrays.asList("mgt"), verbose, false);
                runCommand(Arrays.asList("dot", "-Tpng", "graph.dot", "-o", "dependencies.png"), verbose, false);
            }
            
            long endTime = System.currentTimeMillis();
            double elapsedTime = (endTime - startTime) / 1000.0;
            System.out.printf("%sBuild complete!%s Time taken: %.3f seconds%n", ANSI.GREEN, ANSI.RESET, elapsedTime);
        } catch (Exception e) {
            if (verbose)
                e.printStackTrace();
            return 1;
        }
        return 0;
    }

    public static void main(String[] args) {
        int exitCode = new CommandLine(new QuickCMakeBuild()).execute(args);
        System.exit(exitCode);
    }
}
