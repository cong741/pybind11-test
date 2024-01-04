# CMakeLists.txt
cmake_minimum_required(VERSION 3.27)
project(example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

find_package(pybind11)
pybind11_add_module(example example.cpp)