#include "hacker_rank/one_month/week_3/waiter.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {
using ::testing::Eq;

TEST(Waiter, Works) {
  EXPECT_THAT(Waiter(std::vector<int>{2, 3, 4, 5, 6, 7}, 3),
              Eq(std::vector<int>{2, 4, 6, 3, 5, 7}));
  EXPECT_THAT(Waiter(std::vector<int>{3, 4, 7, 6, 5}, 1),
              Eq(std::vector<int>{4, 6, 3, 7, 5}));
}

}  // namespace