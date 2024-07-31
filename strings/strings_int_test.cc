#include "strings/strings_int.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(IntToString, Works) {
  EXPECT_THAT(IntToString(123), "123");
  EXPECT_THAT(IntToString(-123), "-123");
}

TEST(StringToInt, Works) {
  EXPECT_THAT(StringToInt("314"), 314);
  EXPECT_THAT(StringToInt("-314"), -314);
}

}  // namespace
}  // namespace algo
