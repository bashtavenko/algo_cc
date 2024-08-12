// 11.8 Find the largest k-element of an unsorted array.
//
// 3, 2, 1, 5, 4
// Largest: a[3],
// third largest: a[0]
// Assume entries are distinct.
//
// Approaches:
//  1. Brute force sort
//  2. max-heap
//  3. Keep partitioning until we have pivot index in right position.
//     (Randomized select)
#ifndef ALGO_CC_SEARCHING_K_LARGEST_H_
#define ALGO_CC_SEARCHING_K_LARGEST_H_
#include <cstdint>
#include <vector>

namespace algo {

int32_t FindKthLargest(int32_t k, std::vector<int32_t>* a);

}  // namespace algo

#endif  // ALGO_CC_SEARCHING_K_LARGEST_H_
