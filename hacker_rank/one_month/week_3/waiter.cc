#include "hacker_rank/one_month/week_3/waiter.h"
#include <algorithm>

std::vector<int> Waiter(const std::vector<int>& number, int q) {
  const std::vector<int> kPrimes{2, 3, 5, 7, 11, 13};
  std::vector<int> answer;
  std::vector<int> a = number;
  std::vector<int> b;

  for (int i = 0; i < q; ++i) {
    b.clear();                // Reset b for each prime iteration
    std::vector<int> next_a;  // Next iteration's a-stack

    for (int j = a.size() - 1; j >= 0; --j) {  // Process from top to bottom
      if (a[j] % kPrimes[i] == 0) {
        b.push_back(a[j]);
      } else {
        next_a.push_back(a[j]);
      }
    }

    // Move all of b's elements in reverse order (top to bottom) to answer
    while (!b.empty()) {
      answer.push_back(b.back());
      b.pop_back();
    }
    a = next_a;  // Update `a` for the next iteration
  }

  // Append any remaining values in `a` (as-is, from top to bottom) to answer
  while (!a.empty()) {
    answer.push_back(a.back());
    a.pop_back();
  }

  return answer;
}
