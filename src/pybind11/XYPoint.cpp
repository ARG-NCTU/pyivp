#include "../lib_geometry/XYPoint.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_XYPoint(py::module &m) {
    
    py::class_<XYPoint>(m, "XYPoint")
    .def(py::init())
    .def(py::init<double, double>())
    .def("clear", &XYPoint::clear)
    .def("set_vertex", &XYPoint::set_vertex, py::arg("x"), py::arg("y"), py::arg("z")=0)
    .def("set_vx", &XYPoint::set_vx)
    .def("set_vy", &XYPoint::set_vy)
    .def("set_vz", &XYPoint::set_vz)
    .def("set_spec_digits", &XYPoint::set_spec_digits)
    .def("shift_x", &XYPoint::shift_x)
    .def("shift_y", &XYPoint::shift_y)
    .def("shift_z", &XYPoint::shift_z)
    .def("apply_snap", &XYPoint::apply_snap)
    .def("get_vx", &XYPoint::get_vx)
    .def("get_vy", &XYPoint::get_vy)
    .def("get_vz", &XYPoint::get_vz)
    .def("x", &XYPoint::x)
    .def("y", &XYPoint::y)
    .def("z", &XYPoint::z)
    .def("valid", &XYPoint::valid)
    .def("projectPt", &XYPoint::projectPt)
    .def("get_spec", &XYPoint::get_spec);
}