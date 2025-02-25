#include "arrays/sparse_dot_product.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(DotProduct, Example1) {
  EXPECT_THAT(DotProduct(std::vector<int32_t>{1, 2, 3, 0},
                         std::vector<int32_t>{2, 0, 0, 5}),
              2);
}

TEST(DotProduct, Example2) {
  EXPECT_THAT(DotProduct(std::vector<int32_t>{8, 0, 0, 1, 0, 0, 2, 0},
                         std::vector<int32_t>{0, 2, 0, 7, 0, 0, 3, 0}),
              13);
}

TEST(DotProduct, Example3) {
  EXPECT_THAT(DotProduct(std::vector<int32_t>{1, 2, 0, 2},
                         std::vector<int32_t>{2, 0, 0, 5}),
              12);
}

}  // namespace
}  // namespace algo