/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SBE_UPDATETYPE_CXX_H_
#define _SBE_UPDATETYPE_CXX_H_

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

class UpdateType
{
public:
    enum Value
    {
        Undefined = static_cast<std::uint8_t>(0),
        Snapshot = static_cast<std::uint8_t>(1),
        Incremental = static_cast<std::uint8_t>(2),
        Stale = static_cast<std::uint8_t>(3),
        NULL_VALUE = static_cast<std::uint8_t>(255)
    };

    static UpdateType::Value get(const std::uint8_t value)
    {
        switch (value)
        {
            case static_cast<std::uint8_t>(0): return Undefined;
            case static_cast<std::uint8_t>(1): return Snapshot;
            case static_cast<std::uint8_t>(2): return Incremental;
            case static_cast<std::uint8_t>(3): return Stale;
            case static_cast<std::uint8_t>(255): return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum UpdateType [E103]");
    }

    static const char *c_str(const UpdateType::Value value)
    {
        switch (value)
        {
            case Undefined: return "Undefined";
            case Snapshot: return "Snapshot";
            case Incremental: return "Incremental";
            case Stale: return "Stale";
            case NULL_VALUE: return "NULL_VALUE";
        }

        throw std::runtime_error("unknown value for enum UpdateType [E103]:");
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> & operator << (
        std::basic_ostream<CharT, Traits> &os, UpdateType::Value m)
    {
        return os << UpdateType::c_str(m);
    }
};

}

#endif
