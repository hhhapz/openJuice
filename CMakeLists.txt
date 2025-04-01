cmake_minimum_required(VERSION 3.30)

# Forcing Clang temporarily on Unix systems, will probably change this later once module support improves
if (UNIX)
    set(CMAKE_C_COMPILER "/usr/bin/clang")
    set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
endif()

if(UNIX)
    set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
    set(CMAKE_SKIP_BUILD_RPATH FALSE)
    set(CMAKE_INSTALL_RPATH "$ORIGIN/../build/lib")
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
elseif(WIN32)
    add_custom_command(TARGET openJuice POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_BINARY_DIR}/lib"
        "${CMAKE_SOURCE_DIR}"
    COMMENT "Copying DLLs to project root directory")
endif()

# if(DEFINED ENV{VCPKG_ROOT})
#     set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
# endif()

project(openJuice 
    LANGUAGES CXX
    VERSION 0.0.1
)

set(CMAKE_CXX_MODULE_BMI_DIRECTORY "${CMAKE_BINARY_DIR}/.gens/openJuice/linux/x86_64/release/rules/bmi/cache/modules/4bddce1b")

function(configure_cpp_module_target target)
    set_target_properties(${target} PROPERTIES 
        CXX_STANDARD 23 
        CXX_EXTENSIONS OFF 
        CXX_MODULE_DYNDEP OFF
        CXX_MODULE_BMI_DIRECTORY "${CMAKE_CXX_MODULE_BMI_DIRECTORY}"
    )
endfunction()

option(ENABLE_SANITIZERS "Enable sanitisers in debug builds" OFF)
option(USE_SANITIZER_ADDRESS "Enable address sanitiser" OFF)
option(USE_SANITIZER_KERNEL "Enable kernel address sanitiser" OFF)
option(USE_SANITIZER_HW "Enable hardware address sanitiser" OFF)
option(USE_SANITIZER_UNDEFINED "Enable undefined behaviour sanitiser" OFF)
option(USE_SANITIZER_THREAD "Enable thread sanitiser" OFF)
option(USE_SANITIZER_MEMORY "Enable memory sanitiser" OFF)
option(USE_SANITIZER_LEAK "Enable leak sanitiser" OFF)

function(add_sanitisers target)
    if(NOT ENABLE_SANITIZERS)
        return()
    endif()

    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
        set(SANITIZER_FLAGS "")
        
        if(USE_SANITIZER_ADDRESS)
            list(APPEND SANITIZER_FLAGS "-fsanitize=address")
        endif()

        if(USE_SANITIZER_KERNEL)
            list(APPEND SANITIZER_FLAGS "-fsanitize=kernel-address")
        endif()

        if(USE_SANITIZER_HW)
            list(APPEND SANITIZER_FLAGS "-fsanitize=hwaddress")
        endif()

        if(USE_SANITIZER_UNDEFINED)
            list(APPEND SANITIZER_FLAGS "-fsanitize=undefined")
        endif()

        if(USE_SANITIZER_THREAD)
            list(APPEND SANITIZER_FLAGS "-fsanitize=thread")
        endif()

        if(USE_SANITIZER_MEMORY)
            list(APPEND SANITIZER_FLAGS "-fsanitize=memory")
        endif()
        
        if(USE_SANITIZER_LEAK)
            list(APPEND SANITIZER_FLAGS "-fsanitize=leak")
        endif()
        
        if(SANITIZER_FLAGS)
            target_compile_options(${target} PRIVATE ${SANITIZER_FLAGS})
            target_link_options(${target} PRIVATE ${SANITIZER_FLAGS})
        endif()
    endif()
endfunction()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_definitions(NDEBUG)
    
    if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
        add_compile_options(-O3)
    elseif(MSVC)
        add_compile_options(/O2)
    endif()
    
    set(ENABLE_SANITIZERS OFF)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# dependencies
# if(DEFINED ENV{VCPKG_ROOT})
#     find_package(Boost 1.87.0 REQUIRED
#         COMPONENTS
#             asio regex
#         )
#     find_package(ftxui CONFIG REQUIRED)
#     find_package(SDL3 CONFIG REQUIRED)
#     find_package(tomlplusplus CONFIG REQUIRED)
# endif()

set(BOOST_INCLUDE_LIBRARIES asio regex)
set(BOOST_ENABLE_CMAKE ON)
FetchContent_Declare(
    Boost
    URL https://github.com/boostorg/boost/releases/download/boost-1.87.0/boost-1.87.0-cmake.7z
    USES_TERMINAL_DOWNLOAD TRUE
    DOWNLOAD_NO_EXTRACT FALSE
)
FetchContent_Declare(
    ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
    GIT_TAG main
)
FetchContent_Declare(ftxui-grid-container
    GIT_REPOSITORY https://github.com/mingsheng13/grid-container-ftxui
    GIT_TAG master
)
# Use forked version for now
FetchContent_Declare(ftxui-ip-input
    GIT_REPOSITORY https://github.com/mingsheng13/ip-input-ftxui
    GIT_TAG main
)
FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG origin/main
    OVERRIDE_FIND_PACKAGE
)
FetchContent_Declare(
    SDL3_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG origin/main
    OVERRIDE_FIND_PACKAGE
)
FetchContent_Declare(
    SDL3_ttf
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf.git
    GIT_TAG origin/main
    OVERRIDE_FIND_PACKAGE
)
FetchContent_Declare(
    SDL3_mixer
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_mixer.git
    GIT_TAG origin/main
    OVERRIDE_FIND_PACKAGE
)
FetchContent_Declare(
    SDL3_net
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_net.git
    GIT_TAG origin/main
    OVERRIDE_FIND_PACKAGE
)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        3.0.0
)
FetchContent_Declare(
    tomlplusplus
    GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
    GIT_TAG        master
)

FetchContent_MakeAvailable(
    Boost 
    ftxui
    ftxui-grid-container
    ftxui-ip-input 
    SDL3 
    SDL3_image 
    SDL3_mixer 
    SDL3_net 
    SDL3_ttf 
    SFML 
    tomlplusplus
)

add_subdirectory(stdlib)
add_subdirectory(ftxui)
add_subdirectory(sdl)
add_subdirectory(sfml)
add_subdirectory(tomlpp)

add_subdirectory(src)

target_link_libraries(openJuice PRIVATE 
    modules
    ftxui_modules
    SDL3::SDL3
    SDL3_image::SDL3_image
    SDL3_ttf::SDL3_ttf
    SDL3_mixer::SDL3_mixer
    SDL3_net::SDL3_net
    sfml
)
target_include_directories(openJuice PRIVATE 
    ${SFML_INCLUDE_DIRECTORIES}
    ${tomlplusplus_INCLUDE_DIRS} 
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
