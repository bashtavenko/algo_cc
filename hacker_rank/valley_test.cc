#include "hacker_rank/valley.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(CountValleys, BasicWorks) {
  const std::string path = "UDDDUDUU";
  EXPECT_THAT(CountValleys(8, path), 1);
}

TEST(CountValleys, Works) {
  const std::string path = "DDUUDDUDUUUD";
  EXPECT_THAT(CountValleys(12, path), 2);
}