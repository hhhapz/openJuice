set(GLOB BOARD_SOURCES
    "*.cppm"
)

add_library(board ${BOARD_SOURCES})
target_include_directories(board PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})