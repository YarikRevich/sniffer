#include "internal/core/core.h"

void Core::run() {
    enable();

    for (;;) {
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void Core::enable() {
    gpio_pad_select_gpio((gpio_num_t)2);

    gpio_set_direction((gpio_num_t)2, GPIO_MODE_OUTPUT);

    uart_config_t uart_config = {
            .baud_rate = CONFIG_UART_BAUD_RATE,
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
                    .ssid = CONFIG_WIFI_SSID,
                    .password = CONFIG_WIFI_PASSWORD
            },
    };

    esp_wifi_set_config(WIFI_IF_STA, &wifi_config);

    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &Core::handle_event, NULL);

    esp_wifi_start();

    xEventGroupWaitBits(*State::get_wifi_event_group(), BIT0, false, true, portMAX_DELAY);

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

    esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &Core::handle_event, NULL);

    esp_wifi_start();

    const wifi_promiscuous_filter_t filter = {
            .filter_mask = WIFI_EVENT_MASK_AP_PROBEREQRECVED
    };

    esp_wifi_set_promiscuous_filter(&filter);
    esp_wifi_set_promiscuous_rx_cb(&Core::handle_data);
    esp_wifi_set_promiscuous(true);

    esp_wifi_set_channel(CONFIG_WIFI_CHANNEL, WIFI_SECOND_CHAN_NONE);

    Indicator::toggle_initialization_success();
}

void Core::handle_data(void *src, wifi_promiscuous_pkt_type_t type) {
    wifi_promiscuous_pkt_t *packet = (wifi_promiscuous_pkt_t *) src;

    wifi_header *header = (wifi_header *) packet->payload;

    char *ht = Core::get_ht(packet->payload, packet->rx_ctrl.rssi, SSID_SIZE);

    int sequence = Core::get_sequence(packet->payload);

    Handler::transmit_data_bus_content_response(
            header->ssid, header->sender, header->receiver, ht, header->fctl, packet->rx_ctrl.rssi, sequence);
}

void Core::handle_event(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data) {
    unsigned int ret = 0;

    switch (event_id) {
        case WIFI_EVENT_STA_START:
            ret = esp_wifi_connect();
            if (ret != ESP_OK) {
                Indicator::toggle_initialization_failure();

                return;
            }

            xEventGroupSetBits(*State::get_wifi_event_group(), BIT0);

            break;
        case WIFI_EVENT_STA_DISCONNECTED:
            ret = esp_wifi_connect();
            if (ret != ESP_OK) {
                Indicator::toggle_initialization_failure();

                return;
            }

            xEventGroupSetBits(*State::get_wifi_event_group(), BIT0);

            break;
        default:
            break;
    }
}

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