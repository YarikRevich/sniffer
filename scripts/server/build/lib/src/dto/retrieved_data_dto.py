from dataclasses import dataclass

@dataclass
class RetrievedDataDto:
    """Represents dto used to hold the result of a retrieved data."""

    # Represents SSID of the device.
    ssid: str

    # Represents sender identification.
    sender: str

    # Represents receiver identification.
    receiver: str

    # Represents ht identification.
    ht: str

    # Represents type of the record.
    type: int

    # Represents amplification of the record.
    amplification: int

    # Represents sequence of the record.
    sequence: int

    # Represents timestamp of the received record.
    timestamp: str

    def __init__(self, ssid: str, sender: str, receiver: str, ht: str, type: int, amplification: int, sequence: int, timestamp: str):
        self.ssid = ssid
        self.sender = sender
        self.receiver = receiver
        self.ht = ht
        self.type = type
        self.amplification = amplification
        self.sequence = sequence
        self.timestamp = timestamp
