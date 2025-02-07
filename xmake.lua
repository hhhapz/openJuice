add_rules("mode.release", "mode.debug")
set_languages("c++23")

-- Forcing Clang temporarily, will probably change this later
set_toolchains("clang")
set_runtimes("libc++")

target("openJuice")
    set_kind("binary")
    add_files("src/Main.cpp", 
              "src/engine/board/*.cppm", 
              "src/engine/card/*.cppm", 
              "src/engine/card/types/*.cppm", 
              "src/engine/entities/*.cppm", 
              "src/engine/game/*.cppm", 
              "src/engine/utility/*.cppm",
              "src/card/*.cppm", 
              "src/card/cards/*.cppm", 
              "src/entities/*.cppm", 
              "src/entities/bosses/*.cppm", 
              "src/entities/characters/*.cppm", 
              "src/entities/enemies/*.cppm"
    )
    set_policy("build.c++.modules", true)