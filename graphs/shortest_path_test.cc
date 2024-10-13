#include "graphs/shortest_path.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {

const inline std::vector<std::vector<CellType>> Make3x3() {
  using enum CellType;
  return std::vector<std::vector<CellType>>{{kBlocked, kOpen, kObject},
                                            {kOpen, kOpen, kBlocked},
                                            {kOpen, kBlocked, kOpen}};
}

TEST(ShortestPath, Works3x3) {
  auto grid = Make3x3();
  EXPECT_THAT(ShortestPath(grid), 1);
}

}  // namespace
}  // namespace algo