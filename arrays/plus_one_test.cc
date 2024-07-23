#include "arrays/plus_one.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {
using ::testing::Eq;

TEST(PlusOne, Works) {
  EXPECT_THAT(PlusOne(std::vector<int32_t>{1, 2, 9}),
              Eq(std::vector<int32_t>{1, 3, 0}));
  EXPECT_THAT(PlusOne(std::vector<int32_t>{1, 9, 9}),
              Eq(std::vector<int32_t>{2, 0, 0}));
  EXPECT_THAT(PlusOne(std::vector<int32_t>{9, 9, 9}),
              Eq(std::vector<int32_t>{1, 0, 0, 0}));
}

}  // namespace
}  // namespace algo
