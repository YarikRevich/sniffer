# sniffer

![ESP32](https://img.shields.io/badge/esp32-blue)
[![StandWithUkraine](https://raw.githubusercontent.com/vshymanskyy/StandWithUkraine/main/badges/StandWithUkraine.svg)](https://github.com/vshymanskyy/StandWithUkraine/blob/main/docs/README.md)

## General Information

A driver-like application, which allows to use **ESP32** board as a sniffer for the provided **WIFI** network.

Includes following features:
* Retrieve network packets
* Collect network packets in in-memory storage on server side and make it available via public **API**

![](./Docs/Examples/high-level-design.png)

## Setup

First of all connect your device to the board using Serial port.

![](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2018/08/ESP32-DOIT-DEVKIT-V1-Board-Pinout-30-GPIOs-Copy.png?quality=100&strip=all&ssl=1)

All supportive setup related operations are processed via **Makefile** placed in the project root directory.

> If **ProtocolBuffers** bindings need to be regenerated it's required to execute the following command, passing path to
> the plugin:
```shell
make generate plugin=/etc/plugin
```

In order to perform installation it's required to execute the following command, passing next parameters:
* **ssid**: name of the **WIFI** network.
* **password**: password for the **WIFI** network.
* **country**: country of the location of the **WIFI** network.
* **channel**: channel of the **WIFI** network.
* **baud_rate**: baud rate for the connection with the board.

```shell
make install ssid="505" password="505d505c" country="PL" channel=11 baud_rate=115200
```

After successful installation, the board should signalize successful connection with the **WIFI** network:

![](./docs/examples/signalization.gif)

## Scripts

### Server

Detailed documentation can be found [here](./scripts/server/README.md)