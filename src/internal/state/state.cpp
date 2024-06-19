#include "internal/state/state.h"

EventGroupHandle_t* State::get_wifi_event_group() {
    return &wifi_event_group;
};

EventGroupHandle_t State::wifi_event_group = xEventGroupCreate();