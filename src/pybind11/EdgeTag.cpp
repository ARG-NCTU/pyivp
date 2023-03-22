#include "../lib_geometry/EdgeTag.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_EdgeTag(py::module &m) {

    py::class_<EdgeTag>(m, "EdgeTag")
    .def(py::init())
    .def(py::init<unsigned int, unsigned int, std::string>())
    .def("set_indices", &EdgeTag::setIndices, "if abs of two index must equal 1, then it can return true,else return false\nInput: index1,index2\nReturn: true if success")
    .def("set_tag", &EdgeTag::setTag, "it can modify the tag you set before\nInput: tag")
    .def("get_index1", &EdgeTag::getIndex1, "it will return the value of index1 you set above\nReturn: index1")
    .def("get_tag", &EdgeTag::getTag, "it will return the tag\nReturn: tag")
    .def("get_index2", &EdgeTag::getIndex2, "it will return the value of index2 you set above\nReturn: index2")
    .def("get_spec", &EdgeTag::getSpec, "it can return the result ")
    .def("set_on_spec", &EdgeTag::setOnSpec, "using setOnSpec can set the new value\nInput: 'Index1:Index2:tag'")
    .def("valid", &EdgeTag::valid, "if you don't obey the rule 'abs of two numbers must equal 1' , it will be set (0,0) and no tag, then the func will return false\nReturn: true if success")
    .def("matches", py::overload_cast<unsigned int, unsigned int>(&EdgeTag::matches, py::const_), "true if the given two indices match in either order false otherwise.\nInput: ix1, ix2\nReturn: true if match")
    .def("matches", py::overload_cast<unsigned int, unsigned int, std::string>(&EdgeTag::matches, py::const_), "true if the given two indices match in either order false otherwise.\nInput: ix1, ix2, tag\nReturn: true if match")
    .def("print", &EdgeTag::print, " we can use this tunction to see the result")   
    ;

}
