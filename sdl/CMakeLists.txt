file(GLOB_RECURSE SDL_MODULES *.cppm)
add_library(sdl)
target_sources(sdl
    PUBLIC
    FILE_SET CXX_MODULES FILES
    ${SDL_MODULES})

configure_cpp_module_target(sdl)

## Ignore module circular dependencies, remove when CMake fixes this
set_target_properties(sdl PROPERTIES 
    CXX_STANDARD 23 
    CXX_EXTENSIONS OFF 
    CXX_MODULE_DYNDEP OFF
)