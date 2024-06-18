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
#include "esp_event.h"

#include "md5.h"

#define SSID_MAX_SIZE (32+1)
#define MD5_SIZE (32+1)

/* TAG of ESP32 for I/O operation */
static const char *TAG = "ETS";

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
    static void hello();

private:
    /**
     * Composes hash from the raw data.
     *
     * @param src - given raw data.
     * @param size - given size of raw data.
     * @return composed hash.
     */
    static char* get_hash(unsigned char *src, int size);

    /**
     * Composes ssid from the raw data.
     *
     * @param src - given raw data.
     * @param size - given size of raw data.
     * @return composed ssid.
     */
    static char* get_ssid(unsigned char *src, uint8_t size);

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
