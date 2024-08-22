#include "recursion/power_set.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {

TEST(GenerateFromBits, Works) {
  const std::vector<std::vector<int32_t>> want = {{}, {1}, {2}, {1, 2}};
  EXPECT_THAT(GenerateFromBits(std::vector<int32_t>{1, 2}), want);
}

TEST(Generate, Works) {
  const std::vector<std::vector<int32_t>> want = {
      {0, 1, 2}, {0, 1}, {0, 2}, {0}, {1, 2}, {1}, {2}, {}};
  EXPECT_THAT(Generate(std::vector<int32_t>{0, 1, 2}), want);
}

}  // namespace
}  // namespace algo
