// 18.3 Compute enclosed regions
//
// Fill all 'B' that do not reach the boundary
// Similar to "find island"
#ifndef ALGO_CC_GRAPHS_ENCLOSED_REGIONS_H_
#define ALGO_CC_GRAPHS_ENCLOSED_REGIONS_H_
#include <cstdint>
#include <vector>

namespace algo {

void FillSurroundedRegions(std::vector<std::vector<char>>& board);

}  // namespace algo

#endif  // ALGO_CC_GRAPHS_ENCLOSED_REGIONS_H_
