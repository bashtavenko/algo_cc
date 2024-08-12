// 11.1 Find a sorted array for first occurrence.
//
// There are duplicates
//    [-14, -10, 2, 108, 108, 243, 285, 285, 285, 401]
//    108: 3

#ifndef ALGO_CC_SEARCHING_FIRST_OCCURRENCE_H_
#define ALGO_CC_SEARCHING_FIRST_OCCURRENCE_H_
#include <cstdint>
#include <vector>

namespace algo {

size_t SearchFirst(const std::vector<int32_t>& sorted, int32_t target);

}  // namespace algo

#endif  // ALGO_CC_SEARCHING_FIRST_OCCURRENCE_H_
