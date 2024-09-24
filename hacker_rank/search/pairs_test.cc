#include "hacker_rank/search/pairs.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(Pairs, BasicWorks) {
  EXPECT_THAT(Pairs(1, std::vector<int>{1, 2, 3, 4}), 3);
}

TEST(Pairs, Example1Works) {
  EXPECT_THAT(Pairs(2, std::vector<int>{1, 5, 3, 4, 2}), 3);
}

}  // namespace