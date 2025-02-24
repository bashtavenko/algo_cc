#include "arrays/product_except_self.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {
using ::testing::ElementsAreArray;

TEST(ProductExceptSelf, Works) {
  EXPECT_THAT(ProductExceptSelf(std::vector<int32_t>{1, 2, 3, 4}),
              ElementsAreArray(std::vector<int32_t>{24, 12, 8, 6}));
  EXPECT_THAT(ProductExceptSelf(std::vector<int32_t>{-1, 1, 0, -3, 3}),
              ElementsAreArray(std::vector<int32_t>{0, 0, 9, 0, 0}));
}

}  // namespace
}  // namespace algo
