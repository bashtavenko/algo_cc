#include "primitives/quantize.h"

#include <bitset>
#include "gtest/gtest.h"
#include "gmock/gmock-matchers.h"

namespace algo {
namespace {
using ::testing::FloatNear;

std::string ConvertInt32ToString(uint32_t value) {
  std::bitset<32> bits(value);
  std::string bit_str = bits.to_string();

  // Insert spaces for readability (4 bits per group)
  std::string formatted;
  for (size_t i = 0; i < bit_str.length(); i++) {
    if (i > 0 && i % 4 == 0) formatted += ' ';
    formatted += bit_str[i];
  }
  return formatted;
}


TEST(Quantize, Works) {
  constexpr float min_val = 0.0f;
  constexpr float max_val = 4.0f;
  constexpr float original_data = 3.14159;
  EXPECT_EQ(QuantizeFloatTo8bit(original_data, min_val, max_val), 200);
  EXPECT_THAT(DeQuantize8bitToFloat(200, min_val, max_val), FloatNear(3.14159, 0.01f));
}

TEST(Packing, Works) {
  uint16_t value1 = 1023; // Max 10-bit value
  uint16_t value2 = 512; // Mid 10-bit value
  uint16_t value3 = 4095; // Max 12-bit value
  uint32_t packed = PackValues(value1, value2, value3);
  EXPECT_EQ(ConvertInt32ToString(packed), "1111 1111 1111 1000 0000 0011 1111 1111");
  EXPECT_EQ(packed, 4294444031);
}

TEST(Unpacking, Works) {
  uint16_t value1;
  uint16_t value2;
  uint16_t value3;
  UnpackValues(4294444031, value1, value2, value3);
  EXPECT_EQ(value1, 1023);
  EXPECT_EQ(value2, 512);
  EXPECT_EQ(value3, 4095);
}
} // namespace
} // namespace algo
