#include "internal/handler/handler.h"

void Handler::transmit_data_bus_content_response(
        uint8_t* ssid, uint8_t* sender, uint8_t* receiver, char* ht, int type, int amplification, int sequence) {
    sniffer::DataBusContent data_bus_content;

    sniffer::SSID raw_ssid;
    raw_ssid.set_first(ssid[0]);
    raw_ssid.set_second(ssid[1]);
    raw_ssid.set_third(ssid[2]);
    raw_ssid.set_forth(ssid[3]);
    raw_ssid.set_fifth(ssid[4]);
    raw_ssid.set_sixth(ssid[5]);

    data_bus_content.set_ssid(raw_ssid);
//
    sniffer::Sender raw_sender;
    raw_sender.set_first(sender[0]);
    raw_sender.set_second(sender[1]);
    raw_sender.set_third(sender[2]);
    raw_sender.set_forth(sender[3]);
    raw_sender.set_fifth(sender[4]);
    raw_sender.set_sixth(sender[5]);

    data_bus_content.set_sender(raw_sender);

    sniffer::Receiver raw_receiver;
    raw_receiver.set_first(receiver[0]);
    raw_receiver.set_second(receiver[1]);
    raw_receiver.set_third(receiver[2]);
    raw_receiver.set_forth(receiver[3]);
    raw_receiver.set_fifth(receiver[4]);
    raw_receiver.set_sixth(receiver[5]);

    data_bus_content.set_receiver(raw_receiver);

    sniffer::HT raw_ht;
    raw_ht.set_first(ht[0]);
    raw_ht.set_second(ht[1]);
    raw_ht.set_third(ht[2]);
    raw_ht.set_forth(ht[3]);
    raw_ht.set_fifth(ht[4]);

    data_bus_content.set_ht(raw_ht);

    data_bus_content.set_type(type);

    data_bus_content.set_amplification(amplification);

    data_bus_content.set_sequence(sequence);

    if (Codec::encode_response_content(data_bus_content) != EXIT_SUCCESS) {
        Indicator::toggle_initialization_failure();

        return;
    }

    auto response_buffer = Codec::get_response_buffer();

    uart_write_bytes((uart_port_t)(0), response_buffer->get_raw_buffer(), response_buffer->get_size());
    uart_write_bytes((uart_port_t)(0), "\n\r\n\r", 4);

    response_buffer->clear();
}
