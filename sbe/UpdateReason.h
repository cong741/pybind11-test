/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SBE_UPDATEREASON_CXX_H_
#define _SBE_UPDATEREASON_CXX_H_

#if !defined(__STDC_LIMIT_MACROS)
#  define __STDC_LIMIT_MACROS 1
#endif

#include <cstdint>
#include <iomanip>
#include <limits>
#include <ostream>
#include <stdexcept>
#include <sstream>
#include <string>

#define SBE_NULLVALUE_INT8 (std::numeric_limits<std::int8_t>::min)()
#define SBE_NULLVALUE_INT16 (std::numeric_limits<std::int16_t>::min)()
#define SBE_NULLVALUE_INT32 (std::numeric_limits<std::int32_t>::min)()
#define SBE_NULLVALUE_INT64 (std::numeric_limits<std::int64_t>::min)()
#define SBE_NULLVALUE_UINT8 (std::numeric_limits<std::uint8_t>::max)()
#define SBE_NULLVALUE_UINT16 (std::numeric_limits<std::uint16_t>::max)()
#define SBE_NULLVALUE_UINT32 (std::numeric_limits<std::uint32_t>::max)()
#define SBE_NULLVALUE_UINT64 (std::numeric_limits<std::uint64_t>::max)()

namespace sbe {

class UpdateReason
{
public:
    enum Value
    {
        Undefined = static_cast<std::uint8_t>(0),
        Created = static_cast<std::uint8_t>(1),
        Modified = static_cast<std::uint8_t>(2),
        Canceled = static_cast<std::uint8_t>(3),
        Filled = static_cast<std::uint8_t>(4),
        NULL_VALUE = static_cast<std::uint8_t>(255)
    };

    static UpdateReason::Value get(const std::uint8_t value)
    {
        switch (value)
        {
            case static_cast<std::uint8_t>(0): return Undefined;
            case static_cast<std::uint8_t>(1): return Created;
            case static_cast<std::uint8_t>(2): return Modified;
            case static_cast<std::uint8_t>(3): return Canceled;
            case static_cast<std::uint8_t>(4): return Filled;
            case static_cast<std::uint8_t>(255): return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum UpdateReason [E103]");
    }

    static const char *c_str(const UpdateReason::Value value)
    {
        switch (value)
        {
            case Undefined: return "Undefined";
            case Created: return "Created";
            case Modified: return "Modified";
            case Canceled: return "Canceled";
            case Filled: return "Filled";
            case NULL_VALUE: return "NULL_VALUE";
        }

        throw std::runtime_error("unknown value for enum UpdateReason [E103]:");
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> & operator << (
        std::basic_ostream<CharT, Traits> &os, UpdateReason::Value m)
    {
        return os << UpdateReason::c_str(m);
    }
};

}

#endif
