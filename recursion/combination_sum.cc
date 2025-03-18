#include "recursion/combination_sum.h"
#include <functional>
#include <numeric>

namespace algo {

/// Input: k = 3, n = 7
// Output : [[ 1, 2, 4 ]]
std::vector<std::vector<int32_t>> CombinationSum(int32_t k, int32_t n) {
  std::vector<int32_t> partial;
  std::vector<std::vector<int32_t>> result;

  std::function<void(int32_t, int32_t, int32_t)> run =
      [&](int32_t start, int32_t count, int32_t sum) {
        if (count == k) {
          if (sum == n) {
            result.push_back(partial);
          }
          return;
        }
        for (int i = start; i <= 9; ++i) {
          partial.push_back(i);
          run(i + 1, count + 1, sum + i);
          partial.pop_back();  // Backtrack
        }
      };

  run(/*start=*/1, /*count=*/0, /*sum=*/0);
  return result;
}

}  // namespace algo
