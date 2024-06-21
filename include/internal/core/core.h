#ifndef SNIFFER_CORE_H
#define SNIFFER_CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include <stdint.h>
#include <stddef.h>

#include "esp_wifi.h"
#include "esp_wifi_types.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "esp32/rom/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "sdkconfig.h"


#include "internal/state/state.h"
#include "internal/handler/handler.h"
#include "internal/indicator/indicator.h"

#define SSID_SIZE (6)
#define HT_SIZE (5)

/* TAG of ESP32 for I/O operation */
static const char *TAG = "SNIFFER";

/**
 * Represents header used for WIFI message.
 */
typedef struct {
    int16_t fctl;
    int16_t duration;
    uint8_t receiver[6];
    uint8_t sender[6];
    uint8_t ssid[6];
    int16_t seqctl;
    unsigned char payload[];
} __attribute__((packed)) wifi_header;

/**
 * Represents core part of the application.
 */
class Core {
public:
    /**
     * Starts core logic of the application.
     */
    static void run();

private:
    /**
     * Enables WIFI module with additional packet handler.
     */
    static void enable();

    /**
     * Handles incoming WIFI data.
     *
     * @param buff - given raw data.
     * @param type - given data type.
     */
    static void handle_data(void *src, wifi_promiscuous_pkt_type_t type);

    /**
     * Handles incoming initial stage WIFI events.
     *
     * @param arg - given event type.
     * @param event_base - given event base.
     * @param event_id - given event identification.
     * @param event_data - given event raw data.
     */
    static void handle_init_stage_event(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data);

    /**
     * Retrieves sequence from the raw data.
     *
     * @param src - given raw data.
     * @return retrieved sequence.
     */
    static int get_sequence(unsigned char *src);

    /**
     * Composes ht from the raw data.
     *
     * @param src - given raw data.
     * @param packet_size - given raw packet size.
     * @param ssid_size - given raw ssid size.
     * @return composed ht.
     */
    static char* get_ht(unsigned char *src, int packet_size, int ssid_size);
};

#endif //SNIFFER_CORE_H
