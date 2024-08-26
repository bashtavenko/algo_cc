#include "graphs/flip_color.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <vector>

namespace algo {
namespace {

std::vector<std::vector<bool>> CreateMatrix() {
  return std::vector<std::vector<bool>>{
      {false, true, true, true, true, true, false, false, true, true},     // 0
      {true, true, false, true, true, true, true, true, true, true},       // 1
      {false, true, false, true, true, false, false, true, false, false},  // 2
      {true, true, true, false, false, false, true, true, false, true},    // 3
      {true, false, false, true, true, true, true, true, true, true},      // 4
      {true, false, false, true, true, false, true, false, false, true},   // 5
      {true, true, true, true, false, true, true, true, true, true},       // 6
      {false, true, false, true, false, true, false, true, true, true},    // 7
      {false, true, false, false, true, true, true, false, false, false},  // 8
      {true, true, true, true, true, true, true, false, false, true},      // 9
  };
}

TEST(FlipColor, Works) {
  std::vector<std::vector<bool>> matrix = CreateMatrix();
  FlipColor(0, 9, &matrix);
  EXPECT_FALSE(matrix[9][0]);
}

}  // namespace
}  // namespace algo