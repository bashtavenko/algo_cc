// Find all valid combinations of k numbers that sum up to n such that the
// following conditions are true:
//
// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain
// the same combination twice, and the combinations may be returned in any
// order.
// Input: k = 3, n = 7
// Output : [[ 1, 2, 4 ]] Explanation : 1 + 2 + 4 = 7 There are no other valid
// combinations.
#ifndef COMBINATION_SUM_H
#define COMBINATION_SUM_H

#include <cstdint>
#include <vector>

namespace algo {

std::vector<std::vector<int32_t>> CombinationSum(int32_t k, int32_t n);

}  // namespace algo

#endif  // COMBINATION_SUM_H
