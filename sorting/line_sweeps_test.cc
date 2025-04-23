#include "sorting/line_sweeps.h"
#include "gtest/gtest.h"
#include "gmock/gmock-matchers.h"

namespace algo {
namespace {
TEST(LineSweeps1d, Works) {
  auto input = std::vector<std::pair<int32_t, int32_t>>{{15, 18}, {1, 5}, {8, 10}, {2, 6}};
  EXPECT_EQ(LineSweeps1D(input), 2);

  input = std::vector<std::pair<int32_t, int32_t>>{{15, 18}, {1, 5}};
  EXPECT_EQ(LineSweeps1D(input), 1);
}
} // namespace
} // namespace algo
