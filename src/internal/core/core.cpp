#include "internal/core/core.h"
#include "internal/state/state.h"
#include "internal/handler/handler.h"

//#include "driver/gpio.h"
//#include "sdkconfig.h"

//#include "esp_log.h"

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_log.h"

/**
 * This is an example which echos any data it receives on configured UART back to the sender,
 * with hardware flow control turned off. It does not use UART driver event queue.
 *
 * - Port: configured UART
 * - Receive (Rx) buffer: on
 * - Transmit (Tx) buffer: off
 * - Flow control: off
 * - Event queue: off
 * - Pin assignment: see defines below (See Kconfig)
 */

//#define ECHO_TEST_TXD (1)
//#define ECHO_TEST_RXD (3)
//#define ECHO_TEST_RTS (0)
//#define ECHO_TEST_CTS (0)
//
//#define ECHO_UART_PORT_NUM      (uart_port_t)(0)
//#define ECHO_UART_BAUD_RATE     (115200)
//#define ECHO_TASK_STACK_SIZE    (1024 * 2)

static const char *TAG = "EST";

#define BUF_SIZE (1024)

void Core::run() {
    enable();

    for (;;) {
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void Core::enable() {
    uart_config_t uart_config = {
            .baud_rate = 115200,
            .data_bits = UART_DATA_8_BITS,
            .parity    = UART_PARITY_DISABLE,
            .stop_bits = UART_STOP_BITS_1,
            .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
            .source_clk = UART_SCLK_DEFAULT,
    };
    int intr_alloc_flags = 0;

#if CONFIG_UART_ISR_IN_IRAM
    intr_alloc_flags = ESP_INTR_FLAG_IRAM;
#endif

    ESP_ERROR_CHECK(uart_driver_install((uart_port_t)(0), 1024 * 2, 0, 0, NULL, intr_alloc_flags));
    ESP_ERROR_CHECK(uart_param_config((uart_port_t)(0), &uart_config));
    ESP_ERROR_CHECK(uart_set_pin((uart_port_t)(0), 1, 3, 0, 0));

    esp_event_loop_create_default();

    nvs_flash_init();

    esp_netif_init();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);

    esp_wifi_set_storage(WIFI_STORAGE_RAM);
    esp_wifi_set_mode(WIFI_MODE_APSTA);

    wifi_config_t wifi_config = {
            .sta = {
                    .ssid = "503",
                    .password = "503a503b"
            },
    };

    esp_wifi_set_config(WIFI_IF_STA, &wifi_config);

    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &Core::handle_event, NULL);

    esp_wifi_start();

    xEventGroupWaitBits(*State::get_wifi_event_group(), BIT0, false, true, portMAX_DELAY);

    ESP_LOGE(TAG, "ITWORKS");

    cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);

    esp_wifi_set_storage(WIFI_STORAGE_RAM);
    esp_wifi_set_mode(WIFI_MODE_NULL);

    const wifi_country_t wifi_country = {
            .cc = CONFIG_WIFI_COUNTRY,
            .schan = 1,
            .nchan = 13,
            .policy = WIFI_COUNTRY_POLICY_AUTO
    };

    esp_wifi_set_country(&wifi_country);

    esp_wifi_start();

    const wifi_promiscuous_filter_t filter = {
            .filter_mask = WIFI_EVENT_MASK_AP_PROBEREQRECVED
    };

    esp_wifi_set_promiscuous_filter(&filter);
    esp_wifi_set_promiscuous_rx_cb(&Core::handle_data);
    esp_wifi_set_promiscuous(true);

    esp_wifi_set_channel(CONFIG_WIFI_CHANNEL, WIFI_SECOND_CHAN_NONE);

//    vTaskDelay(10000 / portTICK_PERIOD_MS);
//
//    ret = esp_wifi_connect();
//    if (ret != ESP_OK) {
//        ESP_LOGE(TAG, "WiFi connect failed! ret:%x", ret);
//    }
}


