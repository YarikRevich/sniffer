#ifndef SNIFFER_HANDLER_H
#define SNIFFER_HANDLER_H

#include "internal/proto/buffer/response/response.h"
#include "internal/proto/generated/data.h"
#include "internal/proto/codec/codec.h"

#include "driver/uart.h"

/**
 * Represents exposed handlers.
 */
class Handler {
public:
    /**
     * Transmits data bus content response.
     *
     * @return status of the operation.
     */
    static int transmit_data_bus_content_response(char* ssid);
};

#endif //SNIFFER_HANDLER_H
