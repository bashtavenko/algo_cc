#include "dp/knapsack.h"
#include <functional>

namespace algo {

int32_t OptimumSubjectToCapacity(const std::vector<Item>& items,
                                 int32_t capacity) {
  std::vector<std::vector<int32_t>> dp(items.size(),
                                       std::vector<int32_t>(capacity + 1, -1));

  std::function<int32_t(int32_t, int32_t)> select =
      [&](int32_t k, int32_t available_capacity) {
        if (k < 0) return 0;

        if (dp[k][available_capacity] == -1) {
          int32_t without_curr_item = select(k - 1, available_capacity);
          int32_t with_curr_item =
              available_capacity < items[k].weight
                  ? 0
                  : items[k].value +
                        select(k - 1, available_capacity - items[k].weight);
          dp[k][available_capacity] =
              std::max(without_curr_item, with_curr_item);
        }
        return dp[k][available_capacity];
      };

  return select(items.size() - 1, capacity);
}

}  // namespace algo