#include "../lib_geometry/XYVector.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_XYVector(py::module &m) {
    
    py::class_<XYVector>(m, "XYVector")
    .def(py::init())
    .def(py::init<double, double, double, double>())
    .def("set_position", &XYVector::setPosition)
    .def("set_vector_xy", &XYVector::setVectorXY)
    .def("set_vector_ma", &XYVector::setVectorMA)
    .def("merge_vector_xy", &XYVector::mergeVectorXY)
    .def("merge_vector_ma", &XYVector::mergeVectorMA)
    .def("aug_magnitude", &XYVector::augMagnitude)
    .def("aug_angle", &XYVector::augAngle)
    .def("clear", &XYVector::clear)
    .def("set_headsize", &XYVector::setHeadSize)
    .def("head_size_set", &XYVector::head_size_set)
    .def("apply_snap", &XYVector::applySnap)
    .def("shift_horz", &XYVector::shift_horz)
    .def("shift_vert", &XYVector::shift_vert)
    .def("xpos", &XYVector::xpos)
    .def("ypos", &XYVector::ypos)
    .def("mag", &XYVector::mag)
    .def("ang", &XYVector::ang)
    .def("xdot", &XYVector::xdot)
    .def("ydot", &XYVector::ydot)
    .def("valid", &XYVector::valid)
    .def("headsize", &XYVector::headsize)
    .def("get_spec", &XYVector::get_spec);
}