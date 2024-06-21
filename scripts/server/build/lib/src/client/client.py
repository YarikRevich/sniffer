import logging
from datetime import datetime

from serial import Serial
from serial import SerialException
from serial import EIGHTBITS

from google.protobuf.message import DecodeError

from ..proto import data_pb2 as DataBusContent
from ..dto import RetrievedDataDto
from ..tools import perform_request_await
from ..storage import Storage


class Client:
    """Represents client used to connect to remote device via serial port."""

    # Represents a connection with serial device.
    connection: Serial

    def __init__(self, device: str, baud_rate: int):
        self.device = device
        self.baud_rate = baud_rate

    def __enter__(self) -> object:
        try:
            self.connection = Serial(self.device, self.baud_rate, EIGHTBITS, timeout=1000, xonxoff=False)

            return self
        except SerialException:
            logging.fatal("Given device is not available")

    def read_data_bus_content_response(self) -> None:
        """Reads data bus content response from the board."""

        buffer = bytes()

        while True:
            perform_request_await()

            buffer += self.connection.read(100)

            if (b'\n\r\n\r' in buffer):
                split = buffer.split(b'\n\r\n\r')

                for raw in split:
                    content = DataBusContent.DataBusContent()

                    try:
                        content.ParseFromString(raw)
                    except DecodeError:
                        buffer = raw

                        break

                    Storage.add_record(RetrievedDataDto(
                        f"{hex(content.ssid.first)[2:]}:{hex(content.ssid.second)[2:]}:{hex(content.ssid.third)[2:]}:{hex(content.ssid.fifth)[2:]}:{hex(content.ssid.sixth)[2:]}",
                        f"{hex(content.sender.first)[2:]}:{hex(content.sender.second)[2:]}:{hex(content.sender.third)[2:]}:{hex(content.sender.fifth)[2:]}:{hex(content.sender.sixth)[2:]}",
                        f"{hex(content.receiver.first)[2:]}:{hex(content.receiver.second)[2:]}:{hex(content.receiver.third)[2:]}:{hex(content.receiver.fifth)[2:]}:{hex(content.receiver.sixth)[2:]}",
                        f"{hex(content.ht.first)[2:]}{hex(content.ht.second)[2:]}{hex(content.ht.third)[2:]}{hex(content.ht.fifth)[2:]}",
                        content.type,
                        content.amplification,
                        content.sequence,
                        str(datetime.now())
                    ))

    def __exit__(self, exc_type, exc_val, exc_tb) -> None:
        """Closes client connection."""

        self.connection.close()
