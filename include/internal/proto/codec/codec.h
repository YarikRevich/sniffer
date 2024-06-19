#ifndef SNIFFER_CODEC_H
#define SNIFFER_CODEC_H

#include "internal/proto/buffer/response/response.h"
#include "internal/proto/generated/data.h"
#include "internal/core/core.h"

/**
 * Represents codec used to decompose and composite response.
 */
class Codec {
public:
    /**
     * Retrieves common response buffer instance.
     *
     * @return common instance of response buffer.
     */
    static ResponseBuffer* get_response_buffer();

    /**
     * Performs response encoding operation.
     *
     * @param content - given response content.
     * @return status of the encode operation.
     */
    static int encode_response_content(const sniffer::DataBusContent<SSID_MAX_SIZE>& content);
private:
    /**
     * Represents common instance of response buffer.
     */
    static ResponseBuffer response_buffer;
};

#endif //SNIFFER_CODEC_H
