from typing import Optional

from .get_available_devices import GetAvailableDevicesCommand
from .start import StartCommand


class BaseCommand:
    """Represents base command handler."""

    @staticmethod
    def get_available_devices() -> None:
        """Returns all the available compatible devices connected to serial ports."""

        GetAvailableDevicesCommand.handle()

    @staticmethod
    def start(device: str, baud_rate: int, host: str = "0.0.0.0", port: int = 8082) -> None:
        """Starts server with the given parameters for the given device."""

        StartCommand.handle(device, baud_rate, host, port)