// 16.6 The Knapsack.
//
// Make decisions. What if an item is chosen (provided that it fits into
// knapsack) or NOT chosen? Check both options and get the max.
//
// If capacity is 5, the optimum solution is 2 + 3 = $220
// Greedy won't work because the highest cost per pound is
// item 1 and the next one is item 2 which will end up being
// 1 + 2 = $160
//                            Capacity is 5 lb
// Item Value Weight              0  1  2   3   4   5
// 1     $60   1            1     0  0  60  60  0   60
// 2     $100  2            1-2   0  0  100 0   0   160
// 3     $120  3            1-3   0  0  0   0   0   220
//
// 220 because with current item it is
//$220 ($120 + $100) and without it $160
//$100 is because item 3 has weight of 3 and without that item
// we should look at 5 - 3 = a[2][2]
//
//                             Capacity is 5 lb
// Item Value Weight              0  1  2  3  4  5
// 1     $60   5            1     0  0  0  0  0  60
// 2     $50   3            1-2   0  0  0  50 50 60
// 3     $70   4            1-3   0  0  0  50 70 70
// 4     $30   2            1-4   0  0  30 50 70 80
// 80 is because with current item it is
//$80 ($50 + $30) and without it $70
//$50 is a[4][3] = 50
//
#ifndef ALGO_CC_DP_KNAPSACK_H_
#define ALGO_CC_DP_KNAPSACK_H_

#include <cstdint>
#include <vector>

namespace algo {

struct Item {
  int32_t value;
  int32_t weight;
};

int32_t OptimumSubjectToCapacity(const std::vector<Item>& items,
                                 int32_t capacity);

}  // namespace algo

#endif  // ALGO_CC_DP_KNAPSACK_H_
