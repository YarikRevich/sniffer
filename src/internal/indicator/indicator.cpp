#include "internal/indicator/indicator.h"

void Indicator::toggle_initialization_success() {
    gpio_set_level((gpio_num_t)2, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    gpio_set_level((gpio_num_t)2, 1);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    gpio_set_level((gpio_num_t)2, 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    gpio_set_level((gpio_num_t)2, 1);
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    gpio_set_level((gpio_num_t)2, 0);
}

void Indicator::toggle_initialization_failure() {
    gpio_set_level((gpio_num_t)2, 0);
    vTaskDelay(200 / portTICK_PERIOD_MS);

    gpio_set_level((gpio_num_t)2, 1);
    vTaskDelay(200 / portTICK_PERIOD_MS);

    gpio_set_level((gpio_num_t)2, 0);
    vTaskDelay(200 / portTICK_PERIOD_MS);

    gpio_set_level((gpio_num_t)2, 1);
    vTaskDelay(200 / portTICK_PERIOD_MS);

    gpio_set_level((gpio_num_t)2, 0);
    vTaskDelay(200 / portTICK_PERIOD_MS);

    gpio_set_level((gpio_num_t)2, 1);
    vTaskDelay(200 / portTICK_PERIOD_MS);

    gpio_set_level((gpio_num_t)2, 0);
    vTaskDelay(200 / portTICK_PERIOD_MS);

    gpio_set_level((gpio_num_t)2, 1);
    vTaskDelay(200 / portTICK_PERIOD_MS);

    gpio_set_level((gpio_num_t)2, 0);
    vTaskDelay(200 / portTICK_PERIOD_MS);

    gpio_set_level((gpio_num_t)2, 1);
    vTaskDelay(200 / portTICK_PERIOD_MS);

    gpio_set_level((gpio_num_t)2, 0);
}