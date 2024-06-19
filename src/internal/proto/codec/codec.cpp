#include "internal/proto/codec/codec.h"

ResponseBuffer Codec::response_buffer = ResponseBuffer(100);

ResponseBuffer* Codec::get_response_buffer() {
    return &response_buffer;
}

int Codec::encode_response_content(const sniffer::DataBusContent<SSID_MAX_SIZE>& content) {
    if (content.serialize(response_buffer) == ::EmbeddedProto::Error::NO_ERRORS) {
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}