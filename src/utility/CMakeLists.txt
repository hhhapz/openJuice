set(GLOB UTILITY_SOURCES
    "*.cppm"
)

add_library(utility ${UTILITY_SOURCES})
target_include_directories(utility PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})