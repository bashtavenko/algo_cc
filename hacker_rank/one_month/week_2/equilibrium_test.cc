#include "hacker_rank/one_month/week_2/equilibrium.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(Equilibrium, TrueWorks) {
  EXPECT_TRUE(Equilibrium(std::vector<int>{1, 1, 4, 1, 1}));
  EXPECT_TRUE(Equilibrium(std::vector<int>{2, 0, 0, 0}));
  EXPECT_TRUE(Equilibrium(std::vector<int>{0, 0, 2, 0}));
}

TEST(Equilibrium, FalseWorks) {
  EXPECT_FALSE(Equilibrium(std::vector<int>{1, 2, 3}));
}

}  // namespace