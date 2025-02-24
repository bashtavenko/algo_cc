#include "hash_tables/string_close.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(CloseStrings, Example1) { EXPECT_TRUE(CloseStrings("abc", "bca")); }
TEST(CloseStrings, Example2) { EXPECT_TRUE(CloseStrings("aabbcc", "ccbbaa")); }
TEST(CloseStrings, Example3) { EXPECT_TRUE(CloseStrings("cabbba", "abbccc")); }
TEST(CloseStrings, Example4) { EXPECT_FALSE(CloseStrings("a", "aa")); }
TEST(CloseStrings, Example5) {
  EXPECT_FALSE(CloseStrings("abbbzcf", "babzzcz"));
}

}  // namespace
}  // namespace algo