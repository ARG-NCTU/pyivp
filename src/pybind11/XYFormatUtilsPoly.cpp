#include "../lib_geometry/XYFormatUtilsPoly.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_XYFormatUtilsPoly(py::module &m) {
    m.def("string2Poly", &string2Poly);
    m.def("stringStandard2Poly", &stringStandard2Poly);
    m.def("stringRadial2Poly", &stringRadial2Poly);
    
    // m.def("")
    // m.def()
    // m.def()
    // m.def()
    

}