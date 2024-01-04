/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SBE_DECIMALS_CXX_H_
#define _SBE_DECIMALS_CXX_H_

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

class Decimals
{
public:
    enum Value
    {
        Undefined = static_cast<std::uint8_t>(0),
        _0 = static_cast<std::uint8_t>(1),
        _1 = static_cast<std::uint8_t>(2),
        _2 = static_cast<std::uint8_t>(3),
        _3 = static_cast<std::uint8_t>(4),
        _4 = static_cast<std::uint8_t>(5),
        _5 = static_cast<std::uint8_t>(6),
        _6 = static_cast<std::uint8_t>(7),
        _7 = static_cast<std::uint8_t>(8),
        _8 = static_cast<std::uint8_t>(9),
        _9 = static_cast<std::uint8_t>(10),
        _10 = static_cast<std::uint8_t>(11),
        _11 = static_cast<std::uint8_t>(12),
        _12 = static_cast<std::uint8_t>(13),
        _13 = static_cast<std::uint8_t>(14),
        _14 = static_cast<std::uint8_t>(15),
        _15 = static_cast<std::uint8_t>(16),
        NULL_VALUE = static_cast<std::uint8_t>(255)
    };

    static Decimals::Value get(const std::uint8_t value)
    {
        switch (value)
        {
            case static_cast<std::uint8_t>(0): return Undefined;
            case static_cast<std::uint8_t>(1): return _0;
            case static_cast<std::uint8_t>(2): return _1;
            case static_cast<std::uint8_t>(3): return _2;
            case static_cast<std::uint8_t>(4): return _3;
            case static_cast<std::uint8_t>(5): return _4;
            case static_cast<std::uint8_t>(6): return _5;
            case static_cast<std::uint8_t>(7): return _6;
            case static_cast<std::uint8_t>(8): return _7;
            case static_cast<std::uint8_t>(9): return _8;
            case static_cast<std::uint8_t>(10): return _9;
            case static_cast<std::uint8_t>(11): return _10;
            case static_cast<std::uint8_t>(12): return _11;
            case static_cast<std::uint8_t>(13): return _12;
            case static_cast<std::uint8_t>(14): return _13;
            case static_cast<std::uint8_t>(15): return _14;
            case static_cast<std::uint8_t>(16): return _15;
            case static_cast<std::uint8_t>(255): return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum Decimals [E103]");
    }

    static const char *c_str(const Decimals::Value value)
    {
        switch (value)
        {
            case Undefined: return "Undefined";
            case _0: return "_0";
            case _1: return "_1";
            case _2: return "_2";
            case _3: return "_3";
            case _4: return "_4";
            case _5: return "_5";
            case _6: return "_6";
            case _7: return "_7";
            case _8: return "_8";
            case _9: return "_9";
            case _10: return "_10";
            case _11: return "_11";
            case _12: return "_12";
            case _13: return "_13";
            case _14: return "_14";
            case _15: return "_15";
            case NULL_VALUE: return "NULL_VALUE";
        }

        throw std::runtime_error("unknown value for enum Decimals [E103]:");
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> & operator << (
        std::basic_ostream<CharT, Traits> &os, Decimals::Value m)
    {
        return os << Decimals::c_str(m);
    }
};

}

#endif
