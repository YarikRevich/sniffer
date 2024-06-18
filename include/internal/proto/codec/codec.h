#ifndef SNIFFER_CODEC_H
#define SNIFFER_CODEC_H

#include "data.h"
#include "response.h"

/**
 * Represents codec used to decompose and composite response.
 */
class ProtoCodec {
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
    static int encode_response(const light_detector::ResponseContainer& content);
private:
    /**
     * Represents common instance of response buffer.
     */
    static ResponseBuffer response_buffer;
};

#endif //SNIFFER_CODEC_H
