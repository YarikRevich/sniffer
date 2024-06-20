import logging

from ..middleware import is_device_available

from ..dto import RetrievedDataDto
from ..client import Client

from ..server import run

from threading import Thread

class StartCommand:
    """Represents 'start' command."""

    @staticmethod
    def handle(device: str, baud_rate: int, host: str, port: int) -> None:
        """Handles the execution of command wrapper ."""

        if not is_device_available(device):
            logging.info("Selected device is not available")
            return

        Thread(
            target=StartCommand.__process_get_data_concurrent,
            args=([device, baud_rate])).start()

        run(host, port)

    @staticmethod
    def __process_get_data_concurrent(device: str, baud_rate: int):
        """Processes request to retrieve 'raw' data from the device"""

        with Client(device, baud_rate) as client:
            client.read_data_bus_content_response()
