import os

from serial.tools import list_ports

# Represents STM32 board manufacturer name.
STM_ELECTRONICS = "Silicon Labs"

# Represents a set of all allowed device manufacturers.
ALLOWED_MANUFACTURERS = [
    STM_ELECTRONICS
]


def is_manufacturer_allowed(src: str) -> bool:
    """Checks if the given manufacturer is among of allowed ones."""

    return src in ALLOWED_MANUFACTURERS


def is_device_available(device: str) -> bool:
    """Checks if the given device is available."""

    for entity in list_ports.comports():
        if entity.device == device:
            return True

    return False