#!/usr/bin/env python3

"""
@file quick-cmake-build.py
@brief A Python script to run CMake builds with a progress bar and warning extraction.

This script runs `cmake --build build` while displaying a progress bar. It captures warnings and prints them above the progress bar.

@author mikomikotaishi
"""

import argparse
import os
import re
import shutil
import subprocess
import sys
import time
import threading

from typing import List, Optional, Set, Tuple

class ANSI:
    """
    ANSI escape codes for terminal text styling.
    """
    RESET: str = "\033[0m"
    RED: str = "\033[31m"
    GREEN: str = "\033[32m"
    YELLOW: str = "\033[33m"
    BLUE: str = "\033[34m"
    CLEAR_LINE: str = "\033[K"

def getConsoleWidth() -> int:
    """
    Gets the width of the current console window in characters.

    @return The number of characters that fit on the console width
    """
    try:
        return shutil.get_terminal_size().columns
    except (AttributeError, OSError):
        return 80

def visibleLength(s: str) -> int:
    """
    Calculates the visible length of a string (excluding ANSI escape sequences).

    @param s (str): The string to calculate the visible length of.

    @return int: The visible length of the string.
    """
    ansi_escape: re.Pattern = re.compile(r'\x1B(?:[@-Z\\-_]|\[[0-?]*[ -/]*[@-~])')
    return len(ansi_escape.sub('', s))

