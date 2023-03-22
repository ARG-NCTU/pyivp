#include "../lib_geometry/XYPatternBlock.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_XYPatternBlock(py::module &m) {
    
    py::class_<XYPatternBlock>(m, "XYPatternBlock")
    .def(py::init())
    //Interface for setting parameters
    .def("set_param", py::overload_cast<std::string, std::string>(&XYPatternBlock::setParam), " you can set 5 parameters : block_width, block_length, swath_width, angle, id_point \n\n Input : string, string \n Returns : True if parameters is set correctly ")
    .def("set_param", py::overload_cast<std::string, double>(&XYPatternBlock::setParam)," you can set 4 parameters : block_width, block_length, swath_width, angle. \n\n Input : string, double \n Returns : True if parameters is set correctly ")
    .def("add_idpoint", &XYPatternBlock::addIDPoint,"Add a middle point of the block, the pblock may contain several id points, but at least one.\n\n Input : XYPoint ")
    .def("set_corewidth", &XYPatternBlock::setCoreWidth, py::arg("v")=true)
    .def("set_autodrop", &XYPatternBlock::setAutoDrop, py::arg("v")=true)

    //Interface for building components
    .def("build_composite_seglist", &XYPatternBlock::buildCompositeSegList, py::arg("osx"), py::arg("osy"))
    
    //Interface for getting information
    .def("distance_to_closestentry", &XYPatternBlock::distanceToClosestEntry, py::arg("osx"), py::arg("osy"), py::arg("any_segment")
        ,"By default, any_segment is set to true and the shortest distance is calculated by considering the endpoints of ANY of the lane segments. If any_segment is false, only the first,last (or outer) lane segments are considered.\n\nInputs : \nosx : x coordinate of the target.\nosy : y coordinate of the target.\n\nReturns : \n-1 (if there are any problems) or Distance to the shortest entry point.")
    .def("distance_to_crossaxis", &XYPatternBlock::distanceToCrossAxis, py::arg("osx"), py::arg("osy")
        ,"This function will calculate the distance between target and cross axis.\n\nInputs : \nosx : x coordinate of the target.\nosy : y coordinate of the target.\n\nReturns : \n-1 (if there are any problems) or Distance to the cross axis.")
    
    .def("get_lane_points", &XYPatternBlock::getLanePoints
        ,"Produce a set of points on either side of a center point (cptx, cpty) at angles perpendicular to the given angle. \n\n Returns : a set of points on either side of a center point ")
    .def("get_lane_segments", &XYPatternBlock::getLaneSegments
        ,"Produce a set of line segments of the given length (blocklen) at the given angle, each with the one of the given points (pts) as the center point. \n\n Returns : a set of line segments")
    .def("get_composite_seglist", &XYPatternBlock::getCompositeSegList
        ,"Produce a single XYSegList comprised of each of the given XYSegLists. Each given XYSegList should be a single line segment. Each line segment should be parallel and in order.")
    ;
}
