// 11.10 Find duplicate and missing numbers in unsorted array.
//
// Array n contains n - 1 integers
// n:6 => 5, 3, 0, 1, 2
// 5 * 6 / 2 = 15 ((n - 1)) * n / 2
// sum = 11
// 15 - 11 = 4 (missing 4)
//
// 1. Sum.  Sum of all numbers in the 0 - (n - 1) array is ((n-1) * n) / 2,
// subtract from this number sum of all numbers.
//
// If exactly one element appears twice, the result will be sum - (n-1)n / 2
// Array contains n + 1 integers (one extra)
// n:5 3, 3, 0, 1, 2, 4
// sum: 13
// 4 * 5 / 2: 10
// 13 - 10 = 3
//
// 2. XOR
//
// 3. Hash table
//
#ifndef ALGO_CC_SEARCHING_DUPLICATE_MISSING_H_
#define ALGO_CC_SEARCHING_DUPLICATE_MISSING_H_
#include <cstdint>
#include <vector>

struct DuplicateAndMissing {
  size_t duplicate;
  size_t missing;
};

namespace algo {

DuplicateAndMissing FindDuplicateAndMissing(const std::vector<int32_t>& data);

}  // namespace algo

#endif  // ALGO_CC_SEARCHING_DUPLICATE_MISSING_H_
