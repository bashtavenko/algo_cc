#include "recursion/permutations.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <vector>

namespace algo {
namespace {

TEST(Permutate, Works) {
  std::vector<int32_t> data{7, 3, 5};
  const std::vector<std::vector<int32_t>> want{{7, 3, 5}, {7, 5, 3}, {3, 7, 5},
                                               {3, 5, 7}, {5, 3, 7}, {5, 7, 3}};
  EXPECT_THAT(Permutate(data), want);
}
}  // namespace
}  // namespace algo