#include <pybind11/pybind11.h>
#include "sbe/Header.h"
#include "sbe/ReferenceData.h"

namespace py = pybind11;

PYBIND11_MODULE(sbe, m) {
    m.doc() = "test using pybind11 for reference data"; // optional module docstring

    py::class_<sbe::Header>(m,"Header")
        .def("wrap",&sbe::Header::wrap)
        //.def("fragment",static_cast<std::uint8_t (sbe::Header::*)() const>(&sbe::Header::fragment)); // this works for c++<=14
        .def("fragment",py::overload_cast<>(&sbe::Header::fragment,py::const_));

    py::class_<sbe::ReferenceData>(m,"ReferenceData")
        .def("wrap",&sbe::ReferenceData::wrapForDecode);
}