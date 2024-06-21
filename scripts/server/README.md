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
    description: 'CP2102 USB to UART Bridge Controller',
    location: '/dev/cu.usbserial-0001',
    manufacturer: 'Silicon Labs'
]
```

## Start

The examples below show how to start server for incoming network packets for the given **WIFI** network. 

```shell
$ sniffer-server start --device="/dev/cu.usbmodem1203" --baud_rate="9600" --host="0.0.0.0" --port=8082
```

### Retrieve records

In order to retrieve latest records it's required to perform **HTTP** request using following **URL**:
```shell
http://0.0.0.0:8082/
```

The above request returns response in the following form:
```json
[
  {
    "amplification": -77,
    "ht": "f47cfbf4",
    "receiver": "ff:ff:ff:ff:ff",
    "sender": "18:34:af:26:6f",
    "sequence": 61566,
    "ssid": "18:34:af:26:6f",
    "timestamp": "2024-06-20 18:06:46.974645",
    "type": 128
  },
  {
    "amplification": -87,
    "ht": "f47cfbf4",
    "receiver": "ff:ff:ff:ff:ff",
    "sender": "8c:5b:f0:4a:af",
    "sequence": 32853,
    "ssid": "8c:5b:f0:4a:af",
    "timestamp": "2024-06-20 18:06:47.079578",
    "type": 128
  },
  {
    "amplification": -89,
    "ht": "f47cfbf4",
    "receiver": "b0:4a:39:8e:71",
    "sender": "8c:5b:f0:4a:af",
    "sequence": 36949,
    "ssid": "8c:5b:f0:4a:af",
    "timestamp": "2024-06-20 18:06:47.079690",
    "type": 80
  },
  {
    "amplification": -77,
    "ht": "f47cfbf4",
    "receiver": "b0:4a:39:8e:71",
    "sender": "18:34:af:26:6f",
    "sequence": 127,
    "ssid": "18:34:af:26:6f",
    "timestamp": "2024-06-20 18:06:47.182351",
    "type": 80
  },
  {
    "amplification": -88,
    "ht": "f47cfbf4",
    "receiver": "ff:ff:ff:ff:ff",
    "sender": "8c:5b:f0:8e:8b",
    "sequence": 8388,
    "ssid": "8c:5b:f0:8e:8b",
    "timestamp": "2024-06-20 18:06:47.286270",
    "type": 128
  },
  {
    "amplification": -77,
    "ht": "f47cfbf4",
    "receiver": "b0:4a:39:8e:71",
    "sender": "18:34:af:26:6f",
    "sequence": 4223,
    "ssid": "18:34:af:26:6f",
    "timestamp": "2024-06-20 18:06:47.392288",
    "type": 80
  },
  {
    "amplification": -78,
    "ht": "f47cfbf4",
    "receiver": "b0:4a:39:8e:71",
    "sender": "18:34:af:26:6f",
    "sequence": 4223,
    "ssid": "18:34:af:26:6f",
    "timestamp": "2024-06-20 18:06:47.493092",
    "type": 2128
  },
  {
    "amplification": -77,
    "ht": "f47cfbf4",
    "receiver": "b0:4a:39:8e:71",
    "sender": "18:34:af:26:6f",
    "sequence": 4223,
    "ssid": "18:34:af:26:6f",
    "timestamp": "2024-06-20 18:06:47.493160",
    "type": 2128
  },
  {
    "amplification": -78,
    "ht": "f47cfbf4",
    "receiver": "b0:4a:39:8e:71",
    "sender": "18:34:af:26:6f",
    "sequence": 4223,
    "ssid": "18:34:af:26:6f",
    "timestamp": "2024-06-20 18:06:47.596714",
    "type": 2128
  },
  {
    "amplification": -78,
    "ht": "f47cfbf4",
    "receiver": "ff:ff:ff:ff:ff",
    "sender": "18:34:af:26:6f",
    "sequence": 8319,
    "ssid": "18:34:af:26:6f",
    "timestamp": "2024-06-20 18:06:47.700964",
    "type": 128
  },
  {
    "amplification": -88,
    "ht": "f47cfbf4",
    "receiver": "ff:ff:ff:ff:ff",
    "sender": "8c:5b:f0:4a:af",
    "sequence": 41045,
    "ssid": "8c:5b:f0:4a:af",
    "timestamp": "2024-06-20 18:06:47.803875",
    "type": 128
  }
]
```

Every record contains next data:
* **amplification**: strength of **WIFI** signal
* **ht**: a technology for computer processors interconnection
* **receiver**: a receiver of the network packet.
* **sender**: a sender of the network packet.
* **sequence**: a serial number of the sender device.
* **ssid**: a **SSID** of the network packet.
* **timestamp**: a timestamp of packet retrieval.
* **type**: a type of network packet.

## Authors

* Yaroslav Svitlytskyi