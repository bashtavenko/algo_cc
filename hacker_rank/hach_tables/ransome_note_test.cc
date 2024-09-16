#include "hacker_rank/hach_tables/ransome_note.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(CheckMagazine, Works) {
  EXPECT_TRUE(CheckMagazine(
      std::vector<std::string>{"give", "me", "one", "grand", "today", "night"},
      std::vector<std::string>{"give", "me", "one", "grand", "today"}));
  EXPECT_FALSE(CheckMagazine(
      std::vector<std::string>{"two", "times", "three", "is", "not", "four"},
      std::vector<std::string>{"two", "times", "two", "is", "four"}));

  EXPECT_FALSE(CheckMagazine(
      std::vector<std::string>{"two", "times", "three", "is", "not", "four"},
      std::vector<std::string>{"two", "times", "two", "is", "four"}));
}