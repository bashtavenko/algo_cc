#include "stacks_queues/decode_string.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(DecodeString, Example1) {
  EXPECT_THAT(DecodeString("3[a]2[bc]"), "aaabcbc");
}

TEST(DecodeString, Example2) {
  EXPECT_THAT(DecodeString("3[a2[c]]"), "accaccacc");
}

TEST(DecodeString, Example3) {
  EXPECT_THAT(DecodeString("2[abc]3[cd]ef"), "abcabccdcdcdef");
}

}  // namespace
}  // namespace algo