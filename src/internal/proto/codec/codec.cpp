#include "internal/proto/codec/codec.h"

ResponseBuffer Codec::response_buffer = ResponseBuffer(400);

ResponseBuffer* Codec::get_response_buffer() {
    return &response_buffer;
}

int Codec::encode_response_content(const sniffer::DataBusContent& content) {
    if (content.serialize(response_buffer) == ::EmbeddedProto::Error::NO_ERRORS) {
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}