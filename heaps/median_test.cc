#include "heaps/median.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <vector>

namespace algo {
namespace {

TEST(RunMedian, Works) {
  const std::vector<int32_t> data{1, 0, 3, 5, 2, 0, 1};
  const std::vector<double> want_vertices{1., 0.5, 1., 2., 2., 1.5, 1.};
  EXPECT_THAT(OnlineMedian(data.begin(), data.end()), want_vertices);
}

}  // namespace
}  // namespace algo