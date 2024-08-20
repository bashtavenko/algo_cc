// 15.4 Power set.
// 2^n
//

#ifndef ALGO_CC_RECURSION_POWER_SET_H_
#define ALGO_CC_RECURSION_POWER_SET_H_

#include <cstdint>
#include <vector>

namespace algo {

//  Method 1, use bit array
//    01 take first
//    10 take second
//    11 take both
std::vector<std::vector<int32_t>> GenerateFromBits(
    const std::vector<int32_t>& input_set);

// Classical like venn diagram
std::vector<std::vector<int32_t>> Generate(
    const std::vector<int32_t>& input_set);

}  // namespace algo

#endif  // ALGO_CC_RECURSION_POWER_SET_H_
