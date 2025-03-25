set_project("openJuice")
set_version("0.0.1")

add_rules("mode.release", "mode.debug")
set_languages("c++23")

-- Forcing Clang temporarily, will probably change this later
set_toolchains("llvm")

set_warnings("all")
-- set_warnings("all", "error")

if is_mode("debug") then 
    set_symbols("debug")
    set_optimize("none")
else 
    set_symbols("hidden")
    set_optimize("fastest")
    set_strip("all")
end

add_requires("boost[asio,regex] >= 1.87.0", { alias = "boost" })
add_requires("libsdl >= 3.2.4", { alias = "sdl" })
add_requires("ftxui[component,dom,screen] >= 5.0.0", { alias = "ftxui" })
add_requires("tomlplusplus >= 3.4.0", { alias = "tomlpp" })

set_policy("build.sanitizer.address", true)
set_policy("build.c++.modules", true)

target("openJuice")
set_kind("binary")
add_files(
    -- Standard library directories
    "stdlib/*.cppm",
    "stdlib/chrono/*.cppm",
    "stdlib/collections/*.cppm",
    "stdlib/concurrency/*.cppm",
    "stdlib/core/*.cppm",
    "stdlib/io/*.cppm",
    "stdlib/fmt/*.cppm",
    "stdlib/math/*.cppm",
    "stdlib/mem/*.cppm",
    "stdlib/net/*.cppm",
    "stdlib/os/*.cppm",
    "stdlib/os/unix/*.cppm",
    "stdlib/os/unix/arpa/*.cppm",
    "stdlib/os/unix/net/*.cppm",
    "stdlib/os/unix/netinet/*.cppm",
    "stdlib/os/unix/sys/*.cppm",
    "stdlib/os/unix/sys/platform/*.cppm",
    "stdlib/os/win32/*.cppm",
    "stdlib/ranges/*.cppm",
    "stdlib/str/*.cppm",
    "stdlib/sys/*.cppm",

    -- SDL directories
    "sdl/*.cppm",

    -- Source directories
    "src/Main.cpp",
    "src/card/*.cppm",
    "src/card/hyper/*.cppm",
    "src/card/standard/*.cppm",
    "src/card/standard/base/*.cppm",
    "src/chat/*.cppm",
    "src/engine/board/*.cppm",
    "src/engine/card/*.cppm",
    "src/engine/card/cardtypes/*.cppm",
    "src/engine/card/spawntypes/*.cppm",
    "src/engine/entity/*.cppm",
    "src/engine/game/*.cppm",
    "src/engine/game/ecs/*.cppm",
    "src/engine/observer/*.cppm",
    "src/engine/text/*.cppm",
    "src/engine/ui/*.cppm",
    "src/engine/ui/cli/*.cppm",
    "src/engine/ui/tui/*.cppm",
    "src/engine/unit/*.cppm",
    "src/engine/utility/*.cppm",
    "src/engine/utility/inputparser/*.cppm",
    "src/engine/utility/interfaces/*.cppm",
    "src/engine/utility/exceptions/*.cppm",
    "src/unit/*.cppm",
    "src/unit/bosses/*.cppm",
    "src/unit/characters/*.cppm",
    "src/unit/enemies/*.cppm"
)
add_packages("ftxui", "sdl", "tomlpp", { public = true })
add_packages("boost", { links = {"boost_regex", "boost_system"} })
