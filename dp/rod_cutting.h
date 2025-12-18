// Rod cutting classic from CLRS p.360
// Steel rod cutting. Buys long steel rods and cuts them into shorter rods,
// which it sells. Each cut is free. What is the best way to cut up the rods?
#ifndef ALGO_CC_ROD_CUTTING_H
#define ALGO_CC_ROD_CUTTING_H
#include <cstdint>
#include <vector>

namespace algo {

struct Rod {
  int32_t length;  // Length of a rod
  int32_t price;   // Price
};

struct CutRodResult {
  int32_t revenue;            // Optimum revenue
  std::vector<int32_t> cuts;  // Each value represents a rod length
};

// Recursive top-down implementation
// Returns optimum revenue of cutting rod of the given length.
// For the given rod prices and the given rod length, find
// the optimal solution.
// For example,
// Rod length of 4 can be cut into
// (1 + 1 + 1 + 1) = 9
// 1 + (1 + 1 + 1) => 1 + 8 = 9
// (1 + 1) + (1 + 1) => 5 + 5 = 10  ===> optimum
// (1 + 1 + 1) + 1 => 8 + 1
// etc.
int32_t CutRodBasic(const std::vector<Rod>& rods, int32_t length);

// Same as above but with memoization
int32_t CutRodBasicMemoized(const std::vector<Rod>& rods, int32_t length);

// Bottom up, non-recursive version
int32_t CutRodBottomUp(const std::vector<Rod>& rods, int32_t length);

// Bottom up, non-recursive version with recovering paths of cuts.
CutRodResult CutRod(const std::vector<Rod>& rods, int32_t length);

}  // namespace algo

#endif  // ALGO_CC_ROD_CUTTING_H
