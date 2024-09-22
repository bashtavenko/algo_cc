#include "hacker_rank/search/ice_cream.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(WhatFlavors, BasicWorks) {
  EXPECT_THAT(WhatFlavors(std::vector<int>{2, 1, 3, 5, 6}, 5), Result(1, 3));
}

TEST(WhatFlavors, Example1Works) {
  EXPECT_THAT(WhatFlavors(std::vector<int>{1, 4, 5, 3, 2}, 4), Result(1, 4));
}

TEST(WhatFlavors, Example2Works) {
  EXPECT_THAT(WhatFlavors(std::vector<int>{2, 2, 4, 3}, 4), Result(1, 2));
}

}  // namespace