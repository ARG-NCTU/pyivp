#include "../lib_geometry/XYSegList.h"
#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
namespace py = pybind11;
void init_XYSegList(py::module &m) {
    py::class_<XYSegList>(m, "XYSegList")
    //XYSegList() {m_transparency=0.1;}
    .def(py::init())
    .def("add_vertex",py::overload_cast<const XYPoint&, std::string>(&XYSegList::add_vertex),"add vertex with a vertex")
    .def("add_vertex",py::overload_cast<double, double, double, std::string>(&XYSegList::add_vertex),"add vertex with x y")
    .def("mod_vertex",&XYSegList::mod_vertex,"mod the vertex")
    .def("alter_vertex",&XYSegList::alter_vertex,"find the closest existing vertex and replace it.")
    .def("delete_vertex",py::overload_cast<double, double>(&XYSegList::delete_vertex),"find the closest existing vertex and delete")
    .def("delete_vertex",py::overload_cast<unsigned int>(&XYSegList::delete_vertex),"given a valid vertex index and delete it")
    .def("insert_vertex",&XYSegList::insert_vertex,"find the closest existing segment and add the vertex between points")
    .def("set_edge_tags",&XYSegList::set_edge_tags,"set_edge_tags")
    .def("pop_last_vertex",&XYSegList::pop_last_vertex,"Remove the last vertex")
    .def("clear",&XYSegList::clear,"clear")
    .def("shift_horz",&XYSegList::shift_horz,py::arg("val"),"shift horizontal")
    .def("shift_vert",&XYSegList::shift_vert,py::arg("val"),"shift vertical")
    .def("grow_by_pct",&XYSegList::grow_by_pct,py::arg("pct"),"grow_by_pct")
    .def("grow_by_amt",&XYSegList::grow_by_pct,py::arg("amt"),"grow_by_amt")
    .def("apply_snap",&XYSegList::apply_snap,py::arg("snapval"),"apply_snap")
    .def("rotate",py::overload_cast<double>(&XYSegList::rotate),py::arg("degree"),"rotate")
    .def("rotate",py::overload_cast<double,double,double>(&XYSegList::rotate),py::arg("degrees"),py::arg("cx"),py::arg("cy"),"rotate")
    .def("reverse",&XYSegList::reverse,"reverse")
    .def("new_center",&XYSegList::new_center,py::arg("x"),py::arg("y"),"new_center")
    .def("new_centroid",&XYSegList::new_centroid,py::arg("x"),py::arg("y"),"new_centroid")
    .def("is_clockwise",&XYSegList::is_clockwise,"is_clockwise")
    .def("valid",&XYSegList::valid ,"valid")
    .def("size",&XYSegList::size,"size")
    .def("get_vx",&XYSegList::get_vx,"get_vx")
    .def("get_vy",&XYSegList::get_vy,"get_vy")
    .def("get_vz",&XYSegList::get_vz,"get_vz")
    .def("get_vprop",&XYSegList::get_vprop,"get_vprop")
    .def("get_center_x",&XYSegList::get_center_x,"Return the mid point between the extreme x low, high")
    .def("get_center_y",&XYSegList::get_center_y,"Return the mid point between the extreme y low, high")
    .def("get_centroid_x",&XYSegList::get_centroid_x,"Return the x center of mass of all points")
    .def("get_centroid_y",&XYSegList::get_centroid_y,"Return the y center of mass of all points")
    .def("get_min_x",&XYSegList::get_min_x,"Return the min of the x values")
    .def("get_max_x",&XYSegList::get_max_x,"Return the max of the x values")
    .def("get_min_y",&XYSegList::get_min_y,"Return the min of the y values")
    .def("get_max_y",&XYSegList::get_max_y,"Return the max of the y values")
    .def("get_avg_x",&XYSegList::get_avg_x,"Return the avg of the x values")
    .def("get_avg_y",&XYSegList::get_avg_y,"Return the avg of the y values")
    .def("dist_to_point",&XYSegList::dist_to_point,py::arg("x"),py::arg("y"),"Find the closest distance from the given point to any point on any segment.")
    .def("dist_to_ctr",&XYSegList::dist_to_ctr,py::arg("x"),py::arg("y"),"dist_to_ctr")
    .def("max_dist_to_ctr",&XYSegList::max_dist_to_ctr,"Return the maximum distance between the center and any one of the vertices in the SegList.")
    .def("segs_cross",&XYSegList::segs_cross,py::arg("loop")=true,"Determine if any two segments intersect one another We exclude from consideration any two segments that share a vertex. If the result is false, then this set of line segments should form a polygon, although not necessarily a convex polygon")
    .def("length",&XYSegList::length,"Determine the overall length between the first and the last point-distance in the X-Y Plane only")
    .def("get_spec",py::overload_cast<unsigned int>(&XYSegList::get_spec, py::const_),"get_spec")
    .def("get_spec",py::overload_cast<std::string>(&XYSegList::get_spec, py::const_),"get_spec")
    .def("get_spec",py::overload_cast<unsigned int,std::string>(&XYSegList::get_spec, py::const_),"Get a string specification of the seglist. We set  the vertex precision to be at the integer by default.")
    .def("get_spec_pts",&XYSegList::get_spec_pts,py::arg("vertex_prec")=1,"Get a string specification of the just the points. We set the vertex precision to be at the integer by default.")
    .def("get_spec_pts_label",&XYSegList::get_spec_pts_label,py::arg("vertex_prec")=1,"Get a string specification of just the points and label.")
    .def("get_spec_inactive",&XYSegList::get_spec_inactive, "In cases where we know the polygon spec is created simply to 'erase' a previous poly with the same label, just generate a concise spec with a trivial convext poly.")
    .def("closest_vertex",&XYSegList::closest_vertex,"closest_vertex")
    .def("closest_segment",&XYSegList::closest_segment,"closest_segment")
    .def("get_edge_tags",&XYSegList::get_edge_tags,"get_edge_tags")
    //EdgeTagSet get_edge_tags() const {return(m_edge_tags);}sss
    ;
}