#include "hacker_rank/arrays/left_rotation.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(RotateLeft, FirstTryWorks) {
  std::vector<int> want = {3, 4, 5, 1, 2};
  EXPECT_THAT(RotateLeftFirstTry(std::vector<int>{1, 2, 3, 4, 5}, 2), want);

  want = {5, 1, 2, 3, 4};
  EXPECT_THAT(RotateLeftFirstTry(std::vector<int>{1, 2, 3, 4, 5}, 4), want);
}

TEST(RotateLeft, Works) {
  std::vector<int> want = {3, 4, 5, 1, 2};
  EXPECT_THAT(RotateLeft(std::vector<int>{1, 2, 3, 4, 5}, 2), want);

  want = {5, 1, 2, 3, 4};
  EXPECT_THAT(RotateLeft(std::vector<int>{1, 2, 3, 4, 5}, 4), want);
}

TEST(RotateLeft, STDWorks) {
  std::vector<int> want = {3, 4, 5, 1, 2};
  EXPECT_THAT(RotateLeftSTD(std::vector<int>{1, 2, 3, 4, 5}, 2), want);
  
  want = {5, 1, 2, 3, 4};
  EXPECT_THAT(RotateLeftSTD(std::vector<int>{1, 2, 3, 4, 5}, 4), want);
}