#include <pybind11/pybind11.h>
#include <sbe/Header.h>
#include <sbe/ReferenceData.h>

namespace py = pybind11;

PYBIND11_MODULE(example, m) {
    m.doc() = "test using pybind11 for reference data"; // optional module docstring

    py::class_<sbe::Header>(m,"Header")
        .def("wrap",&sbe::Header::wrap);

    py::class_<sbe::ReferenceData>(m,"ReferenceData")
        .def("wrap",&sbe::ReferenceData::wrapForDecode);
}