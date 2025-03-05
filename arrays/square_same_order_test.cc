#include "arrays/square_same_order.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {
using ::testing::ElementsAreArray;

TEST(SquareIt, Example1) {
  EXPECT_THAT(SquareIt(std::vector<int32_t>{1, 2, 3}),
              ElementsAreArray(std::vector<int32_t>{1, 4, 9}));
}

TEST(SquareIt, Example2) {
  EXPECT_THAT(SquareIt(std::vector<int32_t>{-2, 0, 1, 3}),
              ElementsAreArray(std::vector<int32_t>{0, 1, 4, 9}));
}

}  // namespace
}  // namespace algo