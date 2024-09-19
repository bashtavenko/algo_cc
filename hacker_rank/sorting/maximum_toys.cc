#include "hacker_rank/sorting/maximum_toys.h"
#include <algorithm>
#include <vector>

// [1 2 3 4] for 7 [1, 2, 3]
// 1, 5, 10, 12, 111, 200, 1000 for 50
int MaximumToys(std::vector<int>& prices, int k) {
  std::sort(prices.begin(), prices.end());
  int toys_count = 0;
  int current_sum = 0;
  size_t i = 0;
  while (i < prices.size()) {
    current_sum += prices[i];
    if (current_sum > k) break;
    ++toys_count;
    ++i;
  }
  return toys_count;
}

// Another alternative
// int MaximumToys(std::vector<int>& prices, int k) {
//    std::sort(prices.begin(), prices.end());
//    return std::upper_bound(prices.begin(), prices.end(), k,
//        [sum = 0](int budget, int price) mutable {
//            return (sum += price) <= budget;
//        }) - prices.begin();
//}
// .. or
// // Using upper_bound
// int MaximumToysUpperBound(std::vector<int>& prices, int k) {
//    std::sort(prices.begin(), prices.end());
//    return std::upper_bound(prices.begin(), prices.end(), k,
//        [sum = 0](int budget, int price) mutable {
//            return (sum += price) <= budget;
//        }) - prices.begin();
//}
//
//// Using find_if_not and distance
// int MaximumToysFindIfNot(std::vector<int>& prices, int k) {
//     std::sort(prices.begin(), prices.end());
//     int sum = 0;
//     return std::distance(prices.begin(),
//                          std::find_if_not(prices.begin(), prices.end(),
//                             [&sum, k](int price) {
//                                 return (sum += price) <= k;
//                             }));
// }