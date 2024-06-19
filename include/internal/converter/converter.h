#ifndef SNIFFER_CONVERTER_H
#define SNIFFER_CONVERTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include <stdint.h>
#include <stddef.h>

/**
 * Represents a set of available data converters.
 */
class Converter {
public:
    /**
     * Represents result of uint32 to uint8 conversion.
     */
    struct Uint32ToUint8Result {
        uint8_t data[3];
    };

    /**
     * Converts given uint32 value into uint8.
     *
     * @param value - given uint32 value.
     * @return result of conversion.
     */
    static Uint32ToUint8Result convertUint32ToUint8(uint32_t value);
};

#endif //SNIFFER_CONVERTER_H
