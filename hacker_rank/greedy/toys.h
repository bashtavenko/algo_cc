// Given items with weights, return the smallest number of containers that are
// required for those items.
// The shipping company has a requirement that all items loaded in a container
// must individually weigh no more than 4 units more than the lightest item in
// that container.
// A container must weigh no greater than 4 units + the weight
// of the minimum item. Meaning a container has the heaviest individual item,
// not the total combined weight. It restricts the weight of each item. Sum of
// weights is not important.
// Example w = [1, 2, 3, 4, 5, 10, 11, 12, 13] can be
// broken into two containers [1, 2, 3, 4, 5], [10, 11, 12, 13]
// Example 1: w = [1 2 3 21 7 12 14 21]
// [1, 2, 3] (1 ... 1 + 4 = 5)
// [21] (21...25) two times
// [7] (7 ... 11)
// [12, 14] (12...14)

#ifndef ALGO_CC_HACKER_RANK_GREEDY_TOYS_H_
#define ALGO_CC_HACKER_RANK_GREEDY_TOYS_H_
#include <vector>

int MakeContainers(std::vector<int>& w);

#endif  // ALGO_CC_HACKER_RANK_GREEDY_TOYS_H_
