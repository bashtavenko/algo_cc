#include "dp/rod_cutting.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

using ::testing::Eq;

std::vector<Rod> CreateRod() {
  return std::vector<Rod>{Rod{1, 1},  Rod{2, 5},  Rod{3, 8},  Rod{4, 9},
                          Rod{5, 10}, Rod{6, 17}, Rod{7, 17}, Rod{8, 20},
                          Rod{9, 24}, Rod{10, 30}};
}

TEST(RodCutting, CutRodBasic) {
  EXPECT_THAT(CutRodBasic(CreateRod(), 4), Eq(10));
  EXPECT_THAT(CutRodBasic(CreateRod(), 7), Eq(18));
}

TEST(RodCutting, CutRodBasicMemoized) {
  EXPECT_THAT(CutRodBasicMemoized(CreateRod(), 4), Eq(10));
}

TEST(RodCutting, CutRodBottomUp) {
  EXPECT_THAT(CutRodBottomUp(CreateRod(), 4), Eq(10));
}

TEST(RodCutting, CutRod) {
  auto [revenue, cuts] = CutRod(CreateRod(), 7);
  EXPECT_THAT(revenue, Eq(18));
  EXPECT_THAT(cuts, Eq(std::vector<int32_t>{1, 6}));
}
}  // namespace
}  // namespace algo