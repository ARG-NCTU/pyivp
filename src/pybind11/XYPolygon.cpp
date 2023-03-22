#include "../lib_geometry/XYPolygon.h"

#include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_XYPolygon(py::module &m)
{
  py::class_<XYPolygon>(m, "XYPolygon")
      .def(py::init())

      .def("add_vertex", py::overload_cast<double, double, bool>(&XYPolygon::add_vertex), py::arg("x"), py::arg("y"), py::arg("check_convexity") = true,
           R"(
      Add a vertex (x, y) into Polygon and check convexity.

      Inputs: 
        x: x coord of the given vertex.
        y: y coord of the given vertex.
        check_convexity: True for convex, False for concave.

      Returns:
        The convexity of the polygon. True for convex, False for concave.

      )")

      .def("add_vertex", py::overload_cast<double, double, double, bool>(&XYPolygon::add_vertex), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("check_convexity") = true,
           R"(
      Add a vertex (x, y, z) into Polygon and check convexity.

      Inputs: 
        x: x coord of the given vertex.
        y: y coord of the given vertex.
        z: z coord of the given vertex.
        check_convexity: True for convex, False for concave.

      Returns:
        The convexity of the polygon. True for convex, False for concave.
      
      )")

      .def("add_vertex", py::overload_cast<double, double, double, std::string, bool>(&XYPolygon::add_vertex), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("property"), py::arg("check_convexity") = true,
           R"(
      Add a vertex (x, y, z) into Polygon and check convexity.

      Inputs: 
        x: x coord of the given vertex.
        y: y coord of the given vertex.
        z: z coord of the given vertex.
        property: vertex property.
        check_convexity: True for convex, False for concave.

      Returns:
        The convexity of the polygon. True for convex, False for concave.
      
      )")

      .def("add_vertex_delta", &XYPolygon::add_vertex_delta, py::arg("x"), py::arg("y"), py::arg("delta"), py::arg("check_convexity") = true,
           R"(
      Add a vertex (x, y, z) into Polygon and check if a existing vertex is close to the new vertex by delta distance.

      Inputs: 
        x: x coord of the given vertex.
        y: y coord of the given vertex.
        delta: the delta distance.
        check_convexity: True for convex, False for concave.

      Returns:
        The convexity of the polygon. True for convex, False for concave.
      
      )")

      .def("alter_vertex", &XYPolygon::alter_vertex, py::arg("x"), py::arg("y"), py::arg("z"),
           R"(
      Replace the existing vertex that is closed to the given vertex (x, y, z) with that.

      Inputs: 
        x: x coord of the given vertex.
        y: y coord of the given vertex.
        z: z coord of the given vertex.

      Returns:
        The convexity of the polygon. True for convex, False for concave.

      )")

      .def("delete_vertex", py::overload_cast<double, double>(&XYPolygon::delete_vertex), py::arg("x"), py::arg("y"),
           R"(
      Delete the vertex that is closed to the given vertex (x, y).

      Inputs: 
        x: x coord of the given vertex.
        y: y coord of the given vertex.

      Returns:
        The convexity of the polygon. True for convex, False for concave.

      )")

      .def("delete_vertex", py::overload_cast<unsigned int>(&XYPolygon::delete_vertex), py::arg("ix"),
           R"(
      Delete the vertex by the given index ix.

      Inputs: 
        ix: The index of vertices that will be deleted.

      Returns:
        The convexity of the polygon. True for convex, False for concave.

      )")

      .def("grow_by_pct", &XYPolygon::grow_by_pct, py::arg("pct"),
           R"(
      Inflate or deflate the polygon by the given ratio pct with respect to the polygon centroid.

      Inputs:
        pct: The Growing ratio for inflating or deflating the polygon.

      Returns:
        None

      )")

      .def("grow_by_amt", &XYPolygon::grow_by_amt, py::arg("amt"),
           R"(
      Inflate or deflate the polygon by the given distance amt with respect to the polygon centroid.

      Inputs:
        amt: The Growing distance for inflating or deflating the polygon.

      Returns:
        None
      
      )")

      .def("insert_vertex", &XYPolygon::insert_vertex, py::arg("x"), py::arg("y"), py::arg("z"),
           R"(
      Find the segment closest to the given vertex (x, y, z) and insert it into the points of the segment.

      Inputs:
        x: x coord of the given vertex.
        y: y coord of the given vertex.
        z: z coord of the given vertex.

      Returns:
        The convexity of the polygon. True for convex, False for concave.
      
      )")

      .def("clear", &XYPolygon::clear,
           R"(
      Clear all vertices in the polygon.

      Inputs:
        None

      Returns:
        None      

      )")

      .def("apply_snap", &XYPolygon::apply_snap, py::arg("snapval"),
           R"(
      Snap all the vertices to the grid by snapval.

      Inputs:
        snapval: The grid size.

      Returns:
        The convexity of the polygon. True for convex, False for concave.
      
      )")

      .def("reverse", &XYPolygon::reverse,
           R"(
      Reverse the vertices order in the polygon.

      Inputs:
        None

      Returns:
        None
      
      )")

      .def("rotate", py::overload_cast<double, double, double>(&XYPolygon::rotate), py::arg("val"), py::arg("cx"), py::arg("cy"),
           R"(
      Rotate the polygon by angle val with the respect to the given center (cx, cy).

      Inputs:
        val: The rotating angle.
        cx: x coord of the given center.
        cy: y coord of the given center.

      Returns:
        None
      
      )")

      .def("rotate", py::overload_cast<double>(&XYPolygon::rotate), py::arg("val"),
           R"(
      Rotate the polygon by angle val with the respect to the polygon centroid.

      Inputs:
        val: The rotating angle.

      Returns:
        None
      
      )")

      .def("contains", py::overload_cast<double, double>(&XYPolygon::contains, py::const_), py::arg("x"), py::arg("y"),
           R"(
      Check if the polygon contains the given vertex (x, y).

      Inputs:
        x: x coord of the given vertex.
        y: y coord of the given vertex.

      Returns:
        True if the polygon contains the given vertex (x, y). False otherwise.
      
      )")

      .def("contains", py::overload_cast<const XYPolygon &>(&XYPolygon::contains, py::const_), py::arg("inner_poly"),
           R"(
      Check if the polygon contains the given inner polygon.

      Inputs:
        inner_poly: The inner polygon.

      Returns:
        True if the given polygon is convex and all its vertices are contained within this polygon. False otherwise.
      
      )")

      .def("intersects", py::overload_cast<const XYPolygon &>(&XYPolygon::intersects, py::const_), py::arg("poly"),
           R"(
      Check if the polygon intersects the given polygon.

      Inputs:
        poly: The given polygon.

      Returns:
        True if the polygon intersects the given polygon. False otherwise.
      
      )")

      .def("intersects", py::overload_cast<const XYSquare &>(&XYPolygon::intersects, py::const_), py::arg("square"),
           R"(
      Check if the polygon intersects the given square.

      Inputs:
        square: The given square.

      Returns:
        True if the polygon intersects the given square. False otherwise.
      
      )")

      .def("dist_to_poly", py::overload_cast<const XYPolygon &>(&XYPolygon::dist_to_poly, py::const_), py::arg("poly"),
           R"(
      Calculate the minimum distance of the polygon and the given polygon.

      Inputs:
        poly: The given poly.

      Returns:
        The minumum distance of the polygon and the given polygon.
      
      )")

      .def("dist_to_poly", py::overload_cast<double, double>(&XYPolygon::dist_to_poly, py::const_), py::arg("px"), py::arg("py"),
           R"(
      Calculate the minimum distance of the polygon and the given point (x, y).

      Inputs:
        x: x coord of the given point.
        y: y coord of the given point.

      Returns:
        The minumum distance of the polygon and the given point.
      
      )")

      .def("dist_to_poly", py::overload_cast<double, double, double, double>(&XYPolygon::dist_to_poly, py::const_), py::arg("x1"), py::arg("y1"), py::arg("x2"), py::arg("y2"),
           R"(
      Calculate the minimum distance of the polygon and the given segment ((x1, y1), (x2, y2)).

      Inputs:
        x1: x coord of the first point of the segment.
        y1: y coord of the first point of the segment.
        x2: x coord of the second point of the segment.
        y2: y coord of the second point of the segment.

      Returns:
        The minumum distance of the polygon and the given segment.
      
      )")

      .def("dist_to_poly", py::overload_cast<double, double, double>(&XYPolygon::dist_to_poly, py::const_), py::arg("px"), py::arg("py"), py::arg("angle"),
           R"(
      Calculate the minimum distance of the polygon and the given poing (x1, y1) along the given angle.

      Inputs:
        px: x coord of the given point.
        py: y coord of the given point.
        angle: The given angle.

      Returns:
        The minumum distance of the polygon and the given point along the given angle.
      
      )")

      .def("seg_intercepts", &XYPolygon::seg_intercepts, py::arg("x1"), py::arg("x2"), py::arg("y1"), py::arg("y2"),
           R"(
      Check if the given segment intercepts the polygon or within the polygon.

      Inputs:
        x1: x coord of the first point of the segment.
        y1: y coord of the first point of the segment.
        x2: x coord of the second point of the segment.
        y2: y coord of the second point of the segment.

      Returns:
        True if the given segment intercepts the polygon or the segment within the polygon. False otherwise.
      
      )")

      .def(
          "line_intersects", [](XYPolygon &self, double x1, double y1, double x2, double y2, double &ix1, double &iy1, double &ix2, double &iy2){
                              bool isIntercept = self.line_intersects(x1, y1, x2, y2, ix1, iy1, ix2, iy2);
                              return std::make_tuple(isIntercept, ix1, iy1, ix2, iy2); },
          py::arg("x1"), py::arg("y1"), py::arg("x2"), py::arg("y2"), py::arg("ix1"), py::arg("iy1"), py::arg("ix2"), py::arg("iy2"),
          R"(
      Check if the given segment intercepts the polygon and find the intersects.

      Inputs:
        x1: x coord of the first point of the segment.
        y1: y coord of the first point of the segment.
        x2: x coord of the second point of the segment.
        y2: y coord of the second point of the segment.
        ix1: x coord of the first point of the intersects.
        iy1: y coord of the first point of the intersects.
        ix2: x coord of the second point of the intersects.
        iy2: y coord of the second point of the intersects.

      Returns:
        [isIntercept, ix1, iy1, ix2, iy2]
        isIntercept: True if the given segment intercepts the polygon. False otherwise.
        ix1: x coord of the first point of the intersects.
        iy1: y coord of the first point of the intersects.
        ix2: x coord of the second point of the intersects.
        iy2: y coord of the second point of the intersects.
      
      )")

      .def("vertex_is_viewable", &XYPolygon::vertex_is_viewable, py::arg("ix"), py::arg("x1"), py::arg("y1"),
           R"(
      Determine if the line segment given by the vertex ix, and the point x1,y1, intersects the polygon *only* at the vertex. If so, we say that the vertex is "viewable" from the given point.

      Inputs:
        ix: The index of segment that will be considered.
        x1: x coord of the first point of the segment.
        y1: y coord of the first point of the segment.


      Returns:
        True if the vertex is viewable. False otherwise.
        We return false if the given point is contained in the polygon.
      )")

      .def("is_convex", &XYPolygon::is_convex,
           R"(
      Get the convexity of the polygon.

      Inputs:
        None

      Returns:
        The convexity of the polygon. True for convex, False for concave.
      )")

      .def("determine_convexity", &XYPolygon::determine_convexity,
           R"(
      Determine whether the object represents a convex polygon. We declare that a polygon is *not* convex unless it contains at least three points. 

      Inputs:
        None

      Returns:
        None
      )")

      .def("area", &XYPolygon::area,
           R"(
      Calculate the area of the polygon and return it.

      Inputs:
        None

      Returns:
        The area of the polygon.
      )")

      .def("simplify", &XYPolygon::simplify, py::arg("range_thresh"),
           R"(
      Search for the two closest vertices and if within the the given range, combine the two vertices into one.

      Inputs:
        range_thresh: The threshold range.

      Returns:
        True if there are at least a pair of vertices are close enough to each other. False otherwise.
      )")

      .def("max_radius", &XYPolygon::max_radius,
           R"(
      Determine the maximum distance between the center of the polygon and any of its vertices.

      Inputs:
        None

      Returns:
        The maximum radius.
      )")

      .def(
          "closest_point_on_poly", [](XYPolygon &self, double sx, double sy, double &rx, double &ry){
                                      bool convex = self.closest_point_on_poly(sx, sy, rx, ry); 
                                      return std::make_tuple(convex, rx, ry); },
          py::arg("sx"), py::arg("sy"), py::arg("rx"), py::arg("ry"),
          R"(
      Determine the point on the polygon (on an edge or vertex) closest to the given point.

      Inputs:
        sx: x coord of the given point.
        sy: y coord of the given point.
        rx: x coord of the closest point.
        ry: y coord of the closest point.

      Returns:
        [convex, rx, ry]
        convex: True if the polygon is convex. False otherwise.
        rx: x coord of the closest point.
        ry: y coord of the closest point.
      )")

      .def("export_seglist", &XYPolygon::exportSegList, py::arg("x") = 0, py::arg("y") = 0,
           R"(
      Build an XYSegList from the polygon. Make the first point in the XYSegList the point in the polygon that is closest to the x,y point.

      Inputs:
        x: x coord of the given point. Defaults to 0.
        y: y coord of the given point. Defaults to 0.

      Returns:
        The XYSegList built from the polygon.
      )")

      .def("cross_product_settle", &XYPolygon::crossProductSettle,
           R"(
      If this polygon is nonconvex, try to make it convex by repeatedly removing middle points of the three-point group that is most colinear in the polygon.

      Inputs:
        None

      Returns:
        The convex XYSegList.
      )")

      .def("min_xproduct", [](XYPolygon &self, bool& ok){
                              unsigned int i = self.min_xproduct(ok); 
                              return std::make_tuple(i, ok); }, py::arg("ok"),
           R"(
      Find the vertex with the minimum cross product formed by 
      (1) the preceding vertex, 
      (2) itself and 
      (3) the following vertex.

      Inputs:
        ok: True if vertices is more than three. False otherwise.

      Returns:
        [i, ok]
        i: The index of the vertex having the min cross product.
        ok: True if vertices is more than three. False otherwise.
      )");
}
