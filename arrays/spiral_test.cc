#include "arrays/spiral.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(Matrix_3_3, Works) {
  std::vector<std::vector<int32_t>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<int32_t> const want = {1, 2, 3, 6, 9, 8, 7, 4, 5};
  EXPECT_THAT(Compute(matrix), testing::Eq(want));
};
}  // namespace
}  // namespace algo