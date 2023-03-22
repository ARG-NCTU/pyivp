#include "../lib_geometry/CPAEngine.h"

// #include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;




void init_CPAEngine(py::module &m) {
    
    py::class_<CPAEngine>(m, "CPAEngine")
    .def(py::init()
    , "CPAEngine(), no argument. Please use reset() to assign arguments.")
    .def(py::init<double, double, double, double, double, double>()
    , "CPAEngine(arg0, arg1, arg2, arg3, arg4, arg5): create a CPAEngine object, arguments below are necessary for cpa\nArgs: \n  arg0 <float>: cny, Given Contact Latitude Position \n  arg1 <float>: cnx, Given Contact Longitude Position \n  arg2 <float>: cnh, Given Contact Course (degrees: 0-359) \n  arg3 <float>: cnv, Given Contact Speed (Unit: knots per hour) \n  arg4 <float>: osy, Given Ownship Latitude Position \n  arg5 <float>: osx, Given Ownship Longitude Position")
    .def("reset", &CPAEngine::reset
    , "reset(arg0, arg1, arg2, arg3, arg4, arg5): assign arguments to a existed CPAEngine object, arguments below are necessary for cpa\nArgs: \n  arg0 <float>: cny, Given Contact Latitude Position \n  arg1 <float>: cnx, Given Contact Longitude Position \n  arg2 <float>: cnh, Given Contact Course (degrees: 0-359) \n  arg3 <float>: cnv, Given Contact Speed (Unit: knots per hour) \n  arg4 <float>: osy, Given Ownship Latitude Position \n  arg5 <float>: osx, Given Ownship Longitude Position")
    .def("init_non_cache", &CPAEngine::initNonCache)
    .def("eval_CPA", &CPAEngine::evalCPA
    , "eval_CPA(arg0, arg1, arg2): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \n  arg2 <float>: ostol, Given Ownship Time-on-leg \nreturn: Closest-Point-of-Approach (CPA)")
    .def("eval_Time_CPA", &CPAEngine::evalTimeCPA
    , "eval_Time_CPA(arg0, arg1, arg2): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \n  arg2 <float>: ostol, Given Ownship Time-on-leg \nreturn: Time of Closest-Point-of-Approach (CPA)")
    .def("eval_ROC", &CPAEngine::evalROC
    , "eval_ROC(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: rate-of-closure for a given heading speed")
    .def("eval_range_rate_overrange", &CPAEngine::evalRangeRateOverRange)
    .def("crosses_stern", &CPAEngine::crossesStern
    , "crosses_stern(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour)\nreturn: Determine if for the given ownship course and speed whether it is on a path to cross the path of the contact on its stern")
    .def("crosses_sterndist", &CPAEngine::crossesSternDist
    , "crosses_sterndist(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it is on a path to cross the path of the contact on its stern. And if so, at what distance when it crosses?")
    .def("crosses_stern_dist_bool", &CPAEngine::crossesSternDistBool)
    .def("crosses_bow", &CPAEngine::crossesBow
    , "crosses_bow(arg0, arg1): \nArgs: \n  arg0 <float>: osCRS, Given Ownship Coordinate Reference System (degrees: 0-359) \n  arg1 <float>: osSPD, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it is on a path to cross the path of the contact on its bow")
    .def("crosses_bow_dist", &CPAEngine::crossesBowDist
    , "crosses_bow_dist(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it is on a path to cross the path of the contact on its bow. And if so, at what distance when it crosses?")
    .def("crosses_bow_dist_bool", &CPAEngine::crossesBowDistBool)
    .def("crosses_bow_or_stern", &CPAEngine::crossesBowOrStern
    , "crosses_bow_or_stern(arg0, arg1): \nArgs: \n  arg0 <float>: osCRS, Given Ownship Coordinate Reference System (degrees: 0-359) \n  arg1 <float>: osSPD, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it is on a path to cross the path of the contact on its stern or bow")
    .def("passes_port", &CPAEngine::passesPort
    , "passes_port(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it will pass the contact on the contact's port side. A pass means it will cross the contact's beam, the line perpendicular to the contact's bow-stern line")
    .def("passes_port_dist", &CPAEngine::passesPortDist
    , "passes_port_dist(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it is on a path to cross the path of the contact on its port. And if so, at what distance when it crosses?")
    .def("passes_port_dist_bool", &CPAEngine::passesPortDistBool)
    .def("passes_star", &CPAEngine::passesStar
    , "passes_star(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it will pass the contact on the contact's star side. A pass means it will cross the contact's beam, the line perpendicular to the contact's bow-stern line")
    .def("passes_star_dist", &CPAEngine::passesStarDist
    , "passes_star_dist(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it is on a path to cross the path of the contact on its star. And if so, at what distance when it crosses?")
    .def("passes_star_dist_bool", &CPAEngine::passesStarDistBool)
    .def("passes_port_or_star", &CPAEngine::passesPortOrStar
    , "passes_port_or_star(arg0, arg1): \nArgs: \n  arg0 <float>: osCRS, Given Ownship Coordinate Reference System  (degrees: 0-359) \n  arg1 <float>: osSPD, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it will pass the contact")
    .def("turns_right", &CPAEngine::turnsRight
    , "turns_right(arg0, arg1): \nArgs: \n  arg0 <float>: present_heading, Given Ownship present heading (degrees: 0-359) \n  arg1 <float>: heading, Given Ownship desired heading (degrees: 0-359) \nDetermine if present ownship heading, whether or not the proposed heading represent a righthand turn (starboard)")
    .def("turns_left", &CPAEngine::turnsLeft
    , "turns_left(arg0, arg1): \nArgs: \n  arg0 <float>: present_heading, Given Ownship present heading (degrees: 0-359) \n  arg1 <float>: heading, Given Ownship desired heading (degrees: 0-359) \nDetermine if present ownship heading, whether or not the proposed heading represent a lefthand turn (port)")
    .def("min_maxROC", &CPAEngine::minMaxROC)
    .def("bearing_rate", &CPAEngine::bearingRate
    , "bearing_rate(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate the bearing rate from the speed at tangent, where range is the current range between vehicles")
    .def("bearing_rate_old", &CPAEngine::bearingRateOld
    , "bearing_rate_old(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate the bearing rate from the speed at tangent, where range is the current range between vehicles")
    .def("ownship_contact_rel_bearing", &CPAEngine::ownshipContactRelBearing
    , "ownship_contact_rel_bearing(arg0): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \nreturn: Calculate the contact angle related to bearing")
    .def("get_OS_speed_in_CN_heading", &CPAEngine::getOSSpeedInCNHeading
    , "get_OS_speed_in_CN_heading(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate Ownship's speed from contact heading")
    .def("get_OS_speed_gamma", &CPAEngine::getOSSpeedGamma
    , "get_OS_speed_gamma(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate Ownship's speed in direction perpendicular to contact")
    .def("get_OS_speed_epsilon", &CPAEngine::getOSSpeedEpsilon
    , "get_OS_speed_epsilon(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate Ownship's speed in direction of the contact beam")
    .def("get_OS_time_gamma", &CPAEngine::getOSTimeGamma
    , "get_OS_time_gamma(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate Ownship's time gamma.")
    .def("get_OS_time_epsilon", &CPAEngine::getOSTimeEpsilon
    , "get_OS_time_epsilon(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate Ownship's time epsilon")
    .def("get_arange", &CPAEngine::getARange
    , "get_arange(arg0, arg1, arg2): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \n  arg2 <float>: time, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate the range at a particular time in the future, not necessarily the time at min CPA")
    .def("get_arange_rate", &CPAEngine::getARangeRate
    , "get_arange_rate(arg0, arg1, arg2): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \n  arg2 <float>: time, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate the range rate at a particular time in the future, not necessarily the time at min CPA");
}