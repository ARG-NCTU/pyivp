#include "../lib_geometry/GeomUtils.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_GeomUtils(py::module &m) {
    m.def("dist_point_to_point", &distPointToPoint);
    m.def("dist_point_to_point1", &distPointToPoint1);
    m.def("dist_to_point", &distToPoint );
    // m.def("distPointToSeg", &distPointToSeg<double, double, double, double, double, double>);
    // m.def("distPointToSeg", &distPointToSeg<double, double, double, double, double, double, double, double>);
    m.def("dist_to_segment", &distToSegment);
    // m.def("distPointToSeg", &distPointToSeg<double, double, double, double, double, double, double>);
    m.def("dist_seg_to_seg", &distSegToSeg);
    m.def("lines_cross", &linesCross);
    m.def("segments_cross", &segmentsCross);
    m.def("line_ray_cross", &lineRayCross);
    m.def("line_seg_cross", &lineSegCross);
    m.def("segment_angle", &segmentAngle);
    m.def("perp_seg_int_pt", &perpSegIntPt);
    m.def("perp_line_int_pt", &perpLineIntPt);
    m.def("add_vectors", &addVectors);
    m.def("bearing_min_max_to_poly", &bearingMinMaxToPoly);
    m.def("dist_circle_to_line", &distCircleToLine);
    m.def("rand_point_in_poly", &randPointInPoly);
    m.def("cross_ray_segl", &crossRaySegl);
    m.def("dist_point_to_ray", &distPointToRay);
    m.def("seg_ray_CPA", &segRayCPA);
    m.def("segl_ray_CPA", &seglRayCPA);
    m.def("seg_segl_dist", &segSeglDist);
    m.def("cross_ray_seg", &crossRaySeg);
    m.def("line_circle_int_pts", &lineCircleIntPts);
    m.def("seg_circle_int_pts", &segCircleIntPts);
    m.def("dist_point_to_line", &distPointToLine);
    m.def("dist_point_to_segl", &distPointToSegl);
    m.def("poly_ray_CPA", &polyRayCPA);
    m.def("rand_point_on_poly", &randPointOnPoly);
    m.def("poly_width", &polyWidth);
    m.def("poly_height", &polyHeight);
    m.def("shift_vertices", &shiftVertices);

}