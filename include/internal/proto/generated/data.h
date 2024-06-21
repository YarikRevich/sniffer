/*
 *  This file is generated with Embedded Proto, PLEASE DO NOT EDIT!
 *  source: data.proto
 */

// This file is generated. Please do not edit!
#ifndef DATA_H
#define DATA_H

#include <cstdint>
#include <MessageInterface.h>
#include <WireFormatter.h>
#include <Fields.h>
#include <MessageSizeCalculator.h>
#include <ReadBufferSection.h>
#include <RepeatedFieldFixedSize.h>
#include <FieldStringBytes.h>
#include <Errors.h>
#include <Defines.h>
#include <limits>

// Include external proto definitions

namespace sniffer {

class HT final: public ::EmbeddedProto::MessageInterface
{
  public:
    HT() = default;
    HT(const HT& rhs )
    {
      set_first(rhs.get_first());
      set_second(rhs.get_second());
      set_third(rhs.get_third());
      set_forth(rhs.get_forth());
      set_fifth(rhs.get_fifth());
    }

    HT(const HT&& rhs ) noexcept
    {
      set_first(rhs.get_first());
      set_second(rhs.get_second());
      set_third(rhs.get_third());
      set_forth(rhs.get_forth());
      set_fifth(rhs.get_fifth());
    }

    ~HT() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      FIRST = 1,
      SECOND = 2,
      THIRD = 3,
      FORTH = 4,
      FIFTH = 5
    };

    HT& operator=(const HT& rhs)
    {
      set_first(rhs.get_first());
      set_second(rhs.get_second());
      set_third(rhs.get_third());
      set_forth(rhs.get_forth());
      set_fifth(rhs.get_fifth());
      return *this;
    }

    HT& operator=(const HT&& rhs) noexcept
    {
      set_first(rhs.get_first());
      set_second(rhs.get_second());
      set_third(rhs.get_third());
      set_forth(rhs.get_forth());
      set_fifth(rhs.get_fifth());
      return *this;
    }

    static constexpr char const* FIRST_NAME = "first";
    inline void clear_first() { first_.clear(); }
    inline void set_first(const int32_t& value) { first_ = value; }
    inline void set_first(const int32_t&& value) { first_ = value; }
    inline int32_t& mutable_first() { return first_.get(); }
    inline const int32_t& get_first() const { return first_.get(); }
    inline int32_t first() const { return first_.get(); }

    static constexpr char const* SECOND_NAME = "second";
    inline void clear_second() { second_.clear(); }
    inline void set_second(const int32_t& value) { second_ = value; }
    inline void set_second(const int32_t&& value) { second_ = value; }
    inline int32_t& mutable_second() { return second_.get(); }
    inline const int32_t& get_second() const { return second_.get(); }
    inline int32_t second() const { return second_.get(); }

    static constexpr char const* THIRD_NAME = "third";
    inline void clear_third() { third_.clear(); }
    inline void set_third(const int32_t& value) { third_ = value; }
    inline void set_third(const int32_t&& value) { third_ = value; }
    inline int32_t& mutable_third() { return third_.get(); }
    inline const int32_t& get_third() const { return third_.get(); }
    inline int32_t third() const { return third_.get(); }

    static constexpr char const* FORTH_NAME = "forth";
    inline void clear_forth() { forth_.clear(); }
    inline void set_forth(const int32_t& value) { forth_ = value; }
    inline void set_forth(const int32_t&& value) { forth_ = value; }
    inline int32_t& mutable_forth() { return forth_.get(); }
    inline const int32_t& get_forth() const { return forth_.get(); }
    inline int32_t forth() const { return forth_.get(); }

    static constexpr char const* FIFTH_NAME = "fifth";
    inline void clear_fifth() { fifth_.clear(); }
    inline void set_fifth(const int32_t& value) { fifth_ = value; }
    inline void set_fifth(const int32_t&& value) { fifth_ = value; }
    inline int32_t& mutable_fifth() { return fifth_.get(); }
    inline const int32_t& get_fifth() const { return fifth_.get(); }
    inline int32_t fifth() const { return fifth_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != first_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = first_.serialize_with_id(static_cast<uint32_t>(FieldNumber::FIRST), buffer, false);
      }

