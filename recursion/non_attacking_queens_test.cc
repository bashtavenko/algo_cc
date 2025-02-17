#include "recursion/non_attacking_queens.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {
using ::testing::ElementsAreArray;

TEST(FindQueensPosition, Works) {
  // No idea why this has to be the case
  EXPECT_THAT(FindQueensPosition(4),
              ElementsAreArray(std::vector<std::vector<int32_t>>{
                  {0, 2, 3, 1}, {1, 3, 0, 2}, {2, 0, 3, 1}, {3, 1, 0, 2}}));
}

}  // namespace
}  // namespace algo