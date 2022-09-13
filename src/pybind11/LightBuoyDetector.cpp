#include "../ptask4_ScanTheCode/LightBuoyDetector.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_LightBuoyDetector(py::module &m) {

    py::class_<LightBuoyDetector>(m, "LightBuoyDetector")
    .def(py::init<>())
    .def("reset", &LightBuoyDetector::reset)
    .def("detectColorSequence", &LightBuoyDetector::detectColorSequence)
    .def("set_show_windows", &LightBuoyDetector::set_show_windows)
    .def("set_blob_size", &LightBuoyDetector::set_blob_size)
    ;
}