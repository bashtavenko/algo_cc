#include "dp/traverse_array.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {

TEST(NumberOfWays, Works) {
  EXPECT_THAT(NumberOfWays(3, 3), 6);
  EXPECT_THAT(NumberOfWays(5, 5), 70);
}

}  // namespace
}  // namespace algo
