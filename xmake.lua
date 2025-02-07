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
              "src/engine/entity/*.cppm", 
              "src/engine/game/*.cppm", 
              "src/engine/unit/*.cppm", 
              "src/engine/utility/*.cppm",
              "src/card/*.cppm", 
              "src/card/hyper/*.cppm", 
              "src/card/standard/*.cppm",
              "src/card/standard/base/*.cppm", 
              "src/unit/*.cppm", 
              "src/unit/bosses/*.cppm", 
              "src/unit/characters/*.cppm", 
              "src/unit/enemies/*.cppm"
    )
    set_policy("build.c++.modules", true)