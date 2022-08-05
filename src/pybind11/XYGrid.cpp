#include "../lib_geometry/XYGrid.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>


namespace py = pybind11;

void init_XYGrid(py::module &m) {
    
    py::class_<XYGrid>(m, "XYGrid")
    .def(py::init())

    .def("getElement", &XYGrid::getElement, py::arg("ix"),"get square element generated by initial\n\nInput:\n    index(type:int)\n\nReturn:\n    square info(type:XYSquare)")
    .def("setVal", &XYGrid::setVal, py::arg("ix"), py::arg("val"),"setVal\nset value of specific index, if out of range compare with maximum or minimum value\n\nInput:\n    index(type:int)\n    val(type:double)\n\nReturn:\n    none")
    .def("getVal", &XYGrid::getVal, py::arg("ix"), "get value of specific index, if out of range return 0\n\nInput:\n    index(type:int)\n\nReturn:\n    value(type:double)")

    .def("getSBound", &XYGrid::getSBound, "get the bounding box(square) of input poly\n\nInput:\n    none\n\nReturn:\n    bounding_square(type:XYsquare)")
    .def("getPBound", &XYGrid::getPBound, "get polygon bounding box of your input poly \nInput:\n    none\n\nReturn:\n    bounding_poly(type:XYPolygon)")
    .def("getMinVal", &XYGrid::getMinVal)
    .def("getMaxVal", &XYGrid::getMaxVal)
    .def("size", &XYGrid::size, "get Element size(store how many square)\n\nInput:\n    None\n\nReturn:\n    Element list size(type:int)")

    .def("setUtil", &XYGrid::setUtil, py::arg("ix"), py::arg("val"),"set Util of specific index, if out of range compare with maximum or minimum Util\n\nInput:\n    index(type:int)\n    val(type:double)\n\nReturn:\n    none")
    .def("setUtilRange", &XYGrid::setUtilRange, py::arg("lval"), py::arg("hval"), "set Util maximum & minimum, If utilities have been set prior, they are examined and adjusted (clipped) if they are outside the range.\n\nInput:\n    lval(type:double)\n    hval(type:double)\n\nReturn:\n    none")
    .def("getUtil", &XYGrid::getUtil, py::arg("ix"))

    .def("getMinUtil", &XYGrid::getMinUtil)
    .def("getMaxUtil", &XYGrid::getMaxUtil)
    .def("getMaxUtilPoss", &XYGrid::getMaxUtilPoss,"get hval of setUtilRange(defult:1)\n\nInput:\n    none\n\nReturn:\n    max_util_possible(type:double)")
    .def("getMinUtilPoss", &XYGrid::getMinUtilPoss, "get lval of setUtilRange(defult:0)\n\nInput:\n    none\n\nReturn:\n    min_util_possible(type:double)")

    .def("initialize", py::overload_cast<std::string>(&XYGrid::initialize), py::arg("given_config_str"), "generate sqaure blocks to surround points(which generate a polygon)\n\nInput:\n    defined string (type:str)\ndefined string example: \nx1,y1:x2,y2:x3,y3:label,polyname @ dx,dy\n(at least 3 points can't be hoizontial or vertical line)\n\nReturn:\n    input status(type:bool)")
    .def("handleSegment", &XYGrid::handleSegment, py::arg("x1"), py::arg("y1"), py::arg("x2"), py::arg("y2"), "calculate the intersection length of square in element and line (generate from 2point of input),then store in in val\n\nInput:\n    x1(type:double)\n    y1(type:double)\n    x2(type:double)\n    y2(type:double)\n\nReturn:\n    None")
    .def("resetFromMin", &XYGrid::resetFromMin, "minus all value by minimum value\n\nInput:\n    None\n\nReturn:\n    None")

    .def("ptIntersect", &XYGrid::ptIntersect, py::arg("x"), py::arg("y"),"Determine is a given point is contained within the grid, i.e., within any one element\n\nInput:\n    x(type:double)\n    y(type:double)\n\nReturn:\n    True/False(type:bool)")
    .def("ptIntersectBound", &XYGrid::ptIntersectBound, py::arg("x"), py::arg("y"),"Determine is a given point is contained within the bounding box of all grid squares, i.e., within any one element\n\nInput:\n    x(type:double)\n    y(type:double)\n\nReturn:\n    True/False(type:bool)" )
    .def("segIntersectBound", &XYGrid::segIntersectBound, py::arg("x1"), py::arg("y1"), py::arg("x2"), py::arg("y2"),"Determine is a given line segment(generated by 2 points input) intersects the bounding box of all grid squares.\n\nInput:\n    x1(type:double)\n    y1(type:double)\n    x2(type:double)\n    y2(type:double)\n\nReturn:\n    True/False(type:bool)")
    .def("processDelta", py::overload_cast<const std::string&>(&XYGrid::processDelta),"use a defined string to do setVal and setUtil\n\nInput:\n    definded string(type:str)\ninput example 'old label@ index, old_value , new_value, old_util, new_util'\n\nReturn:\n    input valid or not(type:bool)")
    
    
    .def("getConfigString", &XYGrid::getConfigString)
    .def("getLabel", &XYGrid::getLabel);
   
}