cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

project(openJuice 
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_EXPORT_BUILD_DATABASE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)

add_executable(openJuice src/main.cpp)
target_link_libraries(openJuice PRIVATE board utility)