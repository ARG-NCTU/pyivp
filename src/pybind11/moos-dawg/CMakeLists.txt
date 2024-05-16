cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(PYTHON_LIBRARY_DIR "/usr/local/lib/python3.8/dist-packages")
set(PYTHON_EXECUTABLE "/usr/bin/python3")
set(PYBIND11_DIR "/home/moos-dawg/pyivp/src")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(pyivp)

INCLUDE_DIRECTORIES(
	../../lib_mbutil
	../../lib_geometr)

# INCLUDE_DIRECTORIES(/usr/include/opencv2)
#LINK_DIRECTORIES(/usr/local/lib)

#include_directories("${PYBIND11_DIR}/lib_geometry")
#include_directories("${PYBIND11_DIR}/lib_mbutils")

file (GLOB SOURCE_FILES "${PYBIND11_DIR}/lib_geometry/*.cpp")
file (GLOB SOURCE_FILES_MBUTIL "${PYBIND11_DIR}/lib_mbutil/*.cpp")
file (GLOB HEADER_FILES "${PYBIND11_DIR}/lib_geometry/*.h")
file (GLOB HEADER_FILES_MBUTIL "${PYBIND11_DIR}/lib_mbutil/*.h")
file (GLOB PYTHON_FILES "${PYBIND11_DIR}/pybind11/*.cpp")

find_package(pybind11 REQUIRED)

pybind11_add_module(pyivp 
  ${PYTHON_FILES}
  ${SOURCE_FILES}
  ${HEADER_FILES}
  ${SOURCE_FILES_MBUTIL}
  ${HEADER_FILES_MBUTIL}
)

target_link_libraries(pyivp PUBLIC opencv_core opencv_highgui)
# target_link_libraries(pyivp PRIVATE geometry mbutil task4)

install(TARGETS pyivp
  COMPONENT python
  LIBRARY DESTINATION "${PYTHON_LIBRARY_DIR}"
)
