#include "strings/replace_remove.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {
using ::testing::ContainerEq;
using ::testing::Eq;

TEST(ReplaceRemove, Works) {
  char8_t data[] = u8"acdbbca";
  char8_t want[] = u8"ddcdcdd";
  int32_t result = ReplaceAndRemove(7, data);
  EXPECT_THAT(data, ContainerEq(want));
  EXPECT_THAT(result, Eq(7));
}

}  // namespace
}  // namespace algo