#include "graphs/enclosed_regions.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <vector>

namespace algo {
namespace {
using ::testing::Eq;

std::vector<std::vector<char>> CreateBoard() {
  return std::vector<std::vector<char>>{{'B', 'B', 'B', 'B'},
                                        {'W', 'B', 'W', 'B'},
                                        {'B', 'W', 'W', 'B'},
                                        {'B', 'B', 'B', 'B'}};
}

TEST(FillSurroundedRegions, CentralWoks) {
  auto data = CreateBoard();
  FillSurroundedRegions(&data);
  EXPECT_THAT(data[1][0], Eq('W'));
  EXPECT_THAT(data[1][2], Eq('B'));
  EXPECT_THAT(data[2][2], Eq('B'));
  EXPECT_THAT(data[2][1], Eq('B'));
}

}  // namespace
}  // namespace algo