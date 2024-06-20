# Servver

![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![MacOS](https://img.shields.io/badge/MacOS-8773f5?style=for-the-badge&logo=macos&logoColor=black)
![Windows](https://img.shields.io/badge/Windows-f8f3d5?style=for-the-badge&logo=windows&logoColor=black)
[![StandWithUkraine](https://raw.githubusercontent.com/vshymanskyy/StandWithUkraine/main/badges/StandWithUkraine.svg)](https://github.com/vshymanskyy/StandWithUkraine/blob/main/docs/README.md)

## General Information

Allows to perform operations with serial connected devices.

Includes following features:
* Collect network packets in in-memory storage on server side and make it available via public **API**

All the operations are perform with the usage of **ProtocolBuffers**.

## Setup

Your board needs to have already installed software build, which allows communication with **ESP32**. 
The device should be connected.

All setup related operations are processed via **Makefile** placed in the root directory.

In order to build the project it's required to execute the following command. It generates local **Python** project.
```shell
make install
```

# Use Cases

Most of the commands given below require **baud rate**. It is important to be the exact-supported value,
otherwise requests will be ignored. 

## Get Available Devices

The example below shows how to retrieve a set of all available devices, which can be used to perform other operations.
```shell
$ sniffer-server get_available_devices

[
  instance(AvailableDevicesDto):
    description: 'STM32 STLink',
    location: '/dev/cu.usbmodem1203',
    manufacturer: 'STMicroelectronics'
]
```

## Start

The examples below show how to start server for incoming network packets for the given **WIFI** network and afterwards
how to retrieve scraped data.

```shell
$ sniffer-server --device="/dev/cu.usbmodem1203" --baud_rate="9600" 

[
  instance(RetrievedDataDto):
    data_type: <DataTypeCompound.RAW: 'Raw'>,
    device_id: 80,
    nonce: 4,
    value: 121
]
```

In the same way other types of data can be retrieved, all the available data types are given below:
* raw
* full
* infrared
* visible

It's also possible to have a series of measurements, in order to archive that it's important to add **series** parameter.

```shell
$ light-detector-cli get_data --device="/dev/cu.usbmodem1203" --baud_rate="9600" --type="raw" --series=4

[
  instance(RetrievedDataDto):
    data_type: <DataTypeCompound.RAW: 'Raw'>,
    device_id: 80,
    nonce: 26,
    value: 51
  instance(RetrievedDataDto):
    data_type: <DataTypeCompound.RAW: 'Raw'>,
    device_id: 80,
    nonce: 27,
    value: 80
  instance(RetrievedDataDto):
    data_type: <DataTypeCompound.RAW: 'Raw'>,
    device_id: 80,
    nonce: 28,
    value: 97
  instance(RetrievedDataDto):
    data_type: <DataTypeCompound.RAW: 'Raw'>,
    device_id: 80,
    nonce: 29,
    value: 41
]
```

Having a series of measurements it becomes possible to create a diagram to more easily observe output changes. In
order to do that it's needed to add **export**(describes a location of output diagram file) and **figure**(describes a type of the diagram) 
parameters.

```shell
$ light-detector-cli get_data --device="/dev/cu.usbmodem1203" --baud_rate="9600" --type="raw" --series=4 --export="./output" --figure="plot"

...
```


## Authors

* Yaroslav Svitlytskyi