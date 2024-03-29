cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(PYTHON_LIBRARY_DIR "/usr/lib/python3/dist-packages")
set(PYTHON_EXECUTABLE "/usr/bin/python3")
# this may require a absolute path
set(PYBIND11_DIR "/home/arg/pyivp/examples/automobile_example")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

project(automobile)

include_directories("${CMAKE_SOURCE_DIR}/cpp/include/automobile_bits")
include_directories("${CMAKE_SOURCE_DIR}/python")

file (GLOB SOURCE_FILES "${PYBIND11_DIR}/cpp/src/*.cpp")
file (GLOB HEADER_FILES "${PYBIND11_DIR}/cpp/include/automobile_bits/*.hpp")
file (GLOB PYTHON_FILES "${PYBIND11_DIR}/pybind11/*.cpp")


find_package(pybind11 REQUIRED)

pybind11_add_module(automobile 
${SOURCE_FILES}
${HEADER_FILES}
${PYTHON_FILES}
)

target_link_libraries(automobile PUBLIC)

install(TARGETS automobile
  COMPONENT python
  LIBRARY DESTINATION "${PYTHON_LIBRARY_DIR}"
)
