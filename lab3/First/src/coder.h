#ifndef CODER_H
#define CODER_H

#include <stddef.h>
#include <stdint.h>

size_t encode_varint(uint32_t value, uint8_t *buf);
uint32_t decode_varint(const uint8_t **bufp);

#endif