def runCommand(command: List[str], verbose: bool, capture_output: bool = False) -> Optional[str]:
    """
    Executes a shell command.

    @param command (List[str]): The command to be executed as a list of arguments.
    @param verbose (bool): If True, print the command output; otherwise, suppress it.
    @param capture_output (bool): If True, captures and returns the command's output.

    @return Optional[str]: Captured output if `capture_output` is True, otherwise None.

    @throws subprocess.CalledProcessError: If the command returns a non-zero exit code.
    """
    if verbose:
        print(f"Running command: {' '.join(command)}")
        result: subprocess.CompletedProcess[str] = subprocess.run(command, check=True, text=True)
    else:
        if capture_output:
            result: subprocess.CompletedProcess[str] = subprocess.run(
                command, check=True, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE
            )
            return result.stdout
        else:
            subprocess.run(command, check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    return None

def cleanBuildDirectory(preserve_deps: bool = False) -> None:
    """
    Removes the 'build' directory while optionally preserving dependencies.

    @param preserve_deps: If True, preserves dependencies and removes only project build files.
    """
    print(f"{ANSI.RED}Cleaning{ANSI.RESET} build files...")

    if not os.path.exists("build") and not os.path.exists("src/build"):
        print("No build directory found. Nothing to clean.")
        return

    if preserve_deps:
        print(f"{ANSI.BLUE}Preserving{ANSI.RESET} dependencies in build/_deps")

        extensions_to_remove: Tuple[str] = (".o", ".obj", ".a", ".so", ".dylib", ".dll", ".exe")
        for root, _, files in os.walk("build"):
            if "build/_deps" in root:
                continue
            for file in files:
                if file.endswith(extensions_to_remove):
                    os.remove(os.path.join(root, file))

        print(f"{ANSI.GREEN}Regenerating{ANSI.RESET} build system files...")
        subprocess.run(["cmake", "-G", "Ninja", "."],
                      cwd="build",
                      stdout=subprocess.DEVNULL,
                      stderr=subprocess.DEVNULL)

        print(f"{ANSI.GREEN}Preserved dependencies, only project files removed.{ANSI.RESET}")

    else:
        shutil.rmtree("build", ignore_errors=True)
        shutil.rmtree("src/build", ignore_errors=True)
        print(f"{ANSI.GREEN}Build directory fully cleaned.{ANSI.RESET}")

def runCMakeInit(verbose: bool, release: bool, sanitisers: List[str] = None) -> None:
    """
    Runs the CMake initialisation process with detailed progress reporting.

    @param verbose (bool): If True, prints all output. Otherwise, shows progress indicators.
    @param release (bool): If True, sets CMake to build for release. Otherwise, builds a debug build.
    @param sanitisers (List[str]): List of sanitisers to enable.
    """
    if sanitisers is None:
        sanitisers = []

    cmake_command = ["cmake", "-S", ".", "-G", "Ninja", "-B", "build"]

    address_san: bool = False
    thread_san: bool = False
    memory_san: bool = False
    undefined_san: bool = False
    leak_san: bool = False
    kernel_san: bool = False
    hardware_san: bool = False

    if release:
        print(f"{ANSI.BLUE}Building in{ANSI.RESET} Release mode (optimised)")
        cmake_command.append("-DCMAKE_BUILD_TYPE=Release")
        
        if sanitisers:
            print(f"{ANSI.YELLOW}Note:{ANSI.RESET} Sanitisers disabled in Release mode")
            sanitisers.clear()

    if sanitisers:
        cmake_command.append("-DENABLE_SANITIZERS=ON")

        for sanitiser in sanitisers:
            sanitiser = sanitiser.lower()

            match sanitiser:
                case "address":
                    if thread_san or memory_san:
                        print(f"{ANSI.RED}Error:{ANSI.RESET} AddressSanitizer (ASan) cannot be used with ThreadSanitizer (TSan) or MemorySanitizer (MSan).")
                        return
                    print(f"{ANSI.BLUE}Enabling{ANSI.RESET} AddressSanitizer")
                    address_san = True

                case "kernel-address":
                    print(f"{ANSI.BLUE}Enabling{ANSI.RESET} Kernel AddressSanitizer (KASan)")
                    kernel_san = True

                case "hw-address":
                    print(f"{ANSI.BLUE}Enabling{ANSI.RESET} Hardware AddressSanitizer (HWASan)")
                    hardware_san = True

                case "undefined":
                    print(f"{ANSI.BLUE}Enabling{ANSI.RESET} UndefinedBehaviorSanitizer (UBSan)")
                    undefined_san = True

                case "thread":
                    if address_san or memory_san:
                        print(f"{ANSI.RED}Error:{ANSI.RESET} ThreadSanitizer (TSan) cannot be used with AddressSanitizer (ASan) or MemorySanitizer (MSan).")
                        return
                    print(f"{ANSI.BLUE}Enabling{ANSI.RESET} ThreadSanitizer (TSan)")
                    thread_san = True

                case "memory":
                    if address_san or thread_san:
                        print(f"{ANSI.RED}Error:{ANSI.RESET} MemorySanitizer (MSan) cannot be used with AddressSanitizer (ASan) or ThreadSanitizer (TSan).")
                        return
                    print(f"{ANSI.BLUE}Enabling{ANSI.RESET} MemorySanitizer (MSan)")
                    memory_san = True

                case "leak":
                    print(f"{ANSI.BLUE}Enabling{ANSI.RESET} LeakSanitizer (LSan)")
                    leak_san = True

                case "all":
                    print(f"{ANSI.YELLOW}Enabling{ANSI.RESET} all compatible sanitisers")
                    address_san = True
                    undefined_san = True
                    leak_san = True

                case "all-kernel":
                    print(f"{ANSI.YELLOW}Enabling{ANSI.RESET} all sanitisers (Kernel AddressSanitizer)")
                    kernel_san = True
                    undefined_san = True
                    memory_san = True
                    leak_san = True

                case "all-hardware":
                    print(f"{ANSI.YELLOW}Enabling{ANSI.RESET} all sanitisers (Hardware AddressSanitizer)")
                    hardware_san = True
                    undefined_san = True
                    memory_san = True
                    leak_san = True

                case _:
                    print(f"{ANSI.YELLOW}Warning:{ANSI.RESET} Invalid sanitiser specified: {sanitiser}")

        if address_san:
            cmake_command.append("-DUSE_SANITIZER_ADDRESS=ON")
            cmake_command.append("-DUSE_SANITIZER_LEAK=ON")
        if kernel_san:
            cmake_command.append("-DUSE_SANITIZER_KERNEL=ON")
        if hardware_san:
            cmake_command.append("-DUSE_SANITIZER_HW=ON")
        if undefined_san:
            cmake_command.append("-DUSE_SANITIZER_UNDEFINED=ON")
        if thread_san:
            cmake_command.append("-DUSE_SANITIZER_THREAD=ON")
        if memory_san:
            cmake_command.append("-DUSE_SANITIZER_MEMORY=ON")
        if leak_san and not address_san:
            cmake_command.append("-DUSE_SANITIZER_LEAK=ON")

    if verbose:
        runCommand(cmake_command, verbose=True)
        return

    print(f"{ANSI.GREEN}Initialising{ANSI.RESET} openJuice build...")

    process: subprocess.Popen = subprocess.Popen(
        cmake_command,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    in_download: bool = False
    last_download_percent: int = -1
    cloning_repo: Optional[str] = None

    def processStderr() -> None:
        for line in process.stderr:
            line = line.strip()
            clone_match: Optional[re.Match] = re.search(r"Cloning into ['\"](.*?)['\"]", line)
            if clone_match:
                repo_name = clone_match.group(1).replace("-src", "")
                print(f"{ANSI.BLUE}Cloning{ANSI.RESET} {repo_name} dependency...")
            build_stopped = detectBuildStopped(line)
            if build_stopped:
                print(f"\r{ANSI.CLEAR_LINE}{ANSI.RED}Build stopped:{ANSI.RESET} {build_stopped}")

    stderr_thread = threading.Thread(target=processStderr, daemon=True)
    stderr_thread.start()

    try:
        for line in process.stdout:
            line = line.strip()

            if "compiler identification is" in line:
                print(f"Detecting {line}")

            download_match: Optional[re.Match] = re.search(r"\[download (\d+)% complete]", line)
            if download_match:
                percent = int(download_match.group(1))
                if not in_download:
                    print(f"{ANSI.BLUE}Downloading{ANSI.RESET} Boost library...")
                    in_download = True

                if percent != last_download_percent:
                    last_download_percent = percent
                    bar_length = 20
                    filled = int(bar_length * (percent / 100))
                    
                    bar = "=" * filled + (">" if filled < bar_length else "") + " " * (bar_length - filled - (1 if filled < bar_length else 0))
                    
                    print(f"\r{ANSI.CLEAR_LINE}[{bar}] {percent}%{ANSI.RESET}", end="", flush=True)

                if percent == 100:
                    print()
                    in_download = False

            clone_match: Optional[re.Match] = re.search(r"Cloning into ['\"](.*?)['\"]", line)
            if clone_match:
                repo_name = clone_match.group(1).replace("-src", "")
                cloning_repo = repo_name
                print(f"{ANSI.BLUE}Cloning{ANSI.RESET} {repo_name} dependency...")

            if line.startswith("HEAD is now at") and cloning_repo:
                print(f"{ANSI.GREEN}Finished{ANSI.RESET} cloning {cloning_repo}")
                cloning_repo = None

            if line.startswith("-- Configuring done"):
                print(f"{ANSI.BLUE}Finalising{ANSI.RESET} build configuration...")

            if line.startswith("-- Build files have been written"):
                print(f"{ANSI.GREEN}Build system{ANSI.RESET} configured successfully!")

            build_stopped: Optional[str] = detectBuildStopped(line)
            if build_stopped:
                print(f"\r{ANSI.CLEAR_LINE}{ANSI.RED}Build stopped:{ANSI.RESET} {build_stopped}")

        process.wait()
        stderr_thread.join(timeout=1)

    except KeyboardInterrupt:
        process.kill()
        sys.exit(1)

    if process.returncode != 0:
        raise subprocess.CalledProcessError(process.returncode, process.args)

def parseCMakeProgress(line: str) -> Optional[Tuple[int, int]]:
    """
    Extracts the current step and total steps from CMake build output.

    @param line (str): A line of CMake output.

    @return Optional[Tuple[int, int]]: A tuple (current_step, total_steps) if found, otherwise None.
    """
    match: Optional[re.Match] = re.search(r"\[(\d+)/(\d+)]", line)
    return (int(match.group(1)), int(match.group(2))) if match else None

def extractFilename(line: str) -> Optional[str]:
    """
    Extracts the filename from a compilation command.

    @param line (str): A line of CMake build output.

    @return Optional[str]: The extracted filename if found, otherwise None.
    """
    match: Optional[re.Match] = re.search(r"Building CXX object (.+\.cppm?)\.o", line)
    return match.group(1).strip() if match else None

def detectWarnings(line: str) -> Optional[str]:
    """
    Detects warnings in the compiler output.

    @param line (str): A line of compiler output.

    @return Optional[str]: The filename associated with a warning, if found.
    """
    match: Optional[re.Match] = re.search(r"([^:\s]+:\d+:\d+: warning: .+)", line)
    return match.group(1) if match else None

def detectErrors(line: str) -> Optional[str]:
    """
    Detects compilation errors in the compiler output.

    @param line (str): A line of compiler output.

    @return Optional[str]: The error message if found, otherwise None.
    """
    match: Optional[re.Match] = re.search(r"([^:\s]+:\d+:\d+: error: .+)", line)
    return match.group(1) if match else None

def detectBuildStopped(line: str) -> Optional[str]:
    """
    Detects build stopped messages from ninja.

    @param line (str): A line of compiler output.

    @return Optional[str]: The build stopped message if found, otherwise None.
    """
    match: Optional[re.Match] = re.search(r"ninja: build stopped: (.+)", line)
    return match.group(0) if match else None

def runCMakeBuild(verbose: bool) -> None:
    """
    Runs `cmake --build build` while showing a progress bar if `verbose` is False.

    @param verbose (bool): If True, prints build logs. Otherwise, shows a progress bar.
    """
    if verbose:
        runCommand(["cmake", "--build", "build"], verbose=True)
        return

    print(f"{ANSI.GREEN}Building{ANSI.RESET} openJuice...")

    process: subprocess.Popen = subprocess.Popen(
        ["cmake", "--build", "build"],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    first_line: str = process.stdout.readline().strip()
    if "ninja: no work to do" in first_line:
        print(f"{ANSI.GREEN}Everything up to date!{ANSI.RESET} No compilation needed.")
        process.wait()
        return

    bar_length: int = 40
    last_percentage: int = 0
    total_steps: int = 0
    current_step: int = 0
    current_file: Optional[str] = None
    bar: str = "-" * bar_length
    error_files: Set[str] = set()

    if first_line:
        progress = parseCMakeProgress(first_line)
        if progress:
            current_step, total_steps = progress
            percentage = int((current_step / total_steps) * 100)
            last_percentage = percentage
            filled = int(bar_length * (percentage / 100))
            bar = "#" * filled + "-" * (bar_length - filled)

        new_file = extractFilename(first_line)
        if new_file:
            current_file = new_file

    def updateProgressBar() -> None:
        width: int = len(str(total_steps)) if total_steps > 0 else 1
        
        filled = int(bar_length * (last_percentage / 100))
        progress_bar = "=" * filled + (">" if filled < bar_length else "") + " " * (bar_length - filled - (1 if filled < bar_length else 0))
        
        output_string: str = (
            f"\r{ANSI.CLEAR_LINE}[{progress_bar}] {last_percentage}% "
            f"[{current_step:{width}d}/{total_steps or 1}] "
            f"{ANSI.GREEN}Compiling:{ANSI.RESET} {current_file or ''} "
        )
        if visibleLength(output_string) > getConsoleWidth() - 1:
            output_string = output_string[:getConsoleWidth() - 1]
        print(output_string, end="", flush=True)

    updateProgressBar()

    error_lines: List[str] = []

    def readStderr() -> None:
        for line in process.stderr:
            line = line.strip()
            error_lines.append(line)
            error_msg = detectErrors(line)
            if error_msg:
                error_file = error_msg.split(':')[0]
                if error_file not in error_files:
                    print()
                    error_files.add(error_file)
                print(f"\r{ANSI.CLEAR_LINE}{ANSI.RED}Error:{ANSI.RESET} {error_msg}")
                updateProgressBar()
            build_stopped = detectBuildStopped(line)
            if build_stopped:
                print(f"\r{ANSI.CLEAR_LINE}{ANSI.RED}Build stopped:{ANSI.RESET} {build_stopped}")
                updateProgressBar()

    stderr_thread: threading.Thread = threading.Thread(target=readStderr, daemon=True)
    stderr_thread.start()

    try:
        for line in process.stdout:
            line = line.strip()

            warning_msg: Optional[str] = detectWarnings(line)
            if warning_msg:
                print(f"\r{ANSI.CLEAR_LINE}{ANSI.YELLOW}Warning:{ANSI.RESET} {warning_msg} (enable verbose for details)")
                updateProgressBar()

            error_msg: Optional[str] = detectErrors(line)
            if error_msg:
                error_file = error_msg.split(':')[0]
                if error_file not in error_files:
                    print()
                    error_files.add(error_file)
                print(f"\r{ANSI.CLEAR_LINE}{ANSI.RED}Error:{ANSI.RESET} {error_msg}")
                updateProgressBar()

            progress: Optional[Tuple[int, int]] = parseCMakeProgress(line)
            if progress:
                current_step, total_steps = progress
                percentage: int = int((current_step / total_steps) * 100)

                if percentage > last_percentage:
                    last_percentage = percentage
                    filled: int = int(bar_length * (percentage / 100))
                    bar = "#" * filled + "-" * (bar_length - filled)
                    updateProgressBar()

            new_file: Optional[str] = extractFilename(line)
            if new_file:
                current_file = new_file
                updateProgressBar()

            build_stopped: Optional[str] = detectBuildStopped(line)
            if build_stopped:
                print(f"\r{ANSI.CLEAR_LINE}{ANSI.RED}Build stopped:{ANSI.RESET} {build_stopped}")
                updateProgressBar()

        process.wait()
        stderr_thread.join(timeout=1)

        if process.returncode != 0:
            print(f"\r{ANSI.CLEAR_LINE}{ANSI.RED}Build failed!{ANSI.RESET} Check the errors above or run with --verbose for details.")
        else:
            print()

    except KeyboardInterrupt:
        process.kill()
        sys.exit(1)

    if process.returncode != 0:
        raise subprocess.CalledProcessError(process.returncode, process.args)

def main() -> int:
    """
    Main function to execute the build and dependency generation steps for the openJuice project.
    Supports various flags for different operations.

    @return int: Return code (0 for success, non-zero for failure).
    """
    parser: argparse.ArgumentParser = argparse.ArgumentParser(description="Build script for openJuice project.")

    operation_group: argparse._MutuallyExclusiveGroup = parser.add_mutually_exclusive_group()
    parser.add_argument("-r", "--release", action="store_true",
                        help="Build in release mode (optimised, no sanitisers, NDEBUG defined)")
    
    operation_group.add_argument("-c", "--clean", action="store_true",
                                help="Clean only project source files (no building)")
    operation_group.add_argument("-ca", "--clean-all", action="store_true",
                                help="Clean entire project, including dependencies (no building)")
    operation_group.add_argument("-n", "--new", action="store_true",
                                help="Cleans the build directory and rebuilds everything, including dependencies (mandatory for first build)")
    operation_group.add_argument("-pd", "--preserve-deps", action="store_true",
                                help="Cleans the build directory and rebuilds everything (excluding dependencies)")

    parser.add_argument("-g", "--graph", action="store_true", help="Generate dependency graph")
    parser.add_argument("-s", "--sanitiser", "--sanitizer", nargs="+", default=[],
                        help="Enable sanitisers (address, undefined, thread, memory, leak, all)")
    parser.add_argument("-v", "--verbose", action="store_true",
                        help="Enable verbose output (lacks progress bar or other graphical features)")

    args: argparse.Namespace = parser.parse_args()
    release: bool = args.release
    clean: bool = args.clean
    clean_all: bool = args.clean_all
    generate_graph: bool = args.graph
    build_new: bool = args.new
    preserve_deps: bool = args.preserve_deps
    verbose: bool = args.verbose
    sanitisers: List[str] = args.sanitiser

    start_time: float = time.time()

    try:
        if clean_all:
            cleanBuildDirectory(False)
            return 0
        elif clean:
            cleanBuildDirectory(True)
            return 0
        elif build_new:
            cleanBuildDirectory(False)
            runCMakeInit(verbose, release, sanitisers)
        elif preserve_deps:
            cleanBuildDirectory(True)
            runCMakeInit(verbose, release, sanitisers)
        else:
            if sanitisers and not os.path.exists("build/CMakeCache.txt"):
                runCMakeInit(verbose, release, sanitisers)

        runCMakeBuild(verbose)

        if generate_graph:
            print(f"{ANSI.GREEN}Generating{ANSI.RESET} dependency graph (output: graph.dot, dependencies.png)")
            runCommand(["mgt"], verbose)
            runCommand(["dot", "-Tpng", "graph.dot", "-o", "dependencies.png"], verbose)

    except subprocess.CalledProcessError as e:
        if verbose:
            print(f"Error: {e}", file=sys.stderr)
        return e.returncode

    end_time: float = time.time()
    elapsed_time: float = round(end_time - start_time, 3)

    print(f"{ANSI.GREEN}Build complete!{ANSI.RESET} Time taken: {elapsed_time:.3f} seconds")

    return 0

if __name__ == "__main__":
    sys.exit(main())
