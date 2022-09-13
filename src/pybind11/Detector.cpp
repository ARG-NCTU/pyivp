#include "../ptask4_ScanTheCode/Detector.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_Detector(py::module &m) {

    py::class_<Detector>(m, "Detector")
    .def(py::init())
    .def("DetectColor", &Detector::DetectColor)
    ;
}