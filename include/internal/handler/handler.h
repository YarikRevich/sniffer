#ifndef SNIFFER_HANDLER_H
#define SNIFFER_HANDLER_H

#include "driver/uart.h"
#include "driver/gpio.h"

#include "internal/proto/buffer/response/response.h"
#include "internal/proto/generated/data.h"
#include "internal/indicator/indicator.h"
#include "internal/proto/codec/codec.h"

/**
 * Represents exposed handlers.
 */
class Handler {
public:
    /**
     * Transmits data bus content response.
     *
     * @param ssid - given source ssid.
     * @param sender - given sender of the message.
     * @param receiver - given receiver of the message.
     * @param ht - given ht source options.
     * @param type - given type of the message.
     * @param amplification - given source amplification.
     * @param sequence - given sequence of the message.
     */
    static void transmit_data_bus_content_response(
            uint8_t * ssid, uint8_t * sender, uint8_t * receiver, char* ht, int type, int amplification, int sequence);
};

#endif //SNIFFER_HANDLER_H
