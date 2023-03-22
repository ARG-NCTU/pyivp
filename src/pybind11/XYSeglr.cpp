#include "../lib_geometry/XYSeglr.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_XYSeglr(py::module &m) {
    
    py::class_<XYSeglr>(m, "XYSeglr")
    .def(py::init())
    .def(py::init<Seglr>())
    .def("set_seglr",&XYSeglr::setSeglr)
    .def("clear", &XYSeglr::clear)
    .def("set_raylen", &XYSeglr::setRayLen)
    .def("set_headsize", &XYSeglr::setHeadSize)
    .def("valid", &XYSeglr::valid)
    .def("size", &XYSeglr::size)
    .def("get_minx", &XYSeglr::getMinX)
    .def("get_maxx", &XYSeglr::getMaxX)
    .def("get_miny", &XYSeglr::getMinY)
    .def("get_maxy", &XYSeglr::getMaxY)
    .def("get_vx", &XYSeglr::getVX)
    .def("get_vy", &XYSeglr::getVY)
    .def("get_rayangle", &XYSeglr::getRayAngle)
    .def("get_raybasex", &XYSeglr::getRayBaseX)
    .def("get_raybasey", &XYSeglr::getRayBaseY)
    .def("get_avgx", &XYSeglr::getAvgX)
    .def("get_avgy", &XYSeglr::getAvgY)
    .def("get_raylen", &XYSeglr::getRayLen)
    .def("get_headsize", &XYSeglr::getHeadSize)
    .def("get_spec", &XYSeglr::get_spec);
}