#ifndef SNIFFER_STATE_H
#define SNIFFER_STATE_H

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"

/**
 * Represents device state handler.
 */
class State {
public:
    /**
     * Retrieves WIFI event group.
     *
     * @return retrieved WIFI event group.
     */
    static EventGroupHandle_t* get_wifi_event_group();

private:
    /**
     * Represents WIFI event group.
     */
    static EventGroupHandle_t wifi_event_group;
};

#endif //SNIFFER_STATE_H
