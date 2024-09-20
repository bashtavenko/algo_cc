#include "graphs/maze.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <vector>
#include "absl/strings/str_format.h"

namespace algo {

std::ostream& operator<<(std::ostream& os, const Coordinate& c) {
  os << absl::StreamFormat("(%i, %i)", c.x, c.y);
  return os;
}

namespace {

std::vector<std::vector<Color>> CreateMaze() {
  using enum Color;
  return std::vector<std::vector<Color>>{
      {kBlack, kWhite, kWhite, kWhite, kWhite, kWhite, kBlack, kBlack, kWhite,
       kWhite},  // 0
      {kWhite, kWhite, kBlack, kWhite, kWhite, kWhite, kWhite, kWhite, kWhite,
       kWhite},  // 1
      {kBlack, kWhite, kBlack, kWhite, kWhite, kBlack, kBlack, kWhite, kBlack,
       kBlack},  // 2
      {kWhite, kWhite, kWhite, kBlack, kBlack, kBlack, kWhite, kWhite, kBlack,
       kWhite},  // 3
      {kWhite, kBlack, kBlack, kWhite, kWhite, kWhite, kWhite, kWhite, kWhite,
       kWhite},  // 4
      {kWhite, kBlack, kBlack, kWhite, kWhite, kBlack, kWhite, kBlack, kBlack,
       kWhite},  // 5
      {kWhite, kWhite, kWhite, kWhite, kBlack, kWhite, kWhite, kWhite, kWhite,
       kWhite},  // 6
      {kBlack, kWhite, kBlack, kWhite, kBlack, kWhite, kBlack, kWhite, kWhite,
       kWhite},  // 7
      {kBlack, kWhite, kBlack, kBlack, kWhite, kWhite, kWhite, kBlack, kBlack,
       kBlack},  // 8
      {kWhite, kWhite, kWhite, kWhite, kWhite, kWhite, kWhite, kBlack, kBlack,
       kWhite},  // 9
  };
}

TEST(SearchMaze, Works) {
  auto maze = CreateMaze();
  std::vector<Coordinate> result =
      SearchMaze(Coordinate(0, 9), Coordinate(9, 0), maze);
  const auto want = std::vector<Coordinate>{{0, 9}, {1, 9}, {2, 9}};
  EXPECT_THAT(result, testing::IsSupersetOf(want));
}

}  // namespace
}  // namespace algo