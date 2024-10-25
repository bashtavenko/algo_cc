#include "hacker_rank/one_month/week_2/zigzag.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {
using ::testing::Eq;

TEST(Zigzag, Works) {
  auto arr = std::vector<int>{1, 2, 3, 4, 5, 6, 7};
  Zigzag(arr);
  EXPECT_THAT(arr, Eq(std::vector<int>{1, 2, 3, 7, 6, 5, 4}));
}

}  // namespace