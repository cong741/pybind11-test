/* Generated SBE (Simple Binary Encoding) message codec */
#ifndef _SBE_TRADESUMMARY_CXX_H_
#define _SBE_TRADESUMMARY_CXX_H_

#if __cplusplus >= 201103L
#  define SBE_CONSTEXPR constexpr
#  define SBE_NOEXCEPT noexcept
#else
#  define SBE_CONSTEXPR
#  define SBE_NOEXCEPT
#endif

#if __cplusplus >= 201703L
#  include <string_view>
#  define SBE_NODISCARD [[nodiscard]]
#else
#  define SBE_NODISCARD
#endif

#if !defined(__STDC_LIMIT_MACROS)
#  define __STDC_LIMIT_MACROS 1
#endif

#include <cstdint>
#include <limits>
#include <cstring>
#include <iomanip>
#include <ostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>

#if defined(WIN32) || defined(_WIN32)
#  define SBE_BIG_ENDIAN_ENCODE_16(v) _byteswap_ushort(v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) _byteswap_ulong(v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) _byteswap_uint64(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#  define SBE_BIG_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) (v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) (v)
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#  define SBE_LITTLE_ENDIAN_ENCODE_16(v) __builtin_bswap16(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_32(v) __builtin_bswap32(v)
#  define SBE_LITTLE_ENDIAN_ENCODE_64(v) __builtin_bswap64(v)
#  define SBE_BIG_ENDIAN_ENCODE_16(v) (v)
#  define SBE_BIG_ENDIAN_ENCODE_32(v) (v)
#  define SBE_BIG_ENDIAN_ENCODE_64(v) (v)
#else
#  error "Byte Ordering of platform not determined. Set __BYTE_ORDER__ manually before including this file."
#endif

#if !defined(SBE_BOUNDS_CHECK_EXPECT)
#  if defined(SBE_NO_BOUNDS_CHECK)
#    define SBE_BOUNDS_CHECK_EXPECT(exp, c) (false)
#  elif defined(_MSC_VER)
#    define SBE_BOUNDS_CHECK_EXPECT(exp, c) (exp)
#  else 
#    define SBE_BOUNDS_CHECK_EXPECT(exp, c) (__builtin_expect(exp, c))
#  endif

#endif

#define SBE_FLOAT_NAN std::numeric_limits<float>::quiet_NaN()
#define SBE_DOUBLE_NAN std::numeric_limits<double>::quiet_NaN()
#define SBE_NULLVALUE_INT8 (std::numeric_limits<std::int8_t>::min)()
#define SBE_NULLVALUE_INT16 (std::numeric_limits<std::int16_t>::min)()
#define SBE_NULLVALUE_INT32 (std::numeric_limits<std::int32_t>::min)()
#define SBE_NULLVALUE_INT64 (std::numeric_limits<std::int64_t>::min)()
#define SBE_NULLVALUE_UINT8 (std::numeric_limits<std::uint8_t>::max)()
#define SBE_NULLVALUE_UINT16 (std::numeric_limits<std::uint16_t>::max)()
#define SBE_NULLVALUE_UINT32 (std::numeric_limits<std::uint32_t>::max)()
#define SBE_NULLVALUE_UINT64 (std::numeric_limits<std::uint64_t>::max)()


#include "Side.h"
#include "SecurityType.h"
#include "MessageHeader.h"
#include "StatisticsType.h"
#include "UpdateAction.h"
#include "GroupSize.h"
#include "TradingStatus.h"
#include "UpdateType.h"
#include "Layer.h"
#include "Decimals.h"
#include "UpdateReason.h"
#include "OptionType.h"

namespace sbe {

class TradeSummary
{
private:
    char *m_buffer = nullptr;
    std::uint64_t m_bufferLength = 0;
    std::uint64_t m_offset = 0;
    std::uint64_t m_position = 0;
    std::uint64_t m_actingBlockLength = 0;
    std::uint64_t m_actingVersion = 0;

    inline std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
    {
        return &m_position;
    }

public:
    static const std::uint16_t SBE_BLOCK_LENGTH = static_cast<std::uint16_t>(152);
    static const std::uint16_t SBE_TEMPLATE_ID = static_cast<std::uint16_t>(15);
    static const std::uint16_t SBE_SCHEMA_ID = static_cast<std::uint16_t>(1);
    static const std::uint16_t SBE_SCHEMA_VERSION = static_cast<std::uint16_t>(1);
    static constexpr const char* SBE_SEMANTIC_VERSION = "";

    enum MetaAttribute
    {
        EPOCH, TIME_UNIT, SEMANTIC_TYPE, PRESENCE
    };

    union sbe_float_as_uint_u
    {
        float fp_value;
        std::uint32_t uint_value;
    };

    union sbe_double_as_uint_u
    {
        double fp_value;
        std::uint64_t uint_value;
    };

    using messageHeader = MessageHeader;

    TradeSummary() = default;

    TradeSummary(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t bufferLength,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion) :
        m_buffer(buffer),
        m_bufferLength(bufferLength),
        m_offset(offset),
        m_position(sbeCheckPosition(offset + actingBlockLength)),
        m_actingBlockLength(actingBlockLength),
        m_actingVersion(actingVersion)
    {
    }

    TradeSummary(char *buffer, const std::uint64_t bufferLength) :
        TradeSummary(buffer, 0, bufferLength, sbeBlockLength(), sbeSchemaVersion())
    {
    }

