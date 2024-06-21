#ifndef SNIFFER_INDICATOR_H
#define SNIFFER_INDICATOR_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

/**
 * Represents indicator state machine.
 */
class Indicator {
public:
    /**
     * Indicated initialization process success.
     */
    static void toggle_initialization_success();

    /**
     * Indicated initialization process failure.
     */
    static void toggle_initialization_failure();
};

#endif //SNIFFER_INDICATOR_H
