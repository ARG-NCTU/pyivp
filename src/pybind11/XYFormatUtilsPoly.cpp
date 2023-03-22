#include "../lib_geometry/XYFormatUtilsPoly.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_XYFormatUtilsPoly(py::module &m) {
    m.def("string2poly", &string2Poly);
    m.def("string_standard2poly", &stringStandard2Poly);
    m.def("string_radial2poly", &stringRadial2Poly);
}