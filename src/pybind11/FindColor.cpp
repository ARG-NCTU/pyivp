#include "../ptask4_ScanTheCode/FindColor.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_FindColor(py::module &m) {

    py::class_<FindColor>(m, "FindColor")
    .def(py::init<cv::Scalar, cv::Scalar, std::string>())
    .def("set_show_windows", &FindColor::set_show_windows)
    .def("set_blob_size", &FindColor::set_blob_size)
    .def("reset_findcolor", &FindColor::reset)
    .def("isColor", &FindColor::isColor)
    .def("set_min", &FindColor::set_min)
    .def("set_max", &FindColor::set_max)
    .def("increment", &FindColor::increment)
    .def("decrement", &FindColor::decrement)
    ;
}