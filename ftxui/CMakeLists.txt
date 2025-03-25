file(GLOB_RECURSE FTXUI_MODULES *.cppm)

add_library(ftxui_modules)
target_sources(ftxui_modules
    PUBLIC
    FILE_SET CXX_MODULES FILES
    ${FTXUI_MODULES})

configure_cpp_module_target(ftxui_modules)

target_link_libraries(ftxui_modules
    PUBLIC
    ftxui::screen
    ftxui::dom
    ftxui::component
)

target_include_directories(ftxui_modules
    PRIVATE
    ${ftxui_SOURCE_DIR}/include
)

## Ignore module circular dependencies, remove when CMake fixes this
set_target_properties(ftxui_modules PROPERTIES 
    CXX_STANDARD 23 
    CXX_EXTENSIONS OFF 
    CXX_MODULE_DYNDEP OFF
)