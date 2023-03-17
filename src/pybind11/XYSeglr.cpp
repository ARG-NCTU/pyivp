#include "../lib_geometry/XYSeglr.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_XYSeglr(py::module &m) {
    
    py::class_<XYSeglr>(m, "XYSeglr")
    .def(py::init())
    .def(py::init<Seglr>())
    .def("setSeglr",&XYSeglr::setSeglr)
    .def("clear", &XYSeglr::clear)
    .def("setRayLen", &XYSeglr::setRayLen)
    .def("setHeadSize", &XYSeglr::setHeadSize)
    .def("valid", &XYSeglr::valid)
    .def("size", &XYSeglr::size)
    .def("getMinX", &XYSeglr::getMinX)
    .def("getMaxX", &XYSeglr::getMaxX)
    .def("getMinY", &XYSeglr::getMinY)
    .def("getMaxY", &XYSeglr::getMaxY)
    .def("getVX", &XYSeglr::getVX)
    .def("getVY", &XYSeglr::getVY)
    .def("getRayAngle", &XYSeglr::getRayAngle)
    .def("getRayBaseX", &XYSeglr::getRayBaseX)
    .def("getRayBaseY", &XYSeglr::getRayBaseY)
    .def("getAvgX", &XYSeglr::getAvgX)
    .def("getAvgY", &XYSeglr::getAvgY)
    .def("getRayLen", &XYSeglr::getRayLen)
    .def("getHeadSize", &XYSeglr::getHeadSize)
    .def("get_spec", &XYSeglr::get_spec);
}