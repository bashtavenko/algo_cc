#include "strings/palidrome_index.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {
using ::testing::AnyOf;

TEST(PalidromeIndex, Works) {
  EXPECT_THAT(PalidromeIndex("bcbc"), AnyOf(0, 3));
}
}  // namespace
}  // namespace algo