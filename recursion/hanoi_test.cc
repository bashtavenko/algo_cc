#include "recursion/hanoi.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {
using ::testing::ElementsAreArray;

TEST(ComputeTowerOfHanoi, Works) {
  EXPECT_THAT(ComputeTowerOfHanoi(3),
              ElementsAreArray(std::vector<std::vector<size_t>>{
                  {0, 1},     // smallest goes to 1
                  {0, 2},     // medium goes to 2
                  {1, 2},     // smallest goes to 2 (1, 2)
                  {0, 1},     // lage goes to 1 (2 is empty)
                  {2, 0},     // smallest from 3 goes to 0
                  {2, 1},     // medium from goes to 1
                  {0, 1}}));  // smallest goes to 1, done.
}
}  // namespace
}  // namespace algo