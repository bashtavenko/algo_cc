#include "primitives/saturating_add.h"

namespace algo {

int8_t SaturatingAdd(int8_t a, int8_t b) {
  const int16_t sum = static_cast<int16_t>(a) + static_cast<int16_t>(b);
  if (sum > 127) return 127;
  if (sum < -128) return -128;
  return static_cast<int8_t>(sum);
}

}  // namespace algo