      if((0 != second_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = second_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SECOND), buffer, false);
      }

      if((0 != third_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = third_.serialize_with_id(static_cast<uint32_t>(FieldNumber::THIRD), buffer, false);
      }

      if((0 != forth_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = forth_.serialize_with_id(static_cast<uint32_t>(FieldNumber::FORTH), buffer, false);
      }

      if((0 != fifth_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = fifth_.serialize_with_id(static_cast<uint32_t>(FieldNumber::FIFTH), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::FIRST:
            return_value = first_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SECOND:
            return_value = second_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::THIRD:
            return_value = third_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::FORTH:
            return_value = forth_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::FIFTH:
            return_value = fifth_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_first();
      clear_second();
      clear_third();
      clear_forth();
      clear_fifth();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::FIRST:
          name = FIRST_NAME;
          break;
        case FieldNumber::SECOND:
          name = SECOND_NAME;
          break;
        case FieldNumber::THIRD:
          name = THIRD_NAME;
          break;
        case FieldNumber::FORTH:
          name = FORTH_NAME;
          break;
        case FieldNumber::FIFTH:
          name = FIFTH_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = first_.to_string(left_chars, indent_level + 2, FIRST_NAME, true);
      left_chars = second_.to_string(left_chars, indent_level + 2, SECOND_NAME, false);
      left_chars = third_.to_string(left_chars, indent_level + 2, THIRD_NAME, false);
      left_chars = forth_.to_string(left_chars, indent_level + 2, FORTH_NAME, false);
      left_chars = fifth_.to_string(left_chars, indent_level + 2, FIFTH_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 first_ = 0;
      EmbeddedProto::int32 second_ = 0;
      EmbeddedProto::int32 third_ = 0;
      EmbeddedProto::int32 forth_ = 0;
      EmbeddedProto::int32 fifth_ = 0;

};

class Receiver final: public ::EmbeddedProto::MessageInterface
{
  public:
    Receiver() = default;
    Receiver(const Receiver& rhs )
    {
      set_first(rhs.get_first());
      set_second(rhs.get_second());
      set_third(rhs.get_third());
      set_forth(rhs.get_forth());
      set_fifth(rhs.get_fifth());
      set_sixth(rhs.get_sixth());
    }

    Receiver(const Receiver&& rhs ) noexcept
    {
      set_first(rhs.get_first());
      set_second(rhs.get_second());
      set_third(rhs.get_third());
      set_forth(rhs.get_forth());
      set_fifth(rhs.get_fifth());
      set_sixth(rhs.get_sixth());
    }

    ~Receiver() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      FIRST = 1,
      SECOND = 2,
      THIRD = 3,
      FORTH = 4,
      FIFTH = 5,
      SIXTH = 6
    };

    Receiver& operator=(const Receiver& rhs)
    {
      set_first(rhs.get_first());
      set_second(rhs.get_second());
      set_third(rhs.get_third());
      set_forth(rhs.get_forth());
      set_fifth(rhs.get_fifth());
      set_sixth(rhs.get_sixth());
      return *this;
    }

    Receiver& operator=(const Receiver&& rhs) noexcept
    {
      set_first(rhs.get_first());
      set_second(rhs.get_second());
      set_third(rhs.get_third());
      set_forth(rhs.get_forth());
      set_fifth(rhs.get_fifth());
      set_sixth(rhs.get_sixth());
      return *this;
    }

    static constexpr char const* FIRST_NAME = "first";
    inline void clear_first() { first_.clear(); }
    inline void set_first(const int32_t& value) { first_ = value; }
    inline void set_first(const int32_t&& value) { first_ = value; }
    inline int32_t& mutable_first() { return first_.get(); }
    inline const int32_t& get_first() const { return first_.get(); }
    inline int32_t first() const { return first_.get(); }

    static constexpr char const* SECOND_NAME = "second";
    inline void clear_second() { second_.clear(); }
    inline void set_second(const int32_t& value) { second_ = value; }
    inline void set_second(const int32_t&& value) { second_ = value; }
    inline int32_t& mutable_second() { return second_.get(); }
    inline const int32_t& get_second() const { return second_.get(); }
    inline int32_t second() const { return second_.get(); }

    static constexpr char const* THIRD_NAME = "third";
    inline void clear_third() { third_.clear(); }
    inline void set_third(const int32_t& value) { third_ = value; }
    inline void set_third(const int32_t&& value) { third_ = value; }
    inline int32_t& mutable_third() { return third_.get(); }
    inline const int32_t& get_third() const { return third_.get(); }
    inline int32_t third() const { return third_.get(); }

    static constexpr char const* FORTH_NAME = "forth";
    inline void clear_forth() { forth_.clear(); }
    inline void set_forth(const int32_t& value) { forth_ = value; }
    inline void set_forth(const int32_t&& value) { forth_ = value; }
    inline int32_t& mutable_forth() { return forth_.get(); }
    inline const int32_t& get_forth() const { return forth_.get(); }
    inline int32_t forth() const { return forth_.get(); }

    static constexpr char const* FIFTH_NAME = "fifth";
    inline void clear_fifth() { fifth_.clear(); }
    inline void set_fifth(const int32_t& value) { fifth_ = value; }
    inline void set_fifth(const int32_t&& value) { fifth_ = value; }
    inline int32_t& mutable_fifth() { return fifth_.get(); }
    inline const int32_t& get_fifth() const { return fifth_.get(); }
    inline int32_t fifth() const { return fifth_.get(); }

    static constexpr char const* SIXTH_NAME = "sixth";
    inline void clear_sixth() { sixth_.clear(); }
    inline void set_sixth(const int32_t& value) { sixth_ = value; }
    inline void set_sixth(const int32_t&& value) { sixth_ = value; }
    inline int32_t& mutable_sixth() { return sixth_.get(); }
    inline const int32_t& get_sixth() const { return sixth_.get(); }
    inline int32_t sixth() const { return sixth_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != first_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = first_.serialize_with_id(static_cast<uint32_t>(FieldNumber::FIRST), buffer, false);
      }

      if((0 != second_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = second_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SECOND), buffer, false);
      }

      if((0 != third_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = third_.serialize_with_id(static_cast<uint32_t>(FieldNumber::THIRD), buffer, false);
      }

      if((0 != forth_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = forth_.serialize_with_id(static_cast<uint32_t>(FieldNumber::FORTH), buffer, false);
      }

      if((0 != fifth_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = fifth_.serialize_with_id(static_cast<uint32_t>(FieldNumber::FIFTH), buffer, false);
      }

      if((0 != sixth_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = sixth_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SIXTH), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::FIRST:
            return_value = first_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SECOND:
            return_value = second_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::THIRD:
            return_value = third_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::FORTH:
            return_value = forth_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::FIFTH:
            return_value = fifth_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SIXTH:
            return_value = sixth_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_first();
      clear_second();
      clear_third();
      clear_forth();
      clear_fifth();
      clear_sixth();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::FIRST:
          name = FIRST_NAME;
          break;
        case FieldNumber::SECOND:
          name = SECOND_NAME;
          break;
        case FieldNumber::THIRD:
          name = THIRD_NAME;
          break;
        case FieldNumber::FORTH:
          name = FORTH_NAME;
          break;
        case FieldNumber::FIFTH:
          name = FIFTH_NAME;
          break;
        case FieldNumber::SIXTH:
          name = SIXTH_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = first_.to_string(left_chars, indent_level + 2, FIRST_NAME, true);
      left_chars = second_.to_string(left_chars, indent_level + 2, SECOND_NAME, false);
      left_chars = third_.to_string(left_chars, indent_level + 2, THIRD_NAME, false);
      left_chars = forth_.to_string(left_chars, indent_level + 2, FORTH_NAME, false);
      left_chars = fifth_.to_string(left_chars, indent_level + 2, FIFTH_NAME, false);
      left_chars = sixth_.to_string(left_chars, indent_level + 2, SIXTH_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 first_ = 0;
      EmbeddedProto::int32 second_ = 0;
      EmbeddedProto::int32 third_ = 0;
      EmbeddedProto::int32 forth_ = 0;
      EmbeddedProto::int32 fifth_ = 0;
      EmbeddedProto::int32 sixth_ = 0;

};

class SSID final: public ::EmbeddedProto::MessageInterface
{
  public:
    SSID() = default;
    SSID(const SSID& rhs )
    {
      set_first(rhs.get_first());
      set_second(rhs.get_second());
      set_third(rhs.get_third());
      set_forth(rhs.get_forth());
      set_fifth(rhs.get_fifth());
      set_sixth(rhs.get_sixth());
    }

    SSID(const SSID&& rhs ) noexcept
    {
      set_first(rhs.get_first());
      set_second(rhs.get_second());
      set_third(rhs.get_third());
      set_forth(rhs.get_forth());
      set_fifth(rhs.get_fifth());
      set_sixth(rhs.get_sixth());
    }

    ~SSID() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      FIRST = 1,
      SECOND = 2,
      THIRD = 3,
      FORTH = 4,
      FIFTH = 5,
      SIXTH = 6
    };

    SSID& operator=(const SSID& rhs)
    {
      set_first(rhs.get_first());
      set_second(rhs.get_second());
      set_third(rhs.get_third());
      set_forth(rhs.get_forth());
      set_fifth(rhs.get_fifth());
      set_sixth(rhs.get_sixth());
      return *this;
    }

    SSID& operator=(const SSID&& rhs) noexcept
    {
      set_first(rhs.get_first());
      set_second(rhs.get_second());
      set_third(rhs.get_third());
      set_forth(rhs.get_forth());
      set_fifth(rhs.get_fifth());
      set_sixth(rhs.get_sixth());
      return *this;
    }

    static constexpr char const* FIRST_NAME = "first";
    inline void clear_first() { first_.clear(); }
    inline void set_first(const int32_t& value) { first_ = value; }
    inline void set_first(const int32_t&& value) { first_ = value; }
    inline int32_t& mutable_first() { return first_.get(); }
    inline const int32_t& get_first() const { return first_.get(); }
    inline int32_t first() const { return first_.get(); }

    static constexpr char const* SECOND_NAME = "second";
    inline void clear_second() { second_.clear(); }
    inline void set_second(const int32_t& value) { second_ = value; }
    inline void set_second(const int32_t&& value) { second_ = value; }
    inline int32_t& mutable_second() { return second_.get(); }
    inline const int32_t& get_second() const { return second_.get(); }
    inline int32_t second() const { return second_.get(); }

    static constexpr char const* THIRD_NAME = "third";
    inline void clear_third() { third_.clear(); }
    inline void set_third(const int32_t& value) { third_ = value; }
    inline void set_third(const int32_t&& value) { third_ = value; }
    inline int32_t& mutable_third() { return third_.get(); }
    inline const int32_t& get_third() const { return third_.get(); }
    inline int32_t third() const { return third_.get(); }

    static constexpr char const* FORTH_NAME = "forth";
    inline void clear_forth() { forth_.clear(); }
    inline void set_forth(const int32_t& value) { forth_ = value; }
    inline void set_forth(const int32_t&& value) { forth_ = value; }
    inline int32_t& mutable_forth() { return forth_.get(); }
    inline const int32_t& get_forth() const { return forth_.get(); }
    inline int32_t forth() const { return forth_.get(); }

    static constexpr char const* FIFTH_NAME = "fifth";
    inline void clear_fifth() { fifth_.clear(); }
    inline void set_fifth(const int32_t& value) { fifth_ = value; }
    inline void set_fifth(const int32_t&& value) { fifth_ = value; }
    inline int32_t& mutable_fifth() { return fifth_.get(); }
    inline const int32_t& get_fifth() const { return fifth_.get(); }
    inline int32_t fifth() const { return fifth_.get(); }

    static constexpr char const* SIXTH_NAME = "sixth";
    inline void clear_sixth() { sixth_.clear(); }
    inline void set_sixth(const int32_t& value) { sixth_ = value; }
    inline void set_sixth(const int32_t&& value) { sixth_ = value; }
    inline int32_t& mutable_sixth() { return sixth_.get(); }
    inline const int32_t& get_sixth() const { return sixth_.get(); }
    inline int32_t sixth() const { return sixth_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != first_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = first_.serialize_with_id(static_cast<uint32_t>(FieldNumber::FIRST), buffer, false);
      }

      if((0 != second_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = second_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SECOND), buffer, false);
      }

      if((0 != third_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = third_.serialize_with_id(static_cast<uint32_t>(FieldNumber::THIRD), buffer, false);
      }

      if((0 != forth_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = forth_.serialize_with_id(static_cast<uint32_t>(FieldNumber::FORTH), buffer, false);
      }

      if((0 != fifth_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = fifth_.serialize_with_id(static_cast<uint32_t>(FieldNumber::FIFTH), buffer, false);
      }

      if((0 != sixth_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = sixth_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SIXTH), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::FIRST:
            return_value = first_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SECOND:
            return_value = second_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::THIRD:
            return_value = third_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::FORTH:
            return_value = forth_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::FIFTH:
            return_value = fifth_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SIXTH:
            return_value = sixth_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_first();
      clear_second();
      clear_third();
      clear_forth();
      clear_fifth();
      clear_sixth();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::FIRST:
          name = FIRST_NAME;
          break;
        case FieldNumber::SECOND:
          name = SECOND_NAME;
          break;
        case FieldNumber::THIRD:
          name = THIRD_NAME;
          break;
        case FieldNumber::FORTH:
          name = FORTH_NAME;
          break;
        case FieldNumber::FIFTH:
          name = FIFTH_NAME;
          break;
        case FieldNumber::SIXTH:
          name = SIXTH_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = first_.to_string(left_chars, indent_level + 2, FIRST_NAME, true);
      left_chars = second_.to_string(left_chars, indent_level + 2, SECOND_NAME, false);
      left_chars = third_.to_string(left_chars, indent_level + 2, THIRD_NAME, false);
      left_chars = forth_.to_string(left_chars, indent_level + 2, FORTH_NAME, false);
      left_chars = fifth_.to_string(left_chars, indent_level + 2, FIFTH_NAME, false);
      left_chars = sixth_.to_string(left_chars, indent_level + 2, SIXTH_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 first_ = 0;
      EmbeddedProto::int32 second_ = 0;
      EmbeddedProto::int32 third_ = 0;
      EmbeddedProto::int32 forth_ = 0;
      EmbeddedProto::int32 fifth_ = 0;
      EmbeddedProto::int32 sixth_ = 0;

};

class Sender final: public ::EmbeddedProto::MessageInterface
{
  public:
    Sender() = default;
    Sender(const Sender& rhs )
    {
      set_first(rhs.get_first());
      set_second(rhs.get_second());
      set_third(rhs.get_third());
      set_forth(rhs.get_forth());
      set_fifth(rhs.get_fifth());
      set_sixth(rhs.get_sixth());
    }

    Sender(const Sender&& rhs ) noexcept
    {
      set_first(rhs.get_first());
      set_second(rhs.get_second());
      set_third(rhs.get_third());
      set_forth(rhs.get_forth());
      set_fifth(rhs.get_fifth());
      set_sixth(rhs.get_sixth());
    }

    ~Sender() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      FIRST = 1,
      SECOND = 2,
      THIRD = 3,
      FORTH = 4,
      FIFTH = 5,
      SIXTH = 6
    };

    Sender& operator=(const Sender& rhs)
    {
      set_first(rhs.get_first());
      set_second(rhs.get_second());
      set_third(rhs.get_third());
      set_forth(rhs.get_forth());
      set_fifth(rhs.get_fifth());
      set_sixth(rhs.get_sixth());
      return *this;
    }

    Sender& operator=(const Sender&& rhs) noexcept
    {
      set_first(rhs.get_first());
      set_second(rhs.get_second());
      set_third(rhs.get_third());
      set_forth(rhs.get_forth());
      set_fifth(rhs.get_fifth());
      set_sixth(rhs.get_sixth());
      return *this;
    }

    static constexpr char const* FIRST_NAME = "first";
    inline void clear_first() { first_.clear(); }
    inline void set_first(const int32_t& value) { first_ = value; }
    inline void set_first(const int32_t&& value) { first_ = value; }
    inline int32_t& mutable_first() { return first_.get(); }
    inline const int32_t& get_first() const { return first_.get(); }
    inline int32_t first() const { return first_.get(); }

    static constexpr char const* SECOND_NAME = "second";
    inline void clear_second() { second_.clear(); }
    inline void set_second(const int32_t& value) { second_ = value; }
    inline void set_second(const int32_t&& value) { second_ = value; }
    inline int32_t& mutable_second() { return second_.get(); }
    inline const int32_t& get_second() const { return second_.get(); }
    inline int32_t second() const { return second_.get(); }

    static constexpr char const* THIRD_NAME = "third";
    inline void clear_third() { third_.clear(); }
    inline void set_third(const int32_t& value) { third_ = value; }
    inline void set_third(const int32_t&& value) { third_ = value; }
    inline int32_t& mutable_third() { return third_.get(); }
    inline const int32_t& get_third() const { return third_.get(); }
    inline int32_t third() const { return third_.get(); }

    static constexpr char const* FORTH_NAME = "forth";
    inline void clear_forth() { forth_.clear(); }
    inline void set_forth(const int32_t& value) { forth_ = value; }
    inline void set_forth(const int32_t&& value) { forth_ = value; }
    inline int32_t& mutable_forth() { return forth_.get(); }
    inline const int32_t& get_forth() const { return forth_.get(); }
    inline int32_t forth() const { return forth_.get(); }

    static constexpr char const* FIFTH_NAME = "fifth";
    inline void clear_fifth() { fifth_.clear(); }
    inline void set_fifth(const int32_t& value) { fifth_ = value; }
    inline void set_fifth(const int32_t&& value) { fifth_ = value; }
    inline int32_t& mutable_fifth() { return fifth_.get(); }
    inline const int32_t& get_fifth() const { return fifth_.get(); }
    inline int32_t fifth() const { return fifth_.get(); }

    static constexpr char const* SIXTH_NAME = "sixth";
    inline void clear_sixth() { sixth_.clear(); }
    inline void set_sixth(const int32_t& value) { sixth_ = value; }
    inline void set_sixth(const int32_t&& value) { sixth_ = value; }
    inline int32_t& mutable_sixth() { return sixth_.get(); }
    inline const int32_t& get_sixth() const { return sixth_.get(); }
    inline int32_t sixth() const { return sixth_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0 != first_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = first_.serialize_with_id(static_cast<uint32_t>(FieldNumber::FIRST), buffer, false);
      }

      if((0 != second_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = second_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SECOND), buffer, false);
      }

      if((0 != third_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = third_.serialize_with_id(static_cast<uint32_t>(FieldNumber::THIRD), buffer, false);
      }

      if((0 != forth_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = forth_.serialize_with_id(static_cast<uint32_t>(FieldNumber::FORTH), buffer, false);
      }

      if((0 != fifth_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = fifth_.serialize_with_id(static_cast<uint32_t>(FieldNumber::FIFTH), buffer, false);
      }

      if((0 != sixth_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = sixth_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SIXTH), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::FIRST:
            return_value = first_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SECOND:
            return_value = second_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::THIRD:
            return_value = third_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::FORTH:
            return_value = forth_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::FIFTH:
            return_value = fifth_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SIXTH:
            return_value = sixth_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_first();
      clear_second();
      clear_third();
      clear_forth();
      clear_fifth();
      clear_sixth();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::FIRST:
          name = FIRST_NAME;
          break;
        case FieldNumber::SECOND:
          name = SECOND_NAME;
          break;
        case FieldNumber::THIRD:
          name = THIRD_NAME;
          break;
        case FieldNumber::FORTH:
          name = FORTH_NAME;
          break;
        case FieldNumber::FIFTH:
          name = FIFTH_NAME;
          break;
        case FieldNumber::SIXTH:
          name = SIXTH_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = first_.to_string(left_chars, indent_level + 2, FIRST_NAME, true);
      left_chars = second_.to_string(left_chars, indent_level + 2, SECOND_NAME, false);
      left_chars = third_.to_string(left_chars, indent_level + 2, THIRD_NAME, false);
      left_chars = forth_.to_string(left_chars, indent_level + 2, FORTH_NAME, false);
      left_chars = fifth_.to_string(left_chars, indent_level + 2, FIFTH_NAME, false);
      left_chars = sixth_.to_string(left_chars, indent_level + 2, SIXTH_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::int32 first_ = 0;
      EmbeddedProto::int32 second_ = 0;
      EmbeddedProto::int32 third_ = 0;
      EmbeddedProto::int32 forth_ = 0;
      EmbeddedProto::int32 fifth_ = 0;
      EmbeddedProto::int32 sixth_ = 0;

};

class DataBusContent final: public ::EmbeddedProto::MessageInterface
{
  public:
    DataBusContent() = default;
    DataBusContent(const DataBusContent& rhs )
    {
      set_ssid(rhs.get_ssid());
      set_sender(rhs.get_sender());
      set_receiver(rhs.get_receiver());
      set_ht(rhs.get_ht());
      set_type(rhs.get_type());
      set_amplification(rhs.get_amplification());
      set_sequence(rhs.get_sequence());
    }

    DataBusContent(const DataBusContent&& rhs ) noexcept
    {
      set_ssid(rhs.get_ssid());
      set_sender(rhs.get_sender());
      set_receiver(rhs.get_receiver());
      set_ht(rhs.get_ht());
      set_type(rhs.get_type());
      set_amplification(rhs.get_amplification());
      set_sequence(rhs.get_sequence());
    }

    ~DataBusContent() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      SSID = 1,
      SENDER = 2,
      RECEIVER = 3,
      HT = 4,
      TYPE = 5,
      AMPLIFICATION = 6,
      SEQUENCE = 7
    };

    DataBusContent& operator=(const DataBusContent& rhs)
    {
      set_ssid(rhs.get_ssid());
      set_sender(rhs.get_sender());
      set_receiver(rhs.get_receiver());
      set_ht(rhs.get_ht());
      set_type(rhs.get_type());
      set_amplification(rhs.get_amplification());
      set_sequence(rhs.get_sequence());
      return *this;
    }

    DataBusContent& operator=(const DataBusContent&& rhs) noexcept
    {
      set_ssid(rhs.get_ssid());
      set_sender(rhs.get_sender());
      set_receiver(rhs.get_receiver());
      set_ht(rhs.get_ht());
      set_type(rhs.get_type());
      set_amplification(rhs.get_amplification());
      set_sequence(rhs.get_sequence());
      return *this;
    }

    static constexpr char const* SSID_NAME = "ssid";
    inline void clear_ssid() { ssid_.clear(); }
    inline void set_ssid(const SSID& value) { ssid_ = value; }
    inline void set_ssid(const SSID&& value) { ssid_ = value; }
    inline SSID& mutable_ssid() { return ssid_; }
    inline const SSID& get_ssid() const { return ssid_; }
    inline const SSID& ssid() const { return ssid_; }

    static constexpr char const* SENDER_NAME = "sender";
    inline void clear_sender() { sender_.clear(); }
    inline void set_sender(const Sender& value) { sender_ = value; }
    inline void set_sender(const Sender&& value) { sender_ = value; }
    inline Sender& mutable_sender() { return sender_; }
    inline const Sender& get_sender() const { return sender_; }
    inline const Sender& sender() const { return sender_; }

    static constexpr char const* RECEIVER_NAME = "receiver";
    inline void clear_receiver() { receiver_.clear(); }
    inline void set_receiver(const Receiver& value) { receiver_ = value; }
    inline void set_receiver(const Receiver&& value) { receiver_ = value; }
    inline Receiver& mutable_receiver() { return receiver_; }
    inline const Receiver& get_receiver() const { return receiver_; }
    inline const Receiver& receiver() const { return receiver_; }

    static constexpr char const* HT_NAME = "ht";
    inline void clear_ht() { ht_.clear(); }
    inline void set_ht(const HT& value) { ht_ = value; }
    inline void set_ht(const HT&& value) { ht_ = value; }
    inline HT& mutable_ht() { return ht_; }
    inline const HT& get_ht() const { return ht_; }
    inline const HT& ht() const { return ht_; }

    static constexpr char const* TYPE_NAME = "type";
    inline void clear_type() { type_.clear(); }
    inline void set_type(const int32_t& value) { type_ = value; }
    inline void set_type(const int32_t&& value) { type_ = value; }
    inline int32_t& mutable_type() { return type_.get(); }
    inline const int32_t& get_type() const { return type_.get(); }
    inline int32_t type() const { return type_.get(); }

    static constexpr char const* AMPLIFICATION_NAME = "amplification";
    inline void clear_amplification() { amplification_.clear(); }
    inline void set_amplification(const int32_t& value) { amplification_ = value; }
    inline void set_amplification(const int32_t&& value) { amplification_ = value; }
    inline int32_t& mutable_amplification() { return amplification_.get(); }
    inline const int32_t& get_amplification() const { return amplification_.get(); }
    inline int32_t amplification() const { return amplification_.get(); }

    static constexpr char const* SEQUENCE_NAME = "sequence";
    inline void clear_sequence() { sequence_.clear(); }
    inline void set_sequence(const int32_t& value) { sequence_ = value; }
    inline void set_sequence(const int32_t&& value) { sequence_ = value; }
    inline int32_t& mutable_sequence() { return sequence_.get(); }
    inline const int32_t& get_sequence() const { return sequence_.get(); }
    inline int32_t sequence() const { return sequence_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = ssid_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SSID), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = sender_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SENDER), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = receiver_.serialize_with_id(static_cast<uint32_t>(FieldNumber::RECEIVER), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = ht_.serialize_with_id(static_cast<uint32_t>(FieldNumber::HT), buffer, false);
      }

      if((0 != type_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = type_.serialize_with_id(static_cast<uint32_t>(FieldNumber::TYPE), buffer, false);
      }

      if((0 != amplification_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = amplification_.serialize_with_id(static_cast<uint32_t>(FieldNumber::AMPLIFICATION), buffer, false);
      }

      if((0 != sequence_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = sequence_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SEQUENCE), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::SSID:
            return_value = ssid_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SENDER:
            return_value = sender_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::RECEIVER:
            return_value = receiver_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::HT:
            return_value = ht_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::TYPE:
            return_value = type_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::AMPLIFICATION:
            return_value = amplification_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SEQUENCE:
            return_value = sequence_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_ssid();
      clear_sender();
      clear_receiver();
      clear_ht();
      clear_type();
      clear_amplification();
      clear_sequence();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::SSID:
          name = SSID_NAME;
          break;
        case FieldNumber::SENDER:
          name = SENDER_NAME;
          break;
        case FieldNumber::RECEIVER:
          name = RECEIVER_NAME;
          break;
        case FieldNumber::HT:
          name = HT_NAME;
          break;
        case FieldNumber::TYPE:
          name = TYPE_NAME;
          break;
        case FieldNumber::AMPLIFICATION:
          name = AMPLIFICATION_NAME;
          break;
        case FieldNumber::SEQUENCE:
          name = SEQUENCE_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = ssid_.to_string(left_chars, indent_level + 2, SSID_NAME, true);
      left_chars = sender_.to_string(left_chars, indent_level + 2, SENDER_NAME, false);
      left_chars = receiver_.to_string(left_chars, indent_level + 2, RECEIVER_NAME, false);
      left_chars = ht_.to_string(left_chars, indent_level + 2, HT_NAME, false);
      left_chars = type_.to_string(left_chars, indent_level + 2, TYPE_NAME, false);
      left_chars = amplification_.to_string(left_chars, indent_level + 2, AMPLIFICATION_NAME, false);
      left_chars = sequence_.to_string(left_chars, indent_level + 2, SEQUENCE_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      SSID ssid_;
      Sender sender_;
      Receiver receiver_;
      HT ht_;
      EmbeddedProto::int32 type_ = 0;
      EmbeddedProto::int32 amplification_ = 0;
      EmbeddedProto::int32 sequence_ = 0;

};

} // End of namespace sniffer
#endif // DATA_H