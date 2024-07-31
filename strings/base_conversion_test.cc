#include "strings/base_conversion.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(BaseConversion, Works) {
  EXPECT_THAT(ConvertBase("615", 7, 13), "1A7");
  EXPECT_THAT(ConvertBase("15", 10, 16), "F");
  EXPECT_THAT(ConvertBase("16", 10, 16), "10");
}

}  // namespace
}  // namespace algo