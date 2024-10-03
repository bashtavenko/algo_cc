#include <cstdint>
#include <unordered_map>
#include <vector>

namespace algo {

int32_t FibonacciBasic(int32_t n) {
  if (n <= 1) return n;
  return FibonacciBasic(n - 1) + FibonacciBasic(n - 2);
}
int32_t FibonacciCached(int32_t n, std::unordered_map<int32_t, int32_t>* m) {
  std::unordered_map<int32_t, int32_t>& cache = *m;
  if (n <= 1) {
    return n;
  } else if (!cache.contains(n)) {
    cache[n] = FibonacciCached(n - 1, m) + FibonacciCached(n - 2, m);
  }
  return cache[n];
}
int32_t FibonacciIterative(int32_t n) {
  if (n <= 1) return n;

  int32_t f_minus_1 = 1;
  int32_t f_minus_2 = 0;
  for (int32_t i = 1; i < n;
       ++i) {  // Bug in the book. It should be 1 and not 2
    int32_t f = f_minus_2 + f_minus_1;
    f_minus_2 = f_minus_1;
    f_minus_1 = f;
  }

  return f_minus_1;
}

// Maintain min_sum, max_sum, running_sum for each element.
// Maximum is the difference of run and min.
int32_t FindMaximumSubarray(const std::vector<int32_t>& data) {
  int32_t min_sum = 0;
  int32_t running_sum = 0;
  int32_t max_sum = 0;

  for (size_t i = 0; i < data.size(); ++i) {
    running_sum += data[i];
    if (running_sum < min_sum) {
      // We can find lo and hi indexes for sub-array here and in other block.
      min_sum = running_sum;
    }

    // This is pretty clever.
    if (running_sum - min_sum > max_sum) {
      max_sum = running_sum - min_sum;
    }
  }
  return max_sum;
}

}  // namespace algo