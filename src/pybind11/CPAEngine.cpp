#include "../lib_geometry/CPAEngine.h"

// #include <pybind11/stl.h>
#include <pybind11/pybind11.h>

namespace py = pybind11;




void init_CPAEngine(py::module &m) {
    
    py::class_<CPAEngine>(m, "CPAEngine")
    .def(py::init()
    , "CPAEngine(), no argument. Please use reset() to assign arguments.")
    .def(py::init<double, double, double, double, double, double>()
    , "CPAEngine(arg0, arg1, arg2, arg3, arg4, arg5): create a CPAEngine object, arguments below are necessary for cpa\nArgs: \n  arg0 <float>: cny, Given Contact Latitude Position \n  arg1 <float>: cnx, Given Contact Longitude Position \n  arg2 <float>: cnh, Given Contact Course (degrees: 0-359) \n  arg3 <float>: cnv, Given Contact Speed (Unit: knots per hour) \n  arg4 <float>: osy, Given Ownship Latitude Position \n  arg5 <float>: osx, Given Ownship Latitude Position")
    .def("reset", &CPAEngine::reset
    , "reset(arg0, arg1, arg2, arg3, arg4, arg5): assign arguments to a existed CPAEngine object, arguments below are necessary for cpa\nArgs: \n  arg0 <float>: cny, Given Contact Latitude Position \n  arg1 <float>: cnx, Given Contact Longitude Position \n  arg2 <float>: cnh, Given Contact Course (degrees: 0-359) \n  arg3 <float>: cnv, Given Contact Speed (Unit: knots per hour) \n  arg4 <float>: osy, Given Ownship Latitude Position \n  arg5 <float>: osx, Given Ownship Latitude Position")
    .def("initNonCache", &CPAEngine::initNonCache)
    .def("evalCPA", &CPAEngine::evalCPA
    , "evalCPA(arg0, arg1, arg2): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \n  arg2 <float>: ostol, Given Ownship Time-on-leg \nreturn: Closest-Point-of-Approach (CPA)")
    .def("evalTimeCPA", &CPAEngine::evalTimeCPA
    , "evalTimeCPA(arg0, arg1, arg2): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \n  arg2 <float>: ostol, Given Ownship Time-on-leg \nreturn: Time of Closest-Point-of-Approach (CPA)")
    .def("evalROC", &CPAEngine::evalROC
    , "evalROC(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: rate-of-closure for a given heading speed")
    .def("evalRangeRateOverRange", &CPAEngine::evalRangeRateOverRange)
    .def("crossesStern", &CPAEngine::crossesStern
    , "crossesStern(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour)\nreturn: Determine if for the given ownship course and speed whether it is on a path to cross the path of the contact on its stern")
    .def("crossesSternDist", &CPAEngine::crossesSternDist
    , "crossesSternDist(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it is on a path to cross the path of the contact on its stern. And if so, at what distance when it crosses?")
    .def("crossesSternDistBool", &CPAEngine::crossesSternDistBool)
    .def("crossesBow", &CPAEngine::crossesBow
    , "crossesBow(arg0, arg1): \nArgs: \n  arg0 <float>: osCRS, Given Ownship Coordinate Reference System (degrees: 0-359) \n  arg1 <float>: osSPD, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it is on a path to cross the path of the contact on its bow")
    .def("crossesBowDist", &CPAEngine::crossesBowDist
    , "crossesBowDist(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it is on a path to cross the path of the contact on its bow. And if so, at what distance when it crosses?")
    .def("crossesBowDistBool", &CPAEngine::crossesBowDistBool)
    .def("crossesBowOrStern", &CPAEngine::crossesBowOrStern
    , "crossesBowOrStern(arg0, arg1): \nArgs: \n  arg0 <float>: osCRS, Given Ownship Coordinate Reference System (degrees: 0-359) \n  arg1 <float>: osSPD, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it is on a path to cross the path of the contact on its stern or bow")
    .def("passesPort", &CPAEngine::passesPort
    , "passesPort(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it will pass the contact on the contact's port side. A pass means it will cross the contact's beam, the line perpendicular to the contact's bow-stern line")
    .def("passesPortDist", &CPAEngine::passesPortDist
    , "passesPortDist(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it is on a path to cross the path of the contact on its port. And if so, at what distance when it crosses?")
    .def("passesPortDistBool", &CPAEngine::passesPortDistBool)
    .def("passesStar", &CPAEngine::passesStar
    , "passesStar(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it will pass the contact on the contact's star side. A pass means it will cross the contact's beam, the line perpendicular to the contact's bow-stern line")
    .def("passesStarDist", &CPAEngine::passesStarDist
    , "passesStarDist(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it is on a path to cross the path of the contact on its star. And if so, at what distance when it crosses?")
    .def("passesStarDistBool", &CPAEngine::passesStarDistBool)
    .def("passesPortOrStar", &CPAEngine::passesPortOrStar
    , "passesPortOrStar(arg0, arg1): \nArgs: \n  arg0 <float>: osCRS, Given Ownship Coordinate Reference System  (degrees: 0-359) \n  arg1 <float>: osSPD, Given Ownship Speed (Unit: knots per hour) \nreturn: Determine if for the given ownship course and speed whether it will pass the contact")
    .def("turnsRight", &CPAEngine::turnsRight
    , "turnsRight(arg0, arg1): \nArgs: \n  arg0 <float>: present_heading, Given Ownship present heading (degrees: 0-359) \n  arg1 <float>: heading, Given Ownship desired heading (degrees: 0-359) \nDetermine if present ownship heading, whether or not the proposed heading represent a righthand turn (starboard)")
    .def("turnsLeft", &CPAEngine::turnsLeft
    , "turnsLeft(arg0, arg1): \nArgs: \n  arg0 <float>: present_heading, Given Ownship present heading (degrees: 0-359) \n  arg1 <float>: heading, Given Ownship desired heading (degrees: 0-359) \nDetermine if present ownship heading, whether or not the proposed heading represent a lefthand turn (port)")
    .def("minMaxROC", &CPAEngine::minMaxROC)
    .def("bearingRate", &CPAEngine::bearingRate
    , "bearingRate(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate the bearing rate from the speed at tangent, where range is the current range between vehicles")
    .def("bearingRateOld", &CPAEngine::bearingRateOld
    , "bearingRateOld(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate the bearing rate from the speed at tangent, where range is the current range between vehicles")
    .def("ownshipContactRelBearing", &CPAEngine::ownshipContactRelBearing
    , "ownshipContactRelBearing(arg0): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \nreturn: Calculate the contact angle related to bearing")
    .def("getOSSpeedInCNHeading", &CPAEngine::getOSSpeedInCNHeading
    , "getOSSpeedInCNHeading(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate Ownship's speed from contact heading")
    .def("getOSSpeedGamma", &CPAEngine::getOSSpeedGamma
    , "getOSSpeedGamma(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate Ownship's speed in direction perpendicular to contact")
    .def("getOSSpeedEpsilon", &CPAEngine::getOSSpeedEpsilon
    , "getOSSpeedEpsilon(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate Ownship's speed in direction of the contact beam")
    .def("getOSTimeGamma", &CPAEngine::getOSTimeGamma
    , "getOSTimeGamma(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate Ownship's time gamma.")
    .def("getOSTimeEpsilon", &CPAEngine::getOSTimeEpsilon
    , "getOSTimeEpsilon(arg0, arg1): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate Ownship's time epsilon")
    .def("getARange", &CPAEngine::getARange
    , "getARange(arg0, arg1, arg2): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \n  arg2 <float>: time, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate the range at a particular time in the future, not necessarily the time at min CPA")
    .def("getARangeRate", &CPAEngine::getARangeRate
    , "getARangeRate(arg0, arg1, arg2): \nArgs: \n  arg0 <float>: osh, Given Ownship Course (degrees: 0-359) \n  arg1 <float>: osv, Given Ownship Speed (Unit: knots per hour) \n  arg2 <float>: time, Given Ownship Speed (Unit: knots per hour) \nreturn: Calculate the range rate at a particular time in the future, not necessarily the time at min CPA");
}