#include "strings/reverse_words.h"
#include <string>
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(ReverseWords, Works) {
  std::string s = "Alice likes Bob";
  ReverseWords(&s);
  EXPECT_THAT(s, "Bob likes Alice");
}

}  // namespace
}  // namespace algo