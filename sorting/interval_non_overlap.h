// Given an array of intervals where intervals[i] = [starti, endi],
// return the minimum number of intervals you need to remove to make the rest of
// the intervals non-overlapping.
//
// Note that intervals which only touch at a point are non-overlapping. For
// example, [1, 2] and [2, 3] are non-overlapping.
//
//
//
// Example 1:
//
// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are
// non-overlapping.
//
#ifndef ALGO_CC_SORTING_INTERVAL_NON_OVERLAP_H_
#define ALGO_CC_SORTING_INTERVAL_NON_OVERLAP_H_
#include <cstdint>
#include <vector>

namespace algo {

int32_t EraseOvelapIntervals(std::vector<std::vector<int32_t>>& intervals);

}  // namespace algo

#endif  // ALGO_CC_SORTING_INTERVAL_NON_OVERLAP_H_
