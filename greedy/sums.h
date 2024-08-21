// 17.4 3-sum
//
#ifndef ALGO_CC_GREEDY_SUMS_H_
#define ALGO_CC_GREEDY_SUMS_H_
#include <cstdint>
#include <vector>

namespace algo {

bool HasTwoSum(const std::vector<int32_t>& sorted, int32_t target);
bool HasThreeSum(std::vector<int32_t> data, int32_t target);

}  // namespace algo

#endif  // ALGO_CC_GREEDY_SUMS_H_
