add_rules("mode.release", "mode.debug")
set_languages("c++23")

set_toolchains("clang")
set_runtimes("libc++")

target("openJuice")
    set_kind("binary")
    add_files("src/main.cpp", 
              "src/board/*.cppm", 
              "src/game/*.cppm", 
              "src/utility/*.cppm"
    )
    set_policy("build.c++.modules", true)