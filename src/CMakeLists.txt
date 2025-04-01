file(GLOB_RECURSE MODULES *.cppm)
add_library(modules)
target_sources(modules
    PUBLIC
    FILE_SET CXX_MODULES FILES
    ${MODULES}
)

configure_cpp_module_target(modules)

## Ignore module circular dependencies, remove when CMake fixes this
set_target_properties(modules PROPERTIES 
    CXX_STANDARD 23 
    CXX_EXTENSIONS OFF 
    CXX_MODULE_DYNDEP OFF
)

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(modules PRIVATE 
        -Wall -Wextra -Wpedantic
        -Wshadow -Wunused-parameter
        -Wconversion -Wsign-conversion 
    )
elseif(MSVC)
    target_compile_options(modules PRIVATE /W4)
endif()

target_link_libraries(modules PUBLIC 
    stdlib 
    sfml
    sdl
    tomlpp
    Boost::asio
    Boost::regex
    ftxui::component
    ftxui::dom
    ftxui::screen
    ftxui_modules
)

add_executable(openJuice Main.cpp)

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(openJuice PRIVATE 
        -Wall -Wextra -Wpedantic
        -Wshadow -Wconversion 
        -Wsign-conversion -Wunused-parameter
    )
elseif(MSVC)
    target_compile_options(openJuice PRIVATE /W4)
endif()

target_include_directories(modules PRIVATE ${tomlplusplus_INCLUDE_DIRS})

add_sanitisers(modules)
add_sanitisers(openJuice)

add_custom_command(TARGET openJuice POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy 
        $<TARGET_FILE:openJuice> 
        ${CMAKE_SOURCE_DIR}
    COMMENT "Copying executable to project root directory")