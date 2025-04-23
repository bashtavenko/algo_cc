#ifndef ALGO_CC_PRIMITIVES_QUANTIZE_H_
#define ALGO_CC_PRIMITIVES_QUANTIZE_H_

#include <cstdint>


namespace algo {
// Quantize a float value to an 8-bit integer (0-255)
uint8_t QuantizeFloatTo8bit(float value, float min_val, float max_val);

// Dequantize an 8-bit integer back to float
float DeQuantize8bitToFloat(uint8_t quantized, float min_val, float max_val);

// Pack 3 values into a 32-bit integer:
// - value1: 10 bits (0-1023)
// - value2: 10 bits (0-1023)
// - value3: 12 bits (0-4095)
uint32_t PackValues(uint16_t value1, uint16_t value2, uint16_t value3);

// Unpack a 32-bit integer into 3 values
void UnpackValues(uint32_t packed, uint16_t &value1, uint16_t &value2, uint16_t &value3);
} // namespace algo

#endif //ALGO_CC_PRIMITIVES_QUANTIZE_H_
