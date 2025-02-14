#include "primitives/parity.h"
#include <gtest/gtest.h>

namespace algo {
namespace {

TEST(Parity, Works) {
  EXPECT_EQ(1, ParityBruteForce(0b1011));
  EXPECT_EQ(0, ParityBruteForce(0b10001000));

  EXPECT_EQ(1, ParityDropsLowest(0b1011));
  EXPECT_EQ(0, ParityDropsLowest(0b10001000));
}

}  // namespace
}  // namespace algo
