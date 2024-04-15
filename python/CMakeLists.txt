cmake_minimum_required(VERSION 3.18...3.27)

project(pybind_example LANGUAGES CXX VERSION ${PROJECT_VERSION})

include(../cmake/CPM.cmake)
CPMAddPackage("gh:pybind/pybind11@2.12.0")  # Seamless operability between C++11 and Python                             https://github.com/pybind/pybind11

pybind11_add_module(_core src/main.cpp)

# This is passing in the version as a define just as an example
target_compile_definitions(_core PRIVATE VERSION_INFO=${PROJECT_VERSION})

# The install directory is the output (wheel) directory
install(TARGETS _core DESTINATION pybind_example)
