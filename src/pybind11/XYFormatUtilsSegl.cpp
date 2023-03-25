#include "../lib_geometry/XYFormatUtilsSegl.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_XYFormatUtilsSegl(py::module &m) {
    m.def("string_to_seglist", &string2SegList);
    
}