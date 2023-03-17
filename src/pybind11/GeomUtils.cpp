#include "../lib_geometry/GeomUtils.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_GeomUtils(py::module &m) {
    m.def("distPointToPoint", &distPointToPoint);
    m.def("distPointToPoint1", &distPointToPoint1);
    m.def("distToPoint", &distToPoint );
    // m.def("distPointToSeg", &distPointToSeg<double, double, double, double, double, double>);
    // m.def("distPointToSeg", &distPointToSeg<double, double, double, double, double, double, double, double>);
    m.def("distToSegment", &distToSegment);
    // m.def("distPointToSeg", &distPointToSeg<double, double, double, double, double, double, double>);
    m.def("distSegToSeg", &distSegToSeg);
    m.def("linesCross", &linesCross);
    m.def("segmentsCross", &segmentsCross);
    m.def("lineRayCross", &lineRayCross);
    m.def("lineSegCross", &lineSegCross);
    m.def("segmentAngle", &segmentAngle);
    m.def("perpSegIntPt", &perpSegIntPt);
    m.def("perpLineIntPt", &perpLineIntPt);
    m.def("addVectors", &addVectors);
    m.def("bearingMinMaxToPoly", &bearingMinMaxToPoly);
    m.def("distCircleToLine", &distCircleToLine);
    m.def("randPointInPoly", &randPointInPoly);
    m.def("crossRaySegl", &crossRaySegl);
    m.def("distPointToRay", &distPointToRay);
    m.def("segRayCPA", &segRayCPA);
    m.def("seglRayCPA", &seglRayCPA);
    m.def("segSeglDist", &segSeglDist);
    m.def("crossRaySeg", &crossRaySeg);
    m.def("lineCircleIntPts", &lineCircleIntPts);
    m.def("segCircleIntPts", &segCircleIntPts);
    m.def("distPointToLine", &distPointToLine);
    m.def("distPointToSegl", &distPointToSegl);
    m.def("polyRayCPA", &polyRayCPA);
    m.def("randPointOnPoly", &randPointOnPoly);
    m.def("polyWidth", &polyWidth);
    m.def("polyHeight", &polyHeight);
    m.def("shiftVertices", &shiftVertices);

}