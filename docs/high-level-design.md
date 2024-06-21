```plantuml
title

High-level design of "sniffer"

end title

actor "Client"

component "Board control plain" {
entity "ProtocolBuffers"
node "WIFI module"


[Client] <--> [ProtocolBuffers]: " Retrieve data"
[ProtocolBuffers] <-- [WIFI module]: " Send network packet data"
```