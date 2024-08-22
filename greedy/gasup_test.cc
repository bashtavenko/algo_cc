#include "greedy/gasup.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <vector>

namespace algo {
namespace {

TEST(FindAmpleCity, Works) {
  const std::vector<int32_t> gallons{50, 20, 5, 30, 25, 10, 10};
  const std::vector<int32_t> distances{900, 600, 200, 400, 600, 200, 100};
  EXPECT_THAT(FindAmpleCity(gallons, distances), 3);
}

}  // namespace
}  // namespace algo