//
//static esp_err_t event_handler(void *ctx, system_event_t *event)
//{
//    switch(event->event_id){
//        case SYSTEM_EVENT_STA_START:
//            ESP_LOGI(TAG, "[WI-FI] Connecting to %s", CONFIG_WIFI_SSID);
//            ESP_ERROR_CHECK(esp_wifi_connect());
//            break;
//
//        case SYSTEM_EVENT_STA_GOT_IP: //wifi connected
//            ESP_LOGI(TAG, "[WI-FI] Connected");
//            WIFI_CONNECTED = true;
//            set_blink_led(ON_MODE);
//            xEventGroupSetBits(wifi_event_group, BIT0);
//            break;
//
//        case SYSTEM_EVENT_STA_DISCONNECTED: //wifi lost connection
//            ESP_LOGI(TAG, "[WI-FI] Disconnected");
//            if(WIFI_CONNECTED == false)
//                ESP_LOGW(TAG, "[WI-FI] Impossible to connect to wifi: wrong password and/or SSID or Wi-Fi down");
//            WIFI_CONNECTED = false;
//            set_blink_led(OFF_MODE);
//            if(RUNNING){
//                ESP_ERROR_CHECK(esp_wifi_connect());
//            }
//            else
//                xEventGroupClearBits(wifi_event_group, BIT0);
//            break;
//
//        default:
//            break;
//    }
//
//    return ESP_OK;
//}

void Core::handle_data(void *src, wifi_promiscuous_pkt_type_t type) {
    wifi_promiscuous_pkt_t *packet = (wifi_promiscuous_pkt_t *) src;
    wifi_header *header = (wifi_header *) packet->payload;

//        char *ssid = nullptr;
//
//        uint8_t ssid_size = packet->payload[25];
//
//        if (ssid_size > 0) {
//            ssid = get_ssid(packet->payload, ssid_size);
//        }
//
        int sequence = get_sequence(packet->payload);

    ESP_LOGE(TAG, "DATA RECEIVED: sender: %02x:%02x:%02x:%02x:%02x:%02x receiver: %02x:%02x:%02x:%02x:%02x:%02x", header->sender[0], header->sender[1], header->sender[2], header->sender[3], header->sender[4], header->sender[5], header->receiver[0], header->receiver[1], header->receiver[2], header->receiver[3], header->receiver[4], header->receiver[5]);


    //
        char *ht = get_ht(packet->payload, packet->rx_ctrl.rssi, ssid_size);
//
//        ESP_LOGE(TAG, "DATA RECEIVED: %d", sizeof(packet->payload));
////        uart_write_bytes((uart_port_t)(0), "W\n\r", 3);
//
//        Handler::transmit_data_bus_content_response(ssid);
//
////        ESP_LOGI(TAG, "ADDR=%02x:%02x:%02x:%02x:%02x:%02x, "
////                      "SSID=%s, "
////                      "RSSI=%02d, "
////                      "SN=%d, "
////                      "HT CAP. INFO=%s",
////                 header->sa[0], header->sa[1], header->sa[2], header->sa[3], header->sa[4], header->sa[5],
////                 ssid,
////                 pkt->rx_ctrl.rssi,
////                 sn,
////                 htci);
//
//        // save_pkt_info(header->sa, ssid, ts, hash, pkt->rx_ctrl.rssi, sn, htci);
}

void Core::handle_event(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data) {
    unsigned int ret = 0;

    switch (event_id) {
        case WIFI_EVENT_STA_START:
            ret = esp_wifi_connect();
            if (ret != ESP_OK) {
                ESP_LOGE(TAG, "WiFi connect failed! ret:%x", ret);
            }

            xEventGroupSetBits(*State::get_wifi_event_group(), BIT0);

            break;
        case WIFI_EVENT_STA_DISCONNECTED:
            ret = esp_wifi_connect();
            if (ret != ESP_OK) {
                ESP_LOGE(TAG, "WiFi connect failed! ret:%x", ret);
            }

            xEventGroupSetBits(*State::get_wifi_event_group(), BIT0);

            break;
        default:
            break;
    }
}

char *Core::get_ssid(unsigned char *src, uint8_t size) {
    char *result = new char[SSID_MAX_SIZE];

    int i, j;

    for (i = 26, j = 0; i < 26 + size; i++, j++) {
        result[j] = src[i];
    }

    result[j] = '\0';

    return result;
};

int Core::get_sequence(unsigned char *src) {
    int result;

    char num[5] = "\0";

    sprintf(num, "%02x%02x", src[22], src[23]);
    sscanf(num, "%x", &result);

    return result;
};

char *Core::get_ht(unsigned char *src, int packet_size, int ssid_size) {
    char *result = new char[5];

    int ht_start = 25 + ssid_size + 19;

    if (src[ht_start - 1] > 0 && ht_start < packet_size - 4) {
        if (src[ht_start - 4] == 1)
            sprintf(result, "%02x%02x", src[ht_start + 3], src[ht_start + 1 + 3]);
        else {
            sprintf(result, "%02x%02x", src[ht_start], src[ht_start + 1]);
        }
    }

    return result;
};