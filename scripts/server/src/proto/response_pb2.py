# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: response.proto
# Protobuf Python Version: 4.25.3
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
from google.protobuf.internal import builder as _builder
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from .Content import data_pb2 as Content_dot_data__pb2
from .Content import info_pb2 as Content_dot_info__pb2
from .Content import settings_pb2 as Content_dot_settings__pb2


DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\x0eresponse.proto\x12\x0elight_detector\x1a\x12\x43ontent/data.proto\x1a\x12\x43ontent/info.proto\x1a\x16\x43ontent/settings.proto\"\xd7\x01\n\x11ResponseContainer\x12\x39\n\x07\x64\x61taBus\x18\x01 \x01(\x0b\x32&.light_detector.DataBusResponseContentH\x00\x12\x39\n\x07infoBus\x18\x02 \x01(\x0b\x32&.light_detector.InfoBusResponseContentH\x00\x12\x41\n\x0bsettingsBus\x18\x03 \x01(\x0b\x32*.light_detector.SettingsBusResponseContentH\x00\x42\t\n\x07\x63ontentb\x06proto3')

_globals = globals()
_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, _globals)
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'response_pb2', _globals)
if _descriptor._USE_C_DESCRIPTORS == False:
  DESCRIPTOR._options = None
  _globals['_RESPONSECONTAINER']._serialized_start=99
  _globals['_RESPONSECONTAINER']._serialized_end=314
# @@protoc_insertion_point(module_scope)