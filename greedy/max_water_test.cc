#include "greedy/max_water.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <vector>

namespace algo {
namespace {

TEST(GetMaxTrappedWater, Works) {
  EXPECT_THAT(GetMaxTrappedWater(std::vector<int32_t>{
                  1, 2, 1, 3, 4, 4, 5, 6, 2, 1, 3, 1, 3, 2, 1, 2, 4, 1}),
              48);
}
}  // namespace
}  // namespace algo