#include "internal/converter/converter.h"
#include "internal/proto/codec/codec.h"
#include "internal/handler/handler.h"

int Handler::transmit_data_bus_content_response(char *ssid) {
    sniffer::DataBusContent<SSID_MAX_SIZE> data_bus_content;

    EmbeddedProto::FieldString<SSID_MAX_SIZE> raw_ssid;

    raw_ssid.set(ssid);

    data_bus_content.set_ssid(raw_ssid);

    Codec::encode_response_content(data_bus_content);

    auto response_buffer = Codec::get_response_buffer();

    auto conversion_result = Converter::convertUint32ToUint8(response_buffer->get_size());



    uart_write_bytes(UART_NUM_2, conversion_result.data, 3);


//    if (HAL_UART_Transmit(
//            &huart2,
//            conversion_result.data,
//            3,
//            TRANSMIT_TIMEOUT) != HAL_OK) {
//        return EXIT_FAILURE;
//    }
//
//    if (HAL_UART_Transmit(
//            &huart2,
//            response_buffer->get_raw_buffer(),
//            response_buffer->get_size(),
//            TRANSMIT_TIMEOUT) != HAL_OK) {
//        return EXIT_FAILURE;
//    }
//
    response_buffer->clear();

    return EXIT_SUCCESS;
}
