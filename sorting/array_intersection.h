// 13.1 Find intersection of two sorted arrays.
// Takes two sorted arrays and returns array with elements
// present in both arrays. The input may have duplicates.
//
// Example:
// [2, 3, 3, 5, 5, 6, 7, 7, 8, 12]
// [5, 5, 6, 8, 8, 9, 10, 10]
//
// [5, 6, 8]
//
// Why not have two pointers move?
//
#ifndef ALGO_CC_SORTING_ARRAY_INTERSECTION_H_
#define ALGO_CC_SORTING_ARRAY_INTERSECTION_H_
#include <cstdint>
#include <vector>

namespace algo {

std::vector<int32_t> Intersect(const std::vector<int32_t>& a,
                               const std::vector<int32_t>& b);

}  // namespace algo

#endif  // ALGO_CC_SORTING_ARRAY_INTERSECTION_H_
