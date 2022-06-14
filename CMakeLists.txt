cmake_minimum_required(VERSION 3.4...3.18)
project(chessboard)

find_package(OpenCV REQUIRED)
message(STATUS "OpenCV version: ${OpenCV_VERSION}")

include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/src
)

add_library(chessboard_lib STATIC
    src/Chessboard.cpp
    src/Chessboard.h
    src/ChessboardCorner.h
    src/ChessboardQuad.h
    src/Spline.h
    src/chessBoardCornersDetector.cpp
    src/test_chessboard.cpp
)
set_target_properties(chessboard_lib PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_subdirectory(pybind11)
pybind11_add_module(pyChessBoardDetector src/chessBoardCornersDetector_pybind.cpp)

add_executable(test_chessboard src/test_chessboard.cpp)
target_link_libraries(test_chessboard chessboard_lib)
target_link_libraries(test_chessboard ${OpenCV_LIBS})
target_link_libraries(pyChessBoardDetector PRIVATE chessboard_lib)
target_link_libraries(pyChessBoardDetector PUBLIC ${OpenCV_LIBS})
# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(pyChessBoardDetector PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})
