# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: Content/data.proto
# Protobuf Python Version: 4.25.3
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
from google.protobuf.internal import builder as _builder
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\x12\x43ontent/data.proto\x12\x0elight_detector\"C\n\x15\x44\x61taBusRequestContent\x12*\n\x08\x64\x61taType\x18\x01 \x01(\x0e\x32\x18.light_detector.DataType\"t\n\x16\x44\x61taBusResponseContent\x12\x10\n\x08\x64\x65viceId\x18\x01 \x01(\r\x12*\n\x08\x64\x61taType\x18\x02 \x01(\x0e\x32\x18.light_detector.DataType\x12\r\n\x05value\x18\x03 \x01(\x05\x12\r\n\x05nonce\x18\x04 \x01(\r*F\n\x08\x44\x61taType\x12\x0c\n\x08\x44\x61taNone\x10\x00\x12\x07\n\x03Raw\x10\x01\x12\x08\n\x04\x46ull\x10\x02\x12\x0c\n\x08Infrared\x10\x03\x12\x0b\n\x07Visible\x10\x04\x62\x06proto3')

_globals = globals()
_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, _globals)
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'Content.data_pb2', _globals)
if _descriptor._USE_C_DESCRIPTORS == False:
  DESCRIPTOR._options = None
  _globals['_DATATYPE']._serialized_start=225
  _globals['_DATATYPE']._serialized_end=295
  _globals['_DATABUSREQUESTCONTENT']._serialized_start=38
  _globals['_DATABUSREQUESTCONTENT']._serialized_end=105
  _globals['_DATABUSRESPONSECONTENT']._serialized_start=107
  _globals['_DATABUSRESPONSECONTENT']._serialized_end=223
# @@protoc_insertion_point(module_scope)