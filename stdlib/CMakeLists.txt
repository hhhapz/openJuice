file(GLOB_RECURSE STDLIB_MODULES *.cppm)
add_library(stdlib)
target_sources(stdlib
    PUBLIC
    FILE_SET CXX_MODULES FILES
    ${STDLIB_MODULES})

configure_cpp_module_target(stdlib)

## Ignore module circular dependencies, remove when CMake fixes this
set_target_properties(stdlib PROPERTIES 
    CXX_STANDARD 23 
    CXX_EXTENSIONS OFF 
    CXX_MODULE_DYNDEP OFF
)