# openJuice

## Overview:
Open-source re-engineering of the game *100% Orange Juice!*.
This does not aim to be a one-to-one recreation of the game but rather a port of the game as a CLI program. Written using C++ modules.

Check out my [Rust rewrite](https://github.com/mikomikotaishi/openjuice-rs) (no active development until this is finished).

## Build:
`xmake project -k compile_commands` to generate `compile_commands.json` (if using Clang). 

`xmake` to build. `xmake run` to run.

## Usage:
To be written.

## TODO:
* Allow more build systems (i.e. CMake and GNU Make) to make the project
* Migrate to standard library modules (once released for GCC 15)
* Migrate the frontend from CLI printing to FTXUI
* Implement online multiplayer functionality
* Implement a game AI