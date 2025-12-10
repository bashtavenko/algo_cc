#include "primitives/quantize.h"
#include <cmath>

namespace algo {
uint8_t QuantizeFloatTo8bit(float value, float min_val, float max_val) {
  // Clamp the value to the range
  if (value < min_val) value = min_val;
  if (value > max_val) value = max_val;

  // Scale to 0-1 range
  const float normalized = (value - min_val) / (max_val - min_val);

  // Scale to 0-255 range and round to the nearest integer
  return static_cast<uint8_t>(std::round(normalized * 255.0f));
}

float DeQuantize8bitToFloat(uint8_t quantized, float min_val, float max_val) {
  // Convert back to 0-1 range
  const float normalized = quantized / 255.0f;

  // Scale back to the original range
  return min_val + normalized * (max_val - min_val);
}

uint32_t PackValues(uint16_t value1, uint16_t value2, uint16_t value3) {
  // Make sure values don't exceed their bit limits
  value1 &= 0x3FF; // Mask to 10 bits
  value2 &= 0x3FF; // Mask to 10 bits
  value3 &= 0xFFF; // Mask to 12 bits

  // Pack the values: value1 at bits 0-9, value2 at bits 10-19, value3 at bits 20-31
  return (static_cast<uint32_t>(value3) << 20) |
         (static_cast<uint32_t>(value2) << 10) |
         value1;
}

void UnpackValues(uint32_t packed, uint16_t &value1, uint16_t &value2, uint16_t &value3) {
  value1 = packed & 0x3FF; // Extract bits 0-9
  value2 = (packed >> 10) & 0x3FF; // Extract bits 10-19
  value3 = (packed >> 20) & 0xFFF; // Extract bits 20-31
}
} // namespace
