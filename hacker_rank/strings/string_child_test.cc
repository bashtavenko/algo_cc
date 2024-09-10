#include "hacker_rank/strings/string_child.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(CommonChild, Works) {
  EXPECT_THAT(CommonChildDP("ABCD", "ABDC"), 3);
  EXPECT_THAT(CommonChildDP("HARRY", "SALLY"), 2);
  EXPECT_THAT(CommonChildDP("AA", "BB"), 0);
  EXPECT_THAT(CommonChildDP("SHINCHAN", "NOHARAAA"), 3);
  EXPECT_THAT(CommonChildDP("ABCDEF", "FBDAMN"), 2);
}

TEST(NChooseK, Choose_4_2_Works) {
  const std::vector<std::string> want{"AB", "AC", "AD", "BC", "BD", "CD"};
  EXPECT_THAT(NChooseK("ABCD", 2), want);
}

TEST(NChooseK, Choose_4_3_Works) {
  const std::vector<std::string> want{"ABC", "ABD", "ACD", "BCD"};
  EXPECT_THAT(NChooseK("ABCD", 3), want);
}