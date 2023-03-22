#include "../lib_geometry/EdgeTagSet.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_EdgeTagSet(py::module &m) {

    py::class_<EdgeTagSet>(m, "EdgeTagSet")
    .def(py::init())
    .def("add_edge_tag", &EdgeTagSet::addEdgeTag, "add vertex using EdgeTag\nInput: EdgeTag\nReturn: true if success else return false")
    .def("set_on_spec", &EdgeTagSet::setOnSpec, "using setOnSpec can set the new value\nInput:'index1_1:index1_2:tag1#index2_1:index2_2:tag2'\nReturn: if all new tags are ok ,it will return false")
    .def("size", &EdgeTagSet::size, "return the size of the EdgeTagSet\nReturn: size of EdgeTagSet")
    .def("get_spec", &EdgeTagSet::getSpec, "it can return the result ")
    .def("matches", &EdgeTagSet::matches, "find whether the given value exist or not\nInput: the value you want to find\nReturn: true if it exist")
    .def("print", &EdgeTagSet::print, "we can use this tunction to see the result")   
    ;

}
