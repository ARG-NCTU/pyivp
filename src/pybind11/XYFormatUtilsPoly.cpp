#include "../lib_geometry/XYFormatUtilsPoly.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_XYFormatUtilsPoly(py::module &m) {
    m.def("string_to_poly", &string2Poly);
    m.def("string_standard_to_poly", &stringStandard2Poly);
    m.def("string_radial_to_poly", &stringRadial2Poly);
}