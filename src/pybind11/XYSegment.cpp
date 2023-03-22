#include "../lib_geometry/XYSegment.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_XYSegment(py::module &m) {
    
    py::class_<XYSegment>(m, "XYSegment")
    .def(py::init())
    .def("set", py::overload_cast<double, double, double, double>(&XYSegment::set))
    .def("set", py::overload_cast<const XYPoint&, const XYPoint>(&XYSegment::set))
    .def("clear", &XYSegment::clear)
    .def("shift_horz", &XYSegment::shift_horz, py::arg("val"))
    .def("shift_vert", &XYSegment::shift_vert, py::arg("v"))
    .def("reverse", &XYSegment::reverse)
    .def("length", &XYSegment::length)
    .def("get_x1", &XYSegment::get_x1)
    .def("get_x2", &XYSegment::get_x2)
    .def("get_y1", &XYSegment::get_y1)
    .def("get_y2", &XYSegment::get_y2)
    .def("get_rang12", &XYSegment::getRAng12)
    .def("get_rang21", &XYSegment::getRAng21)
    .def("get_spec", &XYSegment::get_spec, py::arg("vertex_precision") = 1);
}