#include "graphs/flip_color.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <vector>

namespace algo {
namespace {

std::vector<std::vector<bool>> CreateMatrix() {
  // 0 1 1
  // B W B     0
  // W W B     1
  // B B B     2
  return std::vector<std::vector<bool>>{
      {true, false, true},   // 0
      {false, false, true},  // 1
      {true, true, true},    // 2
  };
}

TEST(FlipColor, BFSWorks) {
  std::vector<std::vector<bool>> matrix = CreateMatrix();
  FlipColorBFS(1, 0, &matrix);
  EXPECT_TRUE(matrix[1][0]);
  EXPECT_TRUE(matrix[1][1]);
  EXPECT_TRUE(matrix[0][1]);
}

TEST(FlipColor, DFSWorks) {
  std::vector<std::vector<bool>> matrix = CreateMatrix();
  FlipColorDFS(1, 0, &matrix);
  EXPECT_TRUE(matrix[1][0]);
  EXPECT_TRUE(matrix[1][1]);
  EXPECT_TRUE(matrix[0][1]);
}

}  // namespace
}  // namespace algo