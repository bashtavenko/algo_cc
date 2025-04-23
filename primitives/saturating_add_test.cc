#include "primitives/saturating_add.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace cc {

TEST(SaturatingAdd, Works) {
  EXPECT_EQ(SaturatingAdd(100, 40), 127);     // Instead of -116
  EXPECT_EQ(SaturatingAdd(-100, -50), -128);  // Instead of 106
  EXPECT_EQ(SaturatingAdd(100, 25), 125);     // Instead of 106
}

}  // namespace cc
}  // namespace algo