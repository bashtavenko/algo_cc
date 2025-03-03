#include "arrays/highest_altitude.h"
#include <vector>
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(HighestAltitude, Example1) {
  EXPECT_THAT(HighestAltitude(std::vector<int32_t>{-5, 1, 5, 0, -7}), 1);
}

}  // namespace
}  // namespace algo
