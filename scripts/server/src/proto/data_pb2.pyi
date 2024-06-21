from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from typing import ClassVar as _ClassVar, Mapping as _Mapping, Optional as _Optional, Union as _Union

DESCRIPTOR: _descriptor.FileDescriptor

class SSID(_message.Message):
    __slots__ = ("first", "second", "third", "forth", "fifth", "sixth")
    FIRST_FIELD_NUMBER: _ClassVar[int]
    SECOND_FIELD_NUMBER: _ClassVar[int]
    THIRD_FIELD_NUMBER: _ClassVar[int]
    FORTH_FIELD_NUMBER: _ClassVar[int]
    FIFTH_FIELD_NUMBER: _ClassVar[int]
    SIXTH_FIELD_NUMBER: _ClassVar[int]
    first: int
    second: int
    third: int
    forth: int
    fifth: int
    sixth: int
    def __init__(self, first: _Optional[int] = ..., second: _Optional[int] = ..., third: _Optional[int] = ..., forth: _Optional[int] = ..., fifth: _Optional[int] = ..., sixth: _Optional[int] = ...) -> None: ...

class Sender(_message.Message):
    __slots__ = ("first", "second", "third", "forth", "fifth", "sixth")
    FIRST_FIELD_NUMBER: _ClassVar[int]
    SECOND_FIELD_NUMBER: _ClassVar[int]
    THIRD_FIELD_NUMBER: _ClassVar[int]
    FORTH_FIELD_NUMBER: _ClassVar[int]
    FIFTH_FIELD_NUMBER: _ClassVar[int]
    SIXTH_FIELD_NUMBER: _ClassVar[int]
    first: int
    second: int
    third: int
    forth: int
    fifth: int
    sixth: int
    def __init__(self, first: _Optional[int] = ..., second: _Optional[int] = ..., third: _Optional[int] = ..., forth: _Optional[int] = ..., fifth: _Optional[int] = ..., sixth: _Optional[int] = ...) -> None: ...

class Receiver(_message.Message):
    __slots__ = ("first", "second", "third", "forth", "fifth", "sixth")
    FIRST_FIELD_NUMBER: _ClassVar[int]
    SECOND_FIELD_NUMBER: _ClassVar[int]
    THIRD_FIELD_NUMBER: _ClassVar[int]
    FORTH_FIELD_NUMBER: _ClassVar[int]
    FIFTH_FIELD_NUMBER: _ClassVar[int]
    SIXTH_FIELD_NUMBER: _ClassVar[int]
    first: int
    second: int
    third: int
    forth: int
    fifth: int
    sixth: int
    def __init__(self, first: _Optional[int] = ..., second: _Optional[int] = ..., third: _Optional[int] = ..., forth: _Optional[int] = ..., fifth: _Optional[int] = ..., sixth: _Optional[int] = ...) -> None: ...

class HT(_message.Message):
    __slots__ = ("first", "second", "third", "forth", "fifth")
    FIRST_FIELD_NUMBER: _ClassVar[int]
    SECOND_FIELD_NUMBER: _ClassVar[int]
    THIRD_FIELD_NUMBER: _ClassVar[int]
    FORTH_FIELD_NUMBER: _ClassVar[int]
    FIFTH_FIELD_NUMBER: _ClassVar[int]
    first: int
    second: int
    third: int
    forth: int
    fifth: int
    def __init__(self, first: _Optional[int] = ..., second: _Optional[int] = ..., third: _Optional[int] = ..., forth: _Optional[int] = ..., fifth: _Optional[int] = ...) -> None: ...

class DataBusContent(_message.Message):
    __slots__ = ("ssid", "sender", "receiver", "ht", "type", "amplification", "sequence")
    SSID_FIELD_NUMBER: _ClassVar[int]
    SENDER_FIELD_NUMBER: _ClassVar[int]
    RECEIVER_FIELD_NUMBER: _ClassVar[int]
    HT_FIELD_NUMBER: _ClassVar[int]
    TYPE_FIELD_NUMBER: _ClassVar[int]
    AMPLIFICATION_FIELD_NUMBER: _ClassVar[int]
    SEQUENCE_FIELD_NUMBER: _ClassVar[int]
    ssid: SSID
    sender: Sender
    receiver: Receiver
    ht: HT
    type: int
    amplification: int
    sequence: int
    def __init__(self, ssid: _Optional[_Union[SSID, _Mapping]] = ..., sender: _Optional[_Union[Sender, _Mapping]] = ..., receiver: _Optional[_Union[Receiver, _Mapping]] = ..., ht: _Optional[_Union[HT, _Mapping]] = ..., type: _Optional[int] = ..., amplification: _Optional[int] = ..., sequence: _Optional[int] = ...) -> None: ...
