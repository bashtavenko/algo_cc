#include "hacker_rank/one_month/week_1/pangram.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(Pangram, Works) {
  EXPECT_TRUE(
      Pangram("We promptly judged antique ivory buckles for the next prize"));

  EXPECT_FALSE(
      Pangram("We promptly judged antique ivory buckles for the prize"));
}

}  // namespace