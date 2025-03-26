# openJuice

## Overview:
🍊 Open-source re-engineering of the game [*100% Orange Juice!*](https://store.steampowered.com/app/282800).
This does not aim to be a one-to-one recreation of the game but rather a port of the game as a TUI program.

This project is written independently for fun and as a learning project, and not written for the purposes of piracy. The author(s) encourage the user to support the original developers. No code has been obtained through decompiling, disassembling, or reverse-engineering the original program.

Tested for Linux. Windows and MacOS support untested.

~~Check out my [Rust rewrite](https://github.com/mikomikotaishi/openjuice-rs).~~ No active development until this is finished; currently privated.

[![GPLv3](https://img.shields.io/badge/license-GPLv3-green)](#)

## Build:
Requires C++23, and a build system such as CMake (minimum version 3.30) or XMake. The program has its own bindings for the standard library.

Note: please compile with Clang for now (as it looks like GCC still has problems compiling modules).

### CMake
Requires CMake ≥3.30. 
Any way of calling CMake is fine, for example `cmake -S . -G Ninja -B build` to call Ninja to generate build files and `cmake --build build` to build. `./openJuice` to run.

We have also written a Python script to simplify using CMake, which can be run with `./quick-cmake-build.py`. (Simply execute the script `quick-cmake-build.py` to compile the program with CMake.) If JBang is installed, `QuickCMakeBuild.java` can also be executed as a script.

`quick-cmake-build.py` help:
```
usage: quick-cmake-build.py [-h] [-c | -ca | -n | -pd] [-g] [-s SANITISER [SANITISER ...]] [-v]

Build script for openJuice project.

options:
  -h, --help            show this help message and exit
  -c, --clean           Clean only project source files (no building)
  -ca, --clean-all      Clean entire project, including dependencies (no building)
  -n, --new             Cleans the build directory and rebuilds everything, including dependencies (mandatory for first build)
  -pd, --preserve-deps  Cleans the build directory and rebuilds everything (excluding dependencies)
  -g, --graph           Generate dependency graph
  -s, --sanitiser, --sanitizer SANITISER [SANITISER ...]
                        Enable sanitisers (address, undefined, thread, memory, leak, all)
  -v, --verbose         Enable verbose output (lacks progress bar or other graphical features)
```

`QuickCMakeBuild.java` help:
```
Usage: QuickCMakeBuild [-ghvV] [-s=<sanitisers>]... [-c | -ca | -n | -pd]
Build script for openJuice project
  -c, --clean                Clean only project source files (no building)
      -ca, --clean-all       Clean entire project, including dependencies (no
                               building)
  -g, --graph                Generate dependency graph
  -h, --help                 Show this help message and exit.
  -n, --new                  Cleans the build directory and rebuilds
                               everything, including dependencies (mandatory
                               for first build)
      -pd, --preserve-deps   Cleans the build directory and rebuilds everything
                               (excluding dependencies)
  -s, --sanitiser, --sanitizer=<sanitisers>
                             Enable sanitisers (address, undefined, thread,
                               memory, leak)
  -v, --verbose              Enable verbose output (lacks progress bar or other
                               graphical features)
  -V, --version              Print version information and exit.
```

### XMake
**Warning: currently not working. Please use CMake instead.**

`xmake project -k compile_commands` to generate `compile_commands.json` (if using Clang).

`xmake` to build. `xmake run` to run.

## Usage:
To be written.

## TODO:
* ~~Migrate to standard library modules (once released for GCC 15)~~
    - Currently using homemade standard library modules, no plans to revert to official standard library modules.
    - Once official standard library modules release, plans are to use them for homemade standard library modules to increase compilation speed.
* Resolve all `#warning` markers (none currently!)
* Complete design document
* Continue documentation (Doxygen)
* Implement online multiplayer functionality
* Implement a game AI

## Dependencies
This project uses the following external libraries:
- [Boost.Asio](https://github.com/boostorg/asio)
- [Boost.Regex](https://github.com/boostorg/regex)
- [FTXUI](https://github.com/ArthurSonzogni/FTXUI)
  - [grid-container-ftxui](https://github.com/mingsheng13/grid-container-ftxui)
  - [ip-input-ftxui](https://github.com/mingsheng13/ip-input-ftxui) (due to errors in the original implementation, currently using a forked version [here](https://github.com/mikomikotaishi/ip-input-ftxui))
- [SDL](https://github.com/libsdl-org/SDL)
- [SFML](https://github.com/SFML/SFML)
- [tomlplusplus](https://github.com/marzer/tomlplusplus)