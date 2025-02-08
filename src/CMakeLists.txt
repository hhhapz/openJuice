file(GLOB_RECURSE MODULES *.cppm)
add_library(modules)
target_sources(modules
  PUBLIC
  FILE_SET CXX_MODULES FILES
  ${MODULES})

add_executable(openJuice Main.cpp)

target_link_libraries(openJuice PRIVATE modules ftxui::screen ftxui::dom ftxui::component)
target_include_directories(openJuice PRIVATE ${tomlplusplus_INCLUDE_DIRS})
