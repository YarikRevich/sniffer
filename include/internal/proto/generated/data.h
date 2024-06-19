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

template<
    uint32_t DataBusContent_ssid_LENGTH, 
    uint32_t DataBusContent_receiver_LENGTH, 
    uint32_t DataBusContent_sender_LENGTH, 
    uint32_t DataBusContent_hp_LENGTH
>
class DataBusContent final: public ::EmbeddedProto::MessageInterface
{
  public:
    DataBusContent() = default;
    DataBusContent(const DataBusContent& rhs )
    {
      set_ssid(rhs.get_ssid());
      set_receiver(rhs.get_receiver());
      set_sender(rhs.get_sender());
      set_hp(rhs.get_hp());
      set_amplification(rhs.get_amplification());
      set_sequence(rhs.get_sequence());
    }

    DataBusContent(const DataBusContent&& rhs ) noexcept
    {
      set_ssid(rhs.get_ssid());
      set_receiver(rhs.get_receiver());
      set_sender(rhs.get_sender());
      set_hp(rhs.get_hp());
      set_amplification(rhs.get_amplification());
      set_sequence(rhs.get_sequence());
    }

    ~DataBusContent() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      SSID = 1,
      RECEIVER = 2,
      SENDER = 3,
      HP = 4,
      AMPLIFICATION = 5,
      SEQUENCE = 6
    };

    DataBusContent& operator=(const DataBusContent& rhs)
    {
      set_ssid(rhs.get_ssid());
      set_receiver(rhs.get_receiver());
      set_sender(rhs.get_sender());
      set_hp(rhs.get_hp());
      set_amplification(rhs.get_amplification());
      set_sequence(rhs.get_sequence());
      return *this;
    }

    DataBusContent& operator=(const DataBusContent&& rhs) noexcept
    {
      set_ssid(rhs.get_ssid());
      set_receiver(rhs.get_receiver());
      set_sender(rhs.get_sender());
      set_hp(rhs.get_hp());
      set_amplification(rhs.get_amplification());
      set_sequence(rhs.get_sequence());
      return *this;
    }

    static constexpr char const* SSID_NAME = "ssid";
    inline void clear_ssid() { ssid_.clear(); }
    inline ::EmbeddedProto::FieldString<DataBusContent_ssid_LENGTH>& mutable_ssid() { return ssid_; }
    inline void set_ssid(const ::EmbeddedProto::FieldString<DataBusContent_ssid_LENGTH>& rhs) { ssid_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<DataBusContent_ssid_LENGTH>& get_ssid() const { return ssid_; }
    inline const char* ssid() const { return ssid_.get_const(); }

    static constexpr char const* RECEIVER_NAME = "receiver";
    inline void clear_receiver() { receiver_.clear(); }
    inline ::EmbeddedProto::FieldString<DataBusContent_receiver_LENGTH>& mutable_receiver() { return receiver_; }
    inline void set_receiver(const ::EmbeddedProto::FieldString<DataBusContent_receiver_LENGTH>& rhs) { receiver_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<DataBusContent_receiver_LENGTH>& get_receiver() const { return receiver_; }
    inline const char* receiver() const { return receiver_.get_const(); }

    static constexpr char const* SENDER_NAME = "sender";
    inline void clear_sender() { sender_.clear(); }
    inline ::EmbeddedProto::FieldString<DataBusContent_sender_LENGTH>& mutable_sender() { return sender_; }
    inline void set_sender(const ::EmbeddedProto::FieldString<DataBusContent_sender_LENGTH>& rhs) { sender_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<DataBusContent_sender_LENGTH>& get_sender() const { return sender_; }
    inline const char* sender() const { return sender_.get_const(); }

    static constexpr char const* HP_NAME = "hp";
    inline void clear_hp() { hp_.clear(); }
    inline ::EmbeddedProto::FieldString<DataBusContent_hp_LENGTH>& mutable_hp() { return hp_; }
    inline void set_hp(const ::EmbeddedProto::FieldString<DataBusContent_hp_LENGTH>& rhs) { hp_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<DataBusContent_hp_LENGTH>& get_hp() const { return hp_; }
    inline const char* hp() const { return hp_.get_const(); }

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
        return_value = receiver_.serialize_with_id(static_cast<uint32_t>(FieldNumber::RECEIVER), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = sender_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SENDER), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = hp_.serialize_with_id(static_cast<uint32_t>(FieldNumber::HP), buffer, false);
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

          case FieldNumber::RECEIVER:
            return_value = receiver_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SENDER:
            return_value = sender_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::HP:
            return_value = hp_.deserialize_check_type(buffer, wire_type);
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
      clear_receiver();
      clear_sender();
      clear_hp();
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
        case FieldNumber::RECEIVER:
          name = RECEIVER_NAME;
          break;
        case FieldNumber::SENDER:
          name = SENDER_NAME;
          break;
        case FieldNumber::HP:
          name = HP_NAME;
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
      left_chars = receiver_.to_string(left_chars, indent_level + 2, RECEIVER_NAME, false);
      left_chars = sender_.to_string(left_chars, indent_level + 2, SENDER_NAME, false);
      left_chars = hp_.to_string(left_chars, indent_level + 2, HP_NAME, false);
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


      ::EmbeddedProto::FieldString<DataBusContent_ssid_LENGTH> ssid_;
      ::EmbeddedProto::FieldString<DataBusContent_receiver_LENGTH> receiver_;
      ::EmbeddedProto::FieldString<DataBusContent_sender_LENGTH> sender_;
      ::EmbeddedProto::FieldString<DataBusContent_hp_LENGTH> hp_;
      EmbeddedProto::int32 amplification_ = 0;
      EmbeddedProto::int32 sequence_ = 0;

};

} // End of namespace sniffer
#endif // DATA_H