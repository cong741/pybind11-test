# CMakeLists.txt
cmake_minimum_required(VERSION 3.27)
project(example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(pybind11)
#pybind11_add_module(example example.cpp)
pybind11_add_module(example sbe/ReferenceData.h)