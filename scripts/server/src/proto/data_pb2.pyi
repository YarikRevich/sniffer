from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from typing import ClassVar as _ClassVar, Optional as _Optional

DESCRIPTOR: _descriptor.FileDescriptor

class DataBusContent(_message.Message):
    __slots__ = ("ssid", "receiver", "sender", "hp", "amplification", "sequence")
    SSID_FIELD_NUMBER: _ClassVar[int]
    RECEIVER_FIELD_NUMBER: _ClassVar[int]
    SENDER_FIELD_NUMBER: _ClassVar[int]
    HP_FIELD_NUMBER: _ClassVar[int]
    AMPLIFICATION_FIELD_NUMBER: _ClassVar[int]
    SEQUENCE_FIELD_NUMBER: _ClassVar[int]
    ssid: str
    receiver: str
    sender: str
    hp: str
    amplification: int
    sequence: int
    def __init__(self, ssid: _Optional[str] = ..., receiver: _Optional[str] = ..., sender: _Optional[str] = ..., hp: _Optional[str] = ..., amplification: _Optional[int] = ..., sequence: _Optional[int] = ...) -> None: ...
