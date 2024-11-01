#include "hacker_rank/one_month/week_3/bomberman.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {
using ::testing::Eq;

TEST(BomberMan, SimpleCaseWorks) {
  EXPECT_THAT(BomberMan(3, std::vector<std::string>{"...", "...", "O.."}),
              Eq(std::vector<std::string>{"OOO", ".OO", "..O"}));
}

TEST(BomberMan, Works) {
  EXPECT_THAT(
      BomberMan(3, std::vector<std::string>{"...O...", "....O..", "....O..",
                                            "...O..."
                                            ".......",
                                            "OO.....", "OO....."}),
      Eq(std::vector<std::string>{"OO...OO", "OOO...O", "OOO...O", ".....OO",
                                  "....OOO", "...OOOO"}));
}
}  // namespace