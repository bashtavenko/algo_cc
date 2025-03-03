#include "graphs/nearest_exit.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(NearestExit, Example1) {
  auto maze = std::vector<std::vector<char8_t>>{
      {'+', '+', '.', '+'}, {'.', '.', '.', '+'}, {'+', '+', '+', '.'}};
  auto entrance = std::vector<int32_t>{1, 2};
  EXPECT_THAT(NearestExit(maze, entrance), 1);
}

TEST(NearestExit, Example2) {
  auto maze = std::vector<std::vector<char8_t>>{
      {'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}};
  auto entrance = std::vector<int32_t>{1, 0};
  EXPECT_THAT(NearestExit(maze, entrance), 2);
}

TEST(NearestExit, Example3) {
  auto maze = std::vector<std::vector<char8_t>>{{'.', '+'}};
  auto entrance = std::vector<int32_t>{0, 0};
  EXPECT_THAT(NearestExit(maze, entrance), -1);
}

}  // namespace
}  // namespace algo