    TradeSummary(
        char *buffer,
        const std::uint64_t bufferLength,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion) :
        TradeSummary(buffer, 0, bufferLength, actingBlockLength, actingVersion)
    {
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeBlockLength() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(152);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sbeBlockAndHeaderLength() SBE_NOEXCEPT
    {
        return messageHeader::encodedLength() + sbeBlockLength();
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeTemplateId() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(15);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaId() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(1);
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t sbeSchemaVersion() SBE_NOEXCEPT
    {
        return static_cast<std::uint16_t>(1);
    }

    SBE_NODISCARD static const char *sbeSemanticVersion() SBE_NOEXCEPT
    {
        return "";
    }

    SBE_NODISCARD static SBE_CONSTEXPR const char *sbeSemanticType() SBE_NOEXCEPT
    {
        return "";
    }

    SBE_NODISCARD std::uint64_t offset() const SBE_NOEXCEPT
    {
        return m_offset;
    }

    TradeSummary &wrapForEncode(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingBlockLength = sbeBlockLength();
        m_actingVersion = sbeSchemaVersion();
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    TradeSummary &wrapAndApplyHeader(char *buffer, const std::uint64_t offset, const std::uint64_t bufferLength)
    {
        messageHeader hdr(buffer, offset, bufferLength, sbeSchemaVersion());

        hdr
            .blockLength(sbeBlockLength())
            .templateId(sbeTemplateId())
            .schemaId(sbeSchemaId())
            .version(sbeSchemaVersion());

        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset + messageHeader::encodedLength();
        m_actingBlockLength = sbeBlockLength();
        m_actingVersion = sbeSchemaVersion();
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    TradeSummary &wrapForDecode(
        char *buffer,
        const std::uint64_t offset,
        const std::uint64_t actingBlockLength,
        const std::uint64_t actingVersion,
        const std::uint64_t bufferLength)
    {
        m_buffer = buffer;
        m_bufferLength = bufferLength;
        m_offset = offset;
        m_actingBlockLength = actingBlockLength;
        m_actingVersion = actingVersion;
        m_position = sbeCheckPosition(m_offset + m_actingBlockLength);
        return *this;
    }

    TradeSummary &sbeRewind()
    {
        return wrapForDecode(m_buffer, m_offset, m_actingBlockLength, m_actingVersion, m_bufferLength);
    }

    SBE_NODISCARD std::uint64_t sbePosition() const SBE_NOEXCEPT
    {
        return m_position;
    }

    // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
    std::uint64_t sbeCheckPosition(const std::uint64_t position)
    {
        if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
        {
            throw std::runtime_error("buffer too short [E100]");
        }
        return position;
    }

    void sbePosition(const std::uint64_t position)
    {
        m_position = sbeCheckPosition(position);
    }

    SBE_NODISCARD std::uint64_t encodedLength() const SBE_NOEXCEPT
    {
        return sbePosition() - m_offset;
    }

    SBE_NODISCARD std::uint64_t decodeLength() const
    {
        TradeSummary skipper(m_buffer, m_offset, m_bufferLength, sbeBlockLength(), m_actingVersion);
        skipper.skip();
        return skipper.encodedLength();
    }

    SBE_NODISCARD const char *buffer() const SBE_NOEXCEPT
    {
        return m_buffer;
    }

    SBE_NODISCARD char *buffer() SBE_NOEXCEPT
    {
        return m_buffer;
    }

    SBE_NODISCARD std::uint64_t bufferLength() const SBE_NOEXCEPT
    {
        return m_bufferLength;
    }

    SBE_NODISCARD std::uint64_t actingVersion() const SBE_NOEXCEPT
    {
        return m_actingVersion;
    }

    SBE_NODISCARD static const char *sourceNameMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::SEMANTIC_TYPE: return "MessageInfo";
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t sourceNameId() SBE_NOEXCEPT
    {
        return 100;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sourceNameSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool sourceNameInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t sourceNameEncodingOffset() SBE_NOEXCEPT
    {
        return 0;
    }

    static SBE_CONSTEXPR char sourceNameNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char sourceNameMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char sourceNameMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t sourceNameEncodingLength() SBE_NOEXCEPT
    {
        return 16;
    }

    static SBE_CONSTEXPR std::uint64_t sourceNameLength() SBE_NOEXCEPT
    {
        return 16;
    }

    SBE_NODISCARD const char *sourceName() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 0;
    }

    SBE_NODISCARD char *sourceName() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 0;
    }

    SBE_NODISCARD char sourceName(const std::uint64_t index) const
    {
        if (index >= 16)
        {
            throw std::runtime_error("index out of range for sourceName [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 0 + (index * 1), sizeof(char));
        return (val);
    }

    TradeSummary &sourceName(const std::uint64_t index, const char value)
    {
        if (index >= 16)
        {
            throw std::runtime_error("index out of range for sourceName [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 0 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getSourceName(char *const dst, const std::uint64_t length) const
    {
        if (length > 16)
        {
            throw std::runtime_error("length too large for getSourceName [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 0, sizeof(char) * static_cast<std::size_t>(length));
        return length;
    }

    TradeSummary &putSourceName(const char *const src) SBE_NOEXCEPT
    {
        std::memcpy(m_buffer + m_offset + 0, src, sizeof(char) * 16);
        return *this;
    }

    SBE_NODISCARD std::string getSourceNameAsString() const
    {
        const char *buffer = m_buffer + m_offset + 0;
        std::size_t length = 0;

        for (; length < 16 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getSourceNameAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getSourceNameAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #if __cplusplus >= 201703L
    SBE_NODISCARD std::string_view getSourceNameAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 0;
        std::size_t length = 0;

        for (; length < 16 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #if __cplusplus >= 201703L
    TradeSummary &putSourceName(const std::string_view str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 16)
        {
            throw std::runtime_error("string too large for putSourceName [E106]");
        }

        std::memcpy(m_buffer + m_offset + 0, str.data(), srcLength);
        for (std::size_t start = srcLength; start < 16; ++start)
        {
            m_buffer[m_offset + 0 + start] = 0;
        }

        return *this;
    }
    #else
    TradeSummary &putSourceName(const std::string &str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 16)
        {
            throw std::runtime_error("string too large for putSourceName [E106]");
        }

        std::memcpy(m_buffer + m_offset + 0, str.c_str(), srcLength);
        for (std::size_t start = srcLength; start < 16; ++start)
        {
            m_buffer[m_offset + 0 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *sourceSessionIDMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::SEMANTIC_TYPE: return "MessageInfo";
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t sourceSessionIDId() SBE_NOEXCEPT
    {
        return 101;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sourceSessionIDSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool sourceSessionIDInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t sourceSessionIDEncodingOffset() SBE_NOEXCEPT
    {
        return 16;
    }

    static SBE_CONSTEXPR std::uint8_t sourceSessionIDNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT8;
    }

    static SBE_CONSTEXPR std::uint8_t sourceSessionIDMinValue() SBE_NOEXCEPT
    {
        return static_cast<std::uint8_t>(0);
    }

    static SBE_CONSTEXPR std::uint8_t sourceSessionIDMaxValue() SBE_NOEXCEPT
    {
        return static_cast<std::uint8_t>(254);
    }

    static SBE_CONSTEXPR std::size_t sourceSessionIDEncodingLength() SBE_NOEXCEPT
    {
        return 16;
    }

    static SBE_CONSTEXPR std::uint64_t sourceSessionIDLength() SBE_NOEXCEPT
    {
        return 16;
    }

    SBE_NODISCARD const char *sourceSessionID() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 16;
    }

    SBE_NODISCARD char *sourceSessionID() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 16;
    }

    SBE_NODISCARD std::uint8_t sourceSessionID(const std::uint64_t index) const
    {
        if (index >= 16)
        {
            throw std::runtime_error("index out of range for sourceSessionID [E104]");
        }

        std::uint8_t val;
        std::memcpy(&val, m_buffer + m_offset + 16 + (index * 1), sizeof(std::uint8_t));
        return (val);
    }

    TradeSummary &sourceSessionID(const std::uint64_t index, const std::uint8_t value)
    {
        if (index >= 16)
        {
            throw std::runtime_error("index out of range for sourceSessionID [E105]");
        }

        std::uint8_t val = (value);
        std::memcpy(m_buffer + m_offset + 16 + (index * 1), &val, sizeof(std::uint8_t));
        return *this;
    }

    std::uint64_t getSourceSessionID(char *const dst, const std::uint64_t length) const
    {
        if (length > 16)
        {
            throw std::runtime_error("length too large for getSourceSessionID [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 16, sizeof(std::uint8_t) * static_cast<std::size_t>(length));
        return length;
    }

    TradeSummary &putSourceSessionID(const char *const src) SBE_NOEXCEPT
    {
        std::memcpy(m_buffer + m_offset + 16, src, sizeof(std::uint8_t) * 16);
        return *this;
    }

    SBE_NODISCARD static const char *sourceSeqNoMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::SEMANTIC_TYPE: return "MessageInfo";
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t sourceSeqNoId() SBE_NOEXCEPT
    {
        return 102;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sourceSeqNoSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool sourceSeqNoInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t sourceSeqNoEncodingOffset() SBE_NOEXCEPT
    {
        return 32;
    }

    static SBE_CONSTEXPR std::uint64_t sourceSeqNoNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT64;
    }

    static SBE_CONSTEXPR std::uint64_t sourceSeqNoMinValue() SBE_NOEXCEPT
    {
        return UINT64_C(0x0);
    }

    static SBE_CONSTEXPR std::uint64_t sourceSeqNoMaxValue() SBE_NOEXCEPT
    {
        return UINT64_C(0xfffffffffffffffe);
    }

    static SBE_CONSTEXPR std::size_t sourceSeqNoEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::uint64_t sourceSeqNo() const SBE_NOEXCEPT
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset + 32, sizeof(std::uint64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    TradeSummary &sourceSeqNo(const std::uint64_t value) SBE_NOEXCEPT
    {
        std::uint64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 32, &val, sizeof(std::uint64_t));
        return *this;
    }

    SBE_NODISCARD static const char *originCreateTimeUTCMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::SEMANTIC_TYPE: return "MessageInfo";
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t originCreateTimeUTCId() SBE_NOEXCEPT
    {
        return 103;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t originCreateTimeUTCSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool originCreateTimeUTCInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t originCreateTimeUTCEncodingOffset() SBE_NOEXCEPT
    {
        return 40;
    }

    static SBE_CONSTEXPR std::int64_t originCreateTimeUTCNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t originCreateTimeUTCMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t originCreateTimeUTCMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t originCreateTimeUTCEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t originCreateTimeUTC() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 40, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    TradeSummary &originCreateTimeUTC(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 40, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *exchangeMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t exchangeId() SBE_NOEXCEPT
    {
        return 200;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t exchangeSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool exchangeInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t exchangeEncodingOffset() SBE_NOEXCEPT
    {
        return 48;
    }

    static SBE_CONSTEXPR char exchangeNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char exchangeMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char exchangeMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t exchangeEncodingLength() SBE_NOEXCEPT
    {
        return 32;
    }

    static SBE_CONSTEXPR std::uint64_t exchangeLength() SBE_NOEXCEPT
    {
        return 32;
    }

    SBE_NODISCARD const char *exchange() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 48;
    }

    SBE_NODISCARD char *exchange() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 48;
    }

    SBE_NODISCARD char exchange(const std::uint64_t index) const
    {
        if (index >= 32)
        {
            throw std::runtime_error("index out of range for exchange [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 48 + (index * 1), sizeof(char));
        return (val);
    }

    TradeSummary &exchange(const std::uint64_t index, const char value)
    {
        if (index >= 32)
        {
            throw std::runtime_error("index out of range for exchange [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 48 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getExchange(char *const dst, const std::uint64_t length) const
    {
        if (length > 32)
        {
            throw std::runtime_error("length too large for getExchange [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 48, sizeof(char) * static_cast<std::size_t>(length));
        return length;
    }

    TradeSummary &putExchange(const char *const src) SBE_NOEXCEPT
    {
        std::memcpy(m_buffer + m_offset + 48, src, sizeof(char) * 32);
        return *this;
    }

    SBE_NODISCARD std::string getExchangeAsString() const
    {
        const char *buffer = m_buffer + m_offset + 48;
        std::size_t length = 0;

        for (; length < 32 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getExchangeAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getExchangeAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #if __cplusplus >= 201703L
    SBE_NODISCARD std::string_view getExchangeAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 48;
        std::size_t length = 0;

        for (; length < 32 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #if __cplusplus >= 201703L
    TradeSummary &putExchange(const std::string_view str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 32)
        {
            throw std::runtime_error("string too large for putExchange [E106]");
        }

        std::memcpy(m_buffer + m_offset + 48, str.data(), srcLength);
        for (std::size_t start = srcLength; start < 32; ++start)
        {
            m_buffer[m_offset + 48 + start] = 0;
        }

        return *this;
    }
    #else
    TradeSummary &putExchange(const std::string &str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 32)
        {
            throw std::runtime_error("string too large for putExchange [E106]");
        }

        std::memcpy(m_buffer + m_offset + 48, str.c_str(), srcLength);
        for (std::size_t start = srcLength; start < 32; ++start)
        {
            m_buffer[m_offset + 48 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *symbolMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t symbolId() SBE_NOEXCEPT
    {
        return 201;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t symbolSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool symbolInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t symbolEncodingOffset() SBE_NOEXCEPT
    {
        return 80;
    }

    static SBE_CONSTEXPR char symbolNullValue() SBE_NOEXCEPT
    {
        return static_cast<char>(0);
    }

    static SBE_CONSTEXPR char symbolMinValue() SBE_NOEXCEPT
    {
        return static_cast<char>(32);
    }

    static SBE_CONSTEXPR char symbolMaxValue() SBE_NOEXCEPT
    {
        return static_cast<char>(126);
    }

    static SBE_CONSTEXPR std::size_t symbolEncodingLength() SBE_NOEXCEPT
    {
        return 48;
    }

    static SBE_CONSTEXPR std::uint64_t symbolLength() SBE_NOEXCEPT
    {
        return 48;
    }

    SBE_NODISCARD const char *symbol() const SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 80;
    }

    SBE_NODISCARD char *symbol() SBE_NOEXCEPT
    {
        return m_buffer + m_offset + 80;
    }

    SBE_NODISCARD char symbol(const std::uint64_t index) const
    {
        if (index >= 48)
        {
            throw std::runtime_error("index out of range for symbol [E104]");
        }

        char val;
        std::memcpy(&val, m_buffer + m_offset + 80 + (index * 1), sizeof(char));
        return (val);
    }

    TradeSummary &symbol(const std::uint64_t index, const char value)
    {
        if (index >= 48)
        {
            throw std::runtime_error("index out of range for symbol [E105]");
        }

        char val = (value);
        std::memcpy(m_buffer + m_offset + 80 + (index * 1), &val, sizeof(char));
        return *this;
    }

    std::uint64_t getSymbol(char *const dst, const std::uint64_t length) const
    {
        if (length > 48)
        {
            throw std::runtime_error("length too large for getSymbol [E106]");
        }

        std::memcpy(dst, m_buffer + m_offset + 80, sizeof(char) * static_cast<std::size_t>(length));
        return length;
    }

    TradeSummary &putSymbol(const char *const src) SBE_NOEXCEPT
    {
        std::memcpy(m_buffer + m_offset + 80, src, sizeof(char) * 48);
        return *this;
    }

    SBE_NODISCARD std::string getSymbolAsString() const
    {
        const char *buffer = m_buffer + m_offset + 80;
        std::size_t length = 0;

        for (; length < 48 && *(buffer + length) != '\0'; ++length);
        std::string result(buffer, length);

        return result;
    }

    std::string getSymbolAsJsonEscapedString()
    {
        std::ostringstream oss;
        std::string s = getSymbolAsString();

        for (const auto c : s)
        {
            switch (c)
            {
                case '"': oss << "\\\""; break;
                case '\\': oss << "\\\\"; break;
                case '\b': oss << "\\b"; break;
                case '\f': oss << "\\f"; break;
                case '\n': oss << "\\n"; break;
                case '\r': oss << "\\r"; break;
                case '\t': oss << "\\t"; break;

                default:
                    if ('\x00' <= c && c <= '\x1f')
                    {
                        oss << "\\u" << std::hex << std::setw(4)
                            << std::setfill('0') << (int)(c);
                    }
                    else
                    {
                        oss << c;
                    }
            }
        }

        return oss.str();
    }

    #if __cplusplus >= 201703L
    SBE_NODISCARD std::string_view getSymbolAsStringView() const SBE_NOEXCEPT
    {
        const char *buffer = m_buffer + m_offset + 80;
        std::size_t length = 0;

        for (; length < 48 && *(buffer + length) != '\0'; ++length);
        std::string_view result(buffer, length);

        return result;
    }
    #endif

    #if __cplusplus >= 201703L
    TradeSummary &putSymbol(const std::string_view str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 48)
        {
            throw std::runtime_error("string too large for putSymbol [E106]");
        }

        std::memcpy(m_buffer + m_offset + 80, str.data(), srcLength);
        for (std::size_t start = srcLength; start < 48; ++start)
        {
            m_buffer[m_offset + 80 + start] = 0;
        }

        return *this;
    }
    #else
    TradeSummary &putSymbol(const std::string &str)
    {
        const std::size_t srcLength = str.length();
        if (srcLength > 48)
        {
            throw std::runtime_error("string too large for putSymbol [E106]");
        }

        std::memcpy(m_buffer + m_offset + 80, str.c_str(), srcLength);
        for (std::size_t start = srcLength; start < 48; ++start)
        {
            m_buffer[m_offset + 80 + start] = 0;
        }

        return *this;
    }
    #endif

    SBE_NODISCARD static const char *exchangeTimeUTCMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t exchangeTimeUTCId() SBE_NOEXCEPT
    {
        return 202;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t exchangeTimeUTCSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool exchangeTimeUTCInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t exchangeTimeUTCEncodingOffset() SBE_NOEXCEPT
    {
        return 128;
    }

    static SBE_CONSTEXPR std::int64_t exchangeTimeUTCNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t exchangeTimeUTCMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t exchangeTimeUTCMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t exchangeTimeUTCEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t exchangeTimeUTC() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 128, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    TradeSummary &exchangeTimeUTC(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 128, &val, sizeof(std::int64_t));
        return *this;
    }

    SBE_NODISCARD static const char *exchangeSequenceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t exchangeSequenceId() SBE_NOEXCEPT
    {
        return 203;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t exchangeSequenceSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool exchangeSequenceInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t exchangeSequenceEncodingOffset() SBE_NOEXCEPT
    {
        return 136;
    }

    static SBE_CONSTEXPR std::uint64_t exchangeSequenceNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_UINT64;
    }

    static SBE_CONSTEXPR std::uint64_t exchangeSequenceMinValue() SBE_NOEXCEPT
    {
        return UINT64_C(0x0);
    }

    static SBE_CONSTEXPR std::uint64_t exchangeSequenceMaxValue() SBE_NOEXCEPT
    {
        return UINT64_C(0xfffffffffffffffe);
    }

    static SBE_CONSTEXPR std::size_t exchangeSequenceEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::uint64_t exchangeSequence() const SBE_NOEXCEPT
    {
        std::uint64_t val;
        std::memcpy(&val, m_buffer + m_offset + 136, sizeof(std::uint64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    TradeSummary &exchangeSequence(const std::uint64_t value) SBE_NOEXCEPT
    {
        std::uint64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 136, &val, sizeof(std::uint64_t));
        return *this;
    }

    SBE_NODISCARD static const char *sendingTimeUTCMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
    {
        switch (metaAttribute)
        {
            case MetaAttribute::PRESENCE: return "required";
            default: return "";
        }
    }

    static SBE_CONSTEXPR std::uint16_t sendingTimeUTCId() SBE_NOEXCEPT
    {
        return 204;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sendingTimeUTCSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool sendingTimeUTCInActingVersion() SBE_NOEXCEPT
    {
        return true;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::size_t sendingTimeUTCEncodingOffset() SBE_NOEXCEPT
    {
        return 144;
    }

    static SBE_CONSTEXPR std::int64_t sendingTimeUTCNullValue() SBE_NOEXCEPT
    {
        return SBE_NULLVALUE_INT64;
    }

    static SBE_CONSTEXPR std::int64_t sendingTimeUTCMinValue() SBE_NOEXCEPT
    {
        return INT64_C(-9223372036854775807);
    }

    static SBE_CONSTEXPR std::int64_t sendingTimeUTCMaxValue() SBE_NOEXCEPT
    {
        return INT64_C(9223372036854775807);
    }

    static SBE_CONSTEXPR std::size_t sendingTimeUTCEncodingLength() SBE_NOEXCEPT
    {
        return 8;
    }

    SBE_NODISCARD std::int64_t sendingTimeUTC() const SBE_NOEXCEPT
    {
        std::int64_t val;
        std::memcpy(&val, m_buffer + m_offset + 144, sizeof(std::int64_t));
        return SBE_LITTLE_ENDIAN_ENCODE_64(val);
    }

    TradeSummary &sendingTimeUTC(const std::int64_t value) SBE_NOEXCEPT
    {
        std::int64_t val = SBE_LITTLE_ENDIAN_ENCODE_64(value);
        std::memcpy(m_buffer + m_offset + 144, &val, sizeof(std::int64_t));
        return *this;
    }

    class Trades
    {
    private:
        char *m_buffer = nullptr;
        std::uint64_t m_bufferLength = 0;
        std::uint64_t m_initialPosition = 0;
        std::uint64_t *m_positionPtr = nullptr;
        std::uint64_t m_blockLength = 0;
        std::uint64_t m_count = 0;
        std::uint64_t m_index = 0;
        std::uint64_t m_offset = 0;
        std::uint64_t m_actingVersion = 0;

        SBE_NODISCARD std::uint64_t *sbePositionPtr() SBE_NOEXCEPT
        {
            return m_positionPtr;
        }

    public:
        Trades() = default;

        inline void wrapForDecode(
            char *buffer,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
            GroupSize dimensions(buffer, *pos, bufferLength, actingVersion);
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            m_blockLength = dimensions.blockLength();
            m_count = dimensions.numInGroup();
            m_index = 0;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 4;
        }

        inline void wrapForEncode(
            char *buffer,
            const std::uint16_t count,
            std::uint64_t *pos,
            const std::uint64_t actingVersion,
            const std::uint64_t bufferLength)
        {
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wtype-limits"
    #endif
            if (count > 65534)
            {
                throw std::runtime_error("count outside of allowed range [E110]");
            }
    #if defined(__GNUG__) && !defined(__clang__)
    #pragma GCC diagnostic pop
    #endif
            m_buffer = buffer;
            m_bufferLength = bufferLength;
            GroupSize dimensions(buffer, *pos, bufferLength, actingVersion);
            dimensions.blockLength(static_cast<std::uint16_t>(186));
            dimensions.numInGroup(static_cast<std::uint16_t>(count));
            m_index = 0;
            m_count = count;
            m_blockLength = 186;
            m_actingVersion = actingVersion;
            m_initialPosition = *pos;
            m_positionPtr = pos;
            *m_positionPtr = *m_positionPtr + 4;
        }

        static SBE_CONSTEXPR std::uint64_t sbeHeaderSize() SBE_NOEXCEPT
        {
            return 4;
        }

        static SBE_CONSTEXPR std::uint64_t sbeBlockLength() SBE_NOEXCEPT
        {
            return 186;
        }

        SBE_NODISCARD std::uint64_t sbePosition() const SBE_NOEXCEPT
        {
            return *m_positionPtr;
        }

        // NOLINTNEXTLINE(readability-convert-member-functions-to-static)
        std::uint64_t sbeCheckPosition(const std::uint64_t position)
        {
            if (SBE_BOUNDS_CHECK_EXPECT((position > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short [E100]");
            }
            return position;
        }

        void sbePosition(const std::uint64_t position)
        {
            *m_positionPtr = sbeCheckPosition(position);
        }

        SBE_NODISCARD inline std::uint64_t count() const SBE_NOEXCEPT
        {
            return m_count;
        }

        SBE_NODISCARD inline bool hasNext() const SBE_NOEXCEPT
        {
            return m_index < m_count;
        }

        inline Trades &next()
        {
            if (m_index >= m_count)
            {
                throw std::runtime_error("index >= count [E108]");
            }
            m_offset = *m_positionPtr;
            if (SBE_BOUNDS_CHECK_EXPECT(((m_offset + m_blockLength) > m_bufferLength), false))
            {
                throw std::runtime_error("buffer too short for next group index [E108]");
            }
            *m_positionPtr = m_offset + m_blockLength;
            ++m_index;

            return *this;
        }

        inline std::uint64_t resetCountToIndex()
        {
            m_count = m_index;
            GroupSize dimensions(m_buffer, m_initialPosition, m_bufferLength, m_actingVersion);
            dimensions.numInGroup(static_cast<std::uint16_t>(m_count));
            return m_count;
        }

        template<class Func> inline void forEach(Func &&func)
        {
            while (hasNext())
            {
                next();
                func(*this);
            }
        }


        SBE_NODISCARD static const char *sideMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t sideId() SBE_NOEXCEPT
        {
            return 301;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t sideSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool sideInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t sideEncodingOffset() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t sideEncodingLength() SBE_NOEXCEPT
        {
            return 1;
        }

        SBE_NODISCARD std::uint8_t sideRaw() const SBE_NOEXCEPT
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint8_t));
            return (val);
        }

        SBE_NODISCARD Side::Value side() const
        {
            std::uint8_t val;
            std::memcpy(&val, m_buffer + m_offset + 0, sizeof(std::uint8_t));
            return Side::get((val));
        }

        Trades &side(const Side::Value value) SBE_NOEXCEPT
        {
            std::uint8_t val = (value);
            std::memcpy(m_buffer + m_offset + 0, &val, sizeof(std::uint8_t));
            return *this;
        }

        SBE_NODISCARD static const char *priceMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t priceId() SBE_NOEXCEPT
        {
            return 302;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t priceSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool priceInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t priceEncodingOffset() SBE_NOEXCEPT
        {
            return 1;
        }

        static SBE_CONSTEXPR double priceNullValue() SBE_NOEXCEPT
        {
            return SBE_DOUBLE_NAN;
        }

        static SBE_CONSTEXPR double priceMinValue() SBE_NOEXCEPT
        {
            return 4.9E-324;
        }

        static SBE_CONSTEXPR double priceMaxValue() SBE_NOEXCEPT
        {
            return 1.7976931348623157E308;
        }

        static SBE_CONSTEXPR std::size_t priceEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD double price() const SBE_NOEXCEPT
        {
            union sbe_double_as_uint_u val;
            std::memcpy(&val, m_buffer + m_offset + 1, sizeof(double));
            val.uint_value = SBE_LITTLE_ENDIAN_ENCODE_64(val.uint_value);
            return val.fp_value;
        }

        Trades &price(const double value) SBE_NOEXCEPT
        {
            union sbe_double_as_uint_u val;
            val.fp_value = value;
            val.uint_value = SBE_LITTLE_ENDIAN_ENCODE_64(val.uint_value);
            std::memcpy(m_buffer + m_offset + 1, &val, sizeof(double));
            return *this;
        }

        SBE_NODISCARD static const char *quantityMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t quantityId() SBE_NOEXCEPT
        {
            return 303;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t quantitySinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool quantityInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t quantityEncodingOffset() SBE_NOEXCEPT
        {
            return 9;
        }

        static SBE_CONSTEXPR double quantityNullValue() SBE_NOEXCEPT
        {
            return SBE_DOUBLE_NAN;
        }

        static SBE_CONSTEXPR double quantityMinValue() SBE_NOEXCEPT
        {
            return 4.9E-324;
        }

        static SBE_CONSTEXPR double quantityMaxValue() SBE_NOEXCEPT
        {
            return 1.7976931348623157E308;
        }

        static SBE_CONSTEXPR std::size_t quantityEncodingLength() SBE_NOEXCEPT
        {
            return 8;
        }

        SBE_NODISCARD double quantity() const SBE_NOEXCEPT
        {
            union sbe_double_as_uint_u val;
            std::memcpy(&val, m_buffer + m_offset + 9, sizeof(double));
            val.uint_value = SBE_LITTLE_ENDIAN_ENCODE_64(val.uint_value);
            return val.fp_value;
        }

        Trades &quantity(const double value) SBE_NOEXCEPT
        {
            union sbe_double_as_uint_u val;
            val.fp_value = value;
            val.uint_value = SBE_LITTLE_ENDIAN_ENCODE_64(val.uint_value);
            std::memcpy(m_buffer + m_offset + 9, &val, sizeof(double));
            return *this;
        }

        SBE_NODISCARD static const char *tradeIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t tradeIdId() SBE_NOEXCEPT
        {
            return 304;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t tradeIdSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool tradeIdInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t tradeIdEncodingOffset() SBE_NOEXCEPT
        {
            return 17;
        }

        static SBE_CONSTEXPR char tradeIdNullValue() SBE_NOEXCEPT
        {
            return static_cast<char>(0);
        }

        static SBE_CONSTEXPR char tradeIdMinValue() SBE_NOEXCEPT
        {
            return static_cast<char>(32);
        }

        static SBE_CONSTEXPR char tradeIdMaxValue() SBE_NOEXCEPT
        {
            return static_cast<char>(126);
        }

        static SBE_CONSTEXPR std::size_t tradeIdEncodingLength() SBE_NOEXCEPT
        {
            return 40;
        }

        static SBE_CONSTEXPR std::uint64_t tradeIdLength() SBE_NOEXCEPT
        {
            return 40;
        }

        SBE_NODISCARD const char *tradeId() const SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 17;
        }

        SBE_NODISCARD char *tradeId() SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 17;
        }

        SBE_NODISCARD char tradeId(const std::uint64_t index) const
        {
            if (index >= 40)
            {
                throw std::runtime_error("index out of range for tradeId [E104]");
            }

            char val;
            std::memcpy(&val, m_buffer + m_offset + 17 + (index * 1), sizeof(char));
            return (val);
        }

        Trades &tradeId(const std::uint64_t index, const char value)
        {
            if (index >= 40)
            {
                throw std::runtime_error("index out of range for tradeId [E105]");
            }

            char val = (value);
            std::memcpy(m_buffer + m_offset + 17 + (index * 1), &val, sizeof(char));
            return *this;
        }

        std::uint64_t getTradeId(char *const dst, const std::uint64_t length) const
        {
            if (length > 40)
            {
                throw std::runtime_error("length too large for getTradeId [E106]");
            }

            std::memcpy(dst, m_buffer + m_offset + 17, sizeof(char) * static_cast<std::size_t>(length));
            return length;
        }

        Trades &putTradeId(const char *const src) SBE_NOEXCEPT
        {
            std::memcpy(m_buffer + m_offset + 17, src, sizeof(char) * 40);
            return *this;
        }

        SBE_NODISCARD std::string getTradeIdAsString() const
        {
            const char *buffer = m_buffer + m_offset + 17;
            std::size_t length = 0;

            for (; length < 40 && *(buffer + length) != '\0'; ++length);
            std::string result(buffer, length);

            return result;
        }

        std::string getTradeIdAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getTradeIdAsString();

            for (const auto c : s)
            {
                switch (c)
                {
                    case '"': oss << "\\\""; break;
                    case '\\': oss << "\\\\"; break;
                    case '\b': oss << "\\b"; break;
                    case '\f': oss << "\\f"; break;
                    case '\n': oss << "\\n"; break;
                    case '\r': oss << "\\r"; break;
                    case '\t': oss << "\\t"; break;

                    default:
                        if ('\x00' <= c && c <= '\x1f')
                        {
                            oss << "\\u" << std::hex << std::setw(4)
                                << std::setfill('0') << (int)(c);
                        }
                        else
                        {
                            oss << c;
                        }
                }
            }

            return oss.str();
        }

        #if __cplusplus >= 201703L
        SBE_NODISCARD std::string_view getTradeIdAsStringView() const SBE_NOEXCEPT
        {
            const char *buffer = m_buffer + m_offset + 17;
            std::size_t length = 0;

            for (; length < 40 && *(buffer + length) != '\0'; ++length);
            std::string_view result(buffer, length);

            return result;
        }
        #endif

        #if __cplusplus >= 201703L
        Trades &putTradeId(const std::string_view str)
        {
            const std::size_t srcLength = str.length();
            if (srcLength > 40)
            {
                throw std::runtime_error("string too large for putTradeId [E106]");
            }

            std::memcpy(m_buffer + m_offset + 17, str.data(), srcLength);
            for (std::size_t start = srcLength; start < 40; ++start)
            {
                m_buffer[m_offset + 17 + start] = 0;
            }

            return *this;
        }
        #else
        Trades &putTradeId(const std::string &str)
        {
            const std::size_t srcLength = str.length();
            if (srcLength > 40)
            {
                throw std::runtime_error("string too large for putTradeId [E106]");
            }

            std::memcpy(m_buffer + m_offset + 17, str.c_str(), srcLength);
            for (std::size_t start = srcLength; start < 40; ++start)
            {
                m_buffer[m_offset + 17 + start] = 0;
            }

            return *this;
        }
        #endif

        SBE_NODISCARD static const char *takerOrderIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t takerOrderIdId() SBE_NOEXCEPT
        {
            return 305;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t takerOrderIdSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool takerOrderIdInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t takerOrderIdEncodingOffset() SBE_NOEXCEPT
        {
            return 57;
        }

        static SBE_CONSTEXPR char takerOrderIdNullValue() SBE_NOEXCEPT
        {
            return static_cast<char>(0);
        }

        static SBE_CONSTEXPR char takerOrderIdMinValue() SBE_NOEXCEPT
        {
            return static_cast<char>(32);
        }

        static SBE_CONSTEXPR char takerOrderIdMaxValue() SBE_NOEXCEPT
        {
            return static_cast<char>(126);
        }

        static SBE_CONSTEXPR std::size_t takerOrderIdEncodingLength() SBE_NOEXCEPT
        {
            return 64;
        }

        static SBE_CONSTEXPR std::uint64_t takerOrderIdLength() SBE_NOEXCEPT
        {
            return 64;
        }

        SBE_NODISCARD const char *takerOrderId() const SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 57;
        }

        SBE_NODISCARD char *takerOrderId() SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 57;
        }

        SBE_NODISCARD char takerOrderId(const std::uint64_t index) const
        {
            if (index >= 64)
            {
                throw std::runtime_error("index out of range for takerOrderId [E104]");
            }

            char val;
            std::memcpy(&val, m_buffer + m_offset + 57 + (index * 1), sizeof(char));
            return (val);
        }

        Trades &takerOrderId(const std::uint64_t index, const char value)
        {
            if (index >= 64)
            {
                throw std::runtime_error("index out of range for takerOrderId [E105]");
            }

            char val = (value);
            std::memcpy(m_buffer + m_offset + 57 + (index * 1), &val, sizeof(char));
            return *this;
        }

        std::uint64_t getTakerOrderId(char *const dst, const std::uint64_t length) const
        {
            if (length > 64)
            {
                throw std::runtime_error("length too large for getTakerOrderId [E106]");
            }

            std::memcpy(dst, m_buffer + m_offset + 57, sizeof(char) * static_cast<std::size_t>(length));
            return length;
        }

        Trades &putTakerOrderId(const char *const src) SBE_NOEXCEPT
        {
            std::memcpy(m_buffer + m_offset + 57, src, sizeof(char) * 64);
            return *this;
        }

        SBE_NODISCARD std::string getTakerOrderIdAsString() const
        {
            const char *buffer = m_buffer + m_offset + 57;
            std::size_t length = 0;

            for (; length < 64 && *(buffer + length) != '\0'; ++length);
            std::string result(buffer, length);

            return result;
        }

        std::string getTakerOrderIdAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getTakerOrderIdAsString();

            for (const auto c : s)
            {
                switch (c)
                {
                    case '"': oss << "\\\""; break;
                    case '\\': oss << "\\\\"; break;
                    case '\b': oss << "\\b"; break;
                    case '\f': oss << "\\f"; break;
                    case '\n': oss << "\\n"; break;
                    case '\r': oss << "\\r"; break;
                    case '\t': oss << "\\t"; break;

                    default:
                        if ('\x00' <= c && c <= '\x1f')
                        {
                            oss << "\\u" << std::hex << std::setw(4)
                                << std::setfill('0') << (int)(c);
                        }
                        else
                        {
                            oss << c;
                        }
                }
            }

            return oss.str();
        }

        #if __cplusplus >= 201703L
        SBE_NODISCARD std::string_view getTakerOrderIdAsStringView() const SBE_NOEXCEPT
        {
            const char *buffer = m_buffer + m_offset + 57;
            std::size_t length = 0;

            for (; length < 64 && *(buffer + length) != '\0'; ++length);
            std::string_view result(buffer, length);

            return result;
        }
        #endif

        #if __cplusplus >= 201703L
        Trades &putTakerOrderId(const std::string_view str)
        {
            const std::size_t srcLength = str.length();
            if (srcLength > 64)
            {
                throw std::runtime_error("string too large for putTakerOrderId [E106]");
            }

            std::memcpy(m_buffer + m_offset + 57, str.data(), srcLength);
            for (std::size_t start = srcLength; start < 64; ++start)
            {
                m_buffer[m_offset + 57 + start] = 0;
            }

            return *this;
        }
        #else
        Trades &putTakerOrderId(const std::string &str)
        {
            const std::size_t srcLength = str.length();
            if (srcLength > 64)
            {
                throw std::runtime_error("string too large for putTakerOrderId [E106]");
            }

            std::memcpy(m_buffer + m_offset + 57, str.c_str(), srcLength);
            for (std::size_t start = srcLength; start < 64; ++start)
            {
                m_buffer[m_offset + 57 + start] = 0;
            }

            return *this;
        }
        #endif

        SBE_NODISCARD static const char *makerOrderIdMetaAttribute(const MetaAttribute metaAttribute) SBE_NOEXCEPT
        {
            switch (metaAttribute)
            {
                case MetaAttribute::PRESENCE: return "required";
                default: return "";
            }
        }

        static SBE_CONSTEXPR std::uint16_t makerOrderIdId() SBE_NOEXCEPT
        {
            return 306;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t makerOrderIdSinceVersion() SBE_NOEXCEPT
        {
            return 0;
        }

        SBE_NODISCARD bool makerOrderIdInActingVersion() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static SBE_CONSTEXPR std::size_t makerOrderIdEncodingOffset() SBE_NOEXCEPT
        {
            return 121;
        }

        static SBE_CONSTEXPR char makerOrderIdNullValue() SBE_NOEXCEPT
        {
            return static_cast<char>(0);
        }

        static SBE_CONSTEXPR char makerOrderIdMinValue() SBE_NOEXCEPT
        {
            return static_cast<char>(32);
        }

        static SBE_CONSTEXPR char makerOrderIdMaxValue() SBE_NOEXCEPT
        {
            return static_cast<char>(126);
        }

        static SBE_CONSTEXPR std::size_t makerOrderIdEncodingLength() SBE_NOEXCEPT
        {
            return 64;
        }

        static SBE_CONSTEXPR std::uint64_t makerOrderIdLength() SBE_NOEXCEPT
        {
            return 64;
        }

        SBE_NODISCARD const char *makerOrderId() const SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 121;
        }

        SBE_NODISCARD char *makerOrderId() SBE_NOEXCEPT
        {
            return m_buffer + m_offset + 121;
        }

        SBE_NODISCARD char makerOrderId(const std::uint64_t index) const
        {
            if (index >= 64)
            {
                throw std::runtime_error("index out of range for makerOrderId [E104]");
            }

            char val;
            std::memcpy(&val, m_buffer + m_offset + 121 + (index * 1), sizeof(char));
            return (val);
        }

        Trades &makerOrderId(const std::uint64_t index, const char value)
        {
            if (index >= 64)
            {
                throw std::runtime_error("index out of range for makerOrderId [E105]");
            }

            char val = (value);
            std::memcpy(m_buffer + m_offset + 121 + (index * 1), &val, sizeof(char));
            return *this;
        }

        std::uint64_t getMakerOrderId(char *const dst, const std::uint64_t length) const
        {
            if (length > 64)
            {
                throw std::runtime_error("length too large for getMakerOrderId [E106]");
            }

            std::memcpy(dst, m_buffer + m_offset + 121, sizeof(char) * static_cast<std::size_t>(length));
            return length;
        }

        Trades &putMakerOrderId(const char *const src) SBE_NOEXCEPT
        {
            std::memcpy(m_buffer + m_offset + 121, src, sizeof(char) * 64);
            return *this;
        }

        SBE_NODISCARD std::string getMakerOrderIdAsString() const
        {
            const char *buffer = m_buffer + m_offset + 121;
            std::size_t length = 0;

            for (; length < 64 && *(buffer + length) != '\0'; ++length);
            std::string result(buffer, length);

            return result;
        }

        std::string getMakerOrderIdAsJsonEscapedString()
        {
            std::ostringstream oss;
            std::string s = getMakerOrderIdAsString();

            for (const auto c : s)
            {
                switch (c)
                {
                    case '"': oss << "\\\""; break;
                    case '\\': oss << "\\\\"; break;
                    case '\b': oss << "\\b"; break;
                    case '\f': oss << "\\f"; break;
                    case '\n': oss << "\\n"; break;
                    case '\r': oss << "\\r"; break;
                    case '\t': oss << "\\t"; break;

                    default:
                        if ('\x00' <= c && c <= '\x1f')
                        {
                            oss << "\\u" << std::hex << std::setw(4)
                                << std::setfill('0') << (int)(c);
                        }
                        else
                        {
                            oss << c;
                        }
                }
            }

            return oss.str();
        }

        #if __cplusplus >= 201703L
        SBE_NODISCARD std::string_view getMakerOrderIdAsStringView() const SBE_NOEXCEPT
        {
            const char *buffer = m_buffer + m_offset + 121;
            std::size_t length = 0;

            for (; length < 64 && *(buffer + length) != '\0'; ++length);
            std::string_view result(buffer, length);

            return result;
        }
        #endif

        #if __cplusplus >= 201703L
        Trades &putMakerOrderId(const std::string_view str)
        {
            const std::size_t srcLength = str.length();
            if (srcLength > 64)
            {
                throw std::runtime_error("string too large for putMakerOrderId [E106]");
            }

            std::memcpy(m_buffer + m_offset + 121, str.data(), srcLength);
            for (std::size_t start = srcLength; start < 64; ++start)
            {
                m_buffer[m_offset + 121 + start] = 0;
            }

            return *this;
        }
        #else
        Trades &putMakerOrderId(const std::string &str)
        {
            const std::size_t srcLength = str.length();
            if (srcLength > 64)
            {
                throw std::runtime_error("string too large for putMakerOrderId [E106]");
            }

            std::memcpy(m_buffer + m_offset + 121, str.c_str(), srcLength);
            for (std::size_t start = srcLength; start < 64; ++start)
            {
                m_buffer[m_offset + 121 + start] = 0;
            }

            return *this;
        }
        #endif

        template<typename CharT, typename Traits>
        friend std::basic_ostream<CharT, Traits> & operator << (
            std::basic_ostream<CharT, Traits> &builder, Trades &writer)
        {
            builder << '{';
            builder << R"("side": )";
            builder << '"' << writer.side() << '"';

            builder << ", ";
            builder << R"("price": )";
            builder << +writer.price();

            builder << ", ";
            builder << R"("quantity": )";
            builder << +writer.quantity();

            builder << ", ";
            builder << R"("tradeId": )";
            builder << '"' <<
                writer.getTradeIdAsJsonEscapedString().c_str() << '"';

            builder << ", ";
            builder << R"("takerOrderId": )";
            builder << '"' <<
                writer.getTakerOrderIdAsJsonEscapedString().c_str() << '"';

            builder << ", ";
            builder << R"("makerOrderId": )";
            builder << '"' <<
                writer.getMakerOrderIdAsJsonEscapedString().c_str() << '"';

            builder << '}';

            return builder;
        }

        void skip()
        {
        }

        SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
        {
            return true;
        }

        SBE_NODISCARD static std::size_t computeLength()
        {
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
            std::size_t length = sbeBlockLength();

            return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
        }
    };

private:
    Trades m_trades;

public:
    SBE_NODISCARD static SBE_CONSTEXPR std::uint16_t tradesId() SBE_NOEXCEPT
    {
        return 300;
    }

    SBE_NODISCARD inline Trades &trades()
    {
        m_trades.wrapForDecode(m_buffer, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_trades;
    }

    Trades &tradesCount(const std::uint16_t count)
    {
        m_trades.wrapForEncode(m_buffer, count, sbePositionPtr(), m_actingVersion, m_bufferLength);
        return m_trades;
    }

    SBE_NODISCARD static SBE_CONSTEXPR std::uint64_t tradesSinceVersion() SBE_NOEXCEPT
    {
        return 0;
    }

    SBE_NODISCARD bool tradesInActingVersion() const SBE_NOEXCEPT
    {
        return true;
    }

template<typename CharT, typename Traits>
friend std::basic_ostream<CharT, Traits> & operator << (
    std::basic_ostream<CharT, Traits> &builder, const TradeSummary &_writer)
{
    TradeSummary writer(
        _writer.m_buffer,
        _writer.m_offset,
        _writer.m_bufferLength,
        _writer.m_actingBlockLength,
        _writer.m_actingVersion);

    builder << '{';
    builder << R"("Name": "TradeSummary", )";
    builder << R"("sbeTemplateId": )";
    builder << writer.sbeTemplateId();
    builder << ", ";

    builder << R"("sourceName": )";
    builder << '"' <<
        writer.getSourceNameAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("sourceSessionID": )";
    builder << '[';
    for (std::size_t i = 0, length = writer.sourceSessionIDLength(); i < length; i++)
    {
        if (i)
        {
            builder << ',';
        }
        builder << +writer.sourceSessionID(i);
    }
    builder << ']';

    builder << ", ";
    builder << R"("sourceSeqNo": )";
    builder << +writer.sourceSeqNo();

    builder << ", ";
    builder << R"("originCreateTimeUTC": )";
    builder << +writer.originCreateTimeUTC();

    builder << ", ";
    builder << R"("exchange": )";
    builder << '"' <<
        writer.getExchangeAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("symbol": )";
    builder << '"' <<
        writer.getSymbolAsJsonEscapedString().c_str() << '"';

    builder << ", ";
    builder << R"("exchangeTimeUTC": )";
    builder << +writer.exchangeTimeUTC();

    builder << ", ";
    builder << R"("exchangeSequence": )";
    builder << +writer.exchangeSequence();

    builder << ", ";
    builder << R"("sendingTimeUTC": )";
    builder << +writer.sendingTimeUTC();

    builder << ", ";
    {
        bool atLeastOne = false;
        builder << R"("trades": [)";
        writer.trades().forEach(
            [&](Trades &trades)
            {
                if (atLeastOne)
                {
                    builder << ", ";
                }
                atLeastOne = true;
                builder << trades;
            });
        builder << ']';
    }

    builder << '}';

    return builder;
}

void skip()
{
    auto &tradesGroup { trades() };
    while (tradesGroup.hasNext())
    {
        tradesGroup.next().skip();
    }
}

SBE_NODISCARD static SBE_CONSTEXPR bool isConstLength() SBE_NOEXCEPT
{
    return false;
}

SBE_NODISCARD static std::size_t computeLength(std::size_t tradesLength = 0)
{
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
#endif
    std::size_t length = sbeBlockLength();

    length += Trades::sbeHeaderSize();
    if (tradesLength > 65534LL)
    {
        throw std::runtime_error("tradesLength outside of allowed range [E110]");
    }
    length += tradesLength *Trades::sbeBlockLength();

    return length;
#if defined(__GNUG__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
}
};
}
#endif
