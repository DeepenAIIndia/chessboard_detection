cmake_minimum_required(VERSION 3.4...3.18)
project(chessboard)

find_package(OpenCV REQUIRED)
message(STATUS "OpenCV version: ${OpenCV_VERSION}")

include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/src
)

add_library(${PROJECT_NAME} SHARED
    src/Chessboard.cpp
    src/Chessboard.h
    src/ChessboardCorner.h
    src/ChessboardQuad.h
    src/Spline.h
    src/chessBoardCornersDetector.cpp
)
add_subdirectory(pybind11)
pybind11_add_module(chessBoardCornersDetector_pybind src/chessBoardCornersDetector_pybind.cpp)

add_executable(test_chessboard src/test_chessboard.cpp)
add_executable(chessBoardCornersDetector src/chessBoardCornersDetector.cpp)
target_link_libraries(test_chessboard ${PROJECT_NAME})
target_link_libraries(test_chessboard ${OpenCV_LIBS})
target_link_libraries(chessBoardCornersDetector ${PROJECT_NAME})
target_link_libraries(chessBoardCornersDetector ${OpenCV_LIBS})
target_link_libraries(chessBoardCornersDetector_pybind PUBLIC ${PROJECT_NAME})
target_compile_definitions(chessBoardCornersDetector_pybind PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})