/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SBE_STATISTICSTYPE_CXX_H_
#define _SBE_STATISTICSTYPE_CXX_H_

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

class StatisticsType
{
public:
    enum Value
    {
        Undefined = static_cast<std::uint8_t>(0),
        OpenPrice = static_cast<std::uint8_t>(1),
        SettlementPrice = static_cast<std::uint8_t>(2),
        ClosePrice = static_cast<std::uint8_t>(3),
        OpenInterest = static_cast<std::uint8_t>(4),
        PreOpenInterest = static_cast<std::uint8_t>(5),
        PreSettlementPrice = static_cast<std::uint8_t>(6),
        PreClosePrice = static_cast<std::uint8_t>(7),
        HighestTradedPrice = static_cast<std::uint8_t>(8),
        LowestTradedPrice = static_cast<std::uint8_t>(9),
        UpperLimitPrice = static_cast<std::uint8_t>(10),
        LowerLimitPrice = static_cast<std::uint8_t>(11),
        IndexValue = static_cast<std::uint8_t>(12),
        MarginRate = static_cast<std::uint8_t>(13),
        FundingRate = static_cast<std::uint8_t>(14),
        FundingRatePrediction = static_cast<std::uint8_t>(15),
        TradeVolume = static_cast<std::uint8_t>(16),
        NULL_VALUE = static_cast<std::uint8_t>(255)
    };

    static StatisticsType::Value get(const std::uint8_t value)
    {
        switch (value)
        {
            case static_cast<std::uint8_t>(0): return Undefined;
            case static_cast<std::uint8_t>(1): return OpenPrice;
            case static_cast<std::uint8_t>(2): return SettlementPrice;
            case static_cast<std::uint8_t>(3): return ClosePrice;
            case static_cast<std::uint8_t>(4): return OpenInterest;
            case static_cast<std::uint8_t>(5): return PreOpenInterest;
            case static_cast<std::uint8_t>(6): return PreSettlementPrice;
            case static_cast<std::uint8_t>(7): return PreClosePrice;
            case static_cast<std::uint8_t>(8): return HighestTradedPrice;
            case static_cast<std::uint8_t>(9): return LowestTradedPrice;
            case static_cast<std::uint8_t>(10): return UpperLimitPrice;
            case static_cast<std::uint8_t>(11): return LowerLimitPrice;
            case static_cast<std::uint8_t>(12): return IndexValue;
            case static_cast<std::uint8_t>(13): return MarginRate;
            case static_cast<std::uint8_t>(14): return FundingRate;
            case static_cast<std::uint8_t>(15): return FundingRatePrediction;
            case static_cast<std::uint8_t>(16): return TradeVolume;
            case static_cast<std::uint8_t>(255): return NULL_VALUE;
        }

        throw std::runtime_error("unknown value for enum StatisticsType [E103]");
    }

    static const char *c_str(const StatisticsType::Value value)
    {
        switch (value)
        {
            case Undefined: return "Undefined";
            case OpenPrice: return "OpenPrice";
            case SettlementPrice: return "SettlementPrice";
            case ClosePrice: return "ClosePrice";
            case OpenInterest: return "OpenInterest";
            case PreOpenInterest: return "PreOpenInterest";
            case PreSettlementPrice: return "PreSettlementPrice";
            case PreClosePrice: return "PreClosePrice";
            case HighestTradedPrice: return "HighestTradedPrice";
            case LowestTradedPrice: return "LowestTradedPrice";
            case UpperLimitPrice: return "UpperLimitPrice";
            case LowerLimitPrice: return "LowerLimitPrice";
            case IndexValue: return "IndexValue";
            case MarginRate: return "MarginRate";
            case FundingRate: return "FundingRate";
            case FundingRatePrediction: return "FundingRatePrediction";
            case TradeVolume: return "TradeVolume";
            case NULL_VALUE: return "NULL_VALUE";
        }

        throw std::runtime_error("unknown value for enum StatisticsType [E103]:");
    }

    template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits> & operator << (
        std::basic_ostream<CharT, Traits> &os, StatisticsType::Value m)
    {
        return os << StatisticsType::c_str(m);
    }
};

}

#endif
