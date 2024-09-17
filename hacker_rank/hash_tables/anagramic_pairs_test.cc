#include "hacker_rank/hash_tables/anagramic_pairs.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(FindAnagramPairs, Works) {
  EXPECT_THAT(FindAnagramPairs("mom"), 2);
  EXPECT_THAT(FindAnagramPairs("abba"), 4);
  EXPECT_THAT(FindAnagramPairs("abcd"), 0);
  EXPECT_THAT(FindAnagramPairs("ifailuhkqq"), 3);
  EXPECT_THAT(FindAnagramPairs("kkkk"), 10);
  EXPECT_THAT(FindAnagramPairs("cdcd"), 5);
}