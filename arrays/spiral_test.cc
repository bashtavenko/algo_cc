#include "arrays/spiral.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {
using testing::Eq;

TEST(Matrix_3_3, Works) {
  std::vector<std::vector<int32_t>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  EXPECT_THAT(Compute(matrix),
              Eq(std::vector<int32_t>{1, 2, 3, 6, 9, 8, 7, 4, 5}));
};
}  // namespace
}  // namespace algo