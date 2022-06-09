#include <string>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Chessboard.h"
namespace py = pybind11;

std::string TestBinding(){
    return "Hello Binders!";
}

PYBIND11_MODULE(pyChessBoardDetector, module) {
    module.doc() = "pybind11 plugin for detecting corners in checkerboard using new OpenCV Algorithm.";

    module.def("test_bindings",&TestBinding,"Test Binding Function");
    module.def("get_chessboard_corners", &getChessBoardCorners, 
    "chessBoardCornersDetector", 
     py::arg("image_path"), py::arg("board_width"), py::arg("board_height"), py::arg("verbose") = false);
}
