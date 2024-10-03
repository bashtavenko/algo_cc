#include "hacker_rank/arrays/sparse_arrays.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {
using testing::Eq;

TEST(MatchStrings, Works) {
  EXPECT_THAT(MatchStrings(std::vector<std::string>{"ab", "ab", "abc"},
                           std::vector<std::string>{"ab", "abc", "bc"}),
              Eq(std::vector<int>{2, 1, 0}));
  EXPECT_THAT(
      MatchStrings(std::vector<std::string>{"aba", "baba", "aba", "xzxb"},
                   std::vector<std::string>{"aba", "xzxb", "ab"}),
      Eq(std::vector<int>{2, 1, 0}));
}

}  // namespace
