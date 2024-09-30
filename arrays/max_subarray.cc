#include "arrays/max_subarray.h"
#include <functional>
#include <limits>

namespace algo {

// This is quite messy divide-and-conquer which is hard to get it right.
// It runs in O(n*log(n))
Result MaxSubarrayNLogn(const std::vector<int32_t>& arr) {
  auto max_crossing = [&](int32_t lo, int32_t mid, int32_t hi) {
    int64_t left_sum = std::numeric_limits<int64_t>::min();
    int64_t sum = 0;
    int32_t max_left = lo;
    int32_t max_right = hi;
    // Find both subarray from midpoint both ways
    for (int32_t i = mid; i >= lo; --i) {
      sum += arr[i];
      if (sum > left_sum) {
        left_sum = sum;
        max_left = i;
      }
    }
    int64_t right_sum = std::numeric_limits<int64_t>::min();
    sum = 0;
    for (int32_t j = mid + 1; j <= hi; ++j) {
      sum += arr[j];
      if (sum > right_sum) {
        right_sum = sum;
        max_right = j;
      }
    }
    return Result{.lo = max_left, .hi = max_right, .sum = left_sum + right_sum};
  };

  std::function<Result(int32_t, int32_t)> max_sum = [&](int32_t lo,
                                                        int32_t hi) {
    if (lo == hi) return Result{.lo = lo, .hi = hi, .sum = arr[lo]};
    int32_t mid = lo + (hi - lo) / 2;
    Result left_result = max_sum(lo, mid);
    Result right_result = max_sum(mid + 1, hi);
    Result cross_result = max_crossing(lo, mid, hi);
    if (left_result.sum >= right_result.sum &&
        left_result.sum >= cross_result.sum) {
      return Result{
          .lo = left_result.lo, .hi = left_result.hi, .sum = left_result.sum};
    } else if (right_result.sum >= left_result.sum &&
               right_result.sum >= cross_result.sum) {
      return Result{.lo = right_result.lo,
                    .hi = right_result.hi,
                    .sum = right_result.sum};
    } else {
      return Result{.lo = cross_result.lo,
                    .hi = cross_result.hi,
                    .sum = cross_result.sum};
    }
  };
  return max_sum(0, arr.size() - 1);
}

// This is much simpler and runs in O(n)
// It is similar to dp/bootcamp.cc but with additional handling.
Result MaxSubarray(const std::vector<int32_t>& arr) {
  if (arr.empty()) {
    return {-1, -1, 0};  // Return invalid indices and 0 sum for empty array
  }

  int64_t min_sum = 0;
  int64_t running_sum = 0;
  int64_t max_sum = std::numeric_limits<int64_t>::min();
  int32_t min_index = -1;
  int32_t start = 0;
  int32_t end = 0;

  for (int32_t i = 0; i < arr.size(); ++i) {
    running_sum += arr[i];

    if (running_sum < min_sum) {
      min_sum = running_sum;
      min_index = i;
    }

    if (running_sum - min_sum > max_sum) {
      max_sum = running_sum - min_sum;
      start = (min_index == -1) ? 0 : min_index + 1;
      end = i;
    }
  }

  // Handle the case where all numbers are negative
  if (max_sum < 0) {
    max_sum = *std::max_element(arr.begin(), arr.end());
    start = end =
        std::distance(arr.begin(), std::max_element(arr.begin(), arr.end()));
  }
  return {start, end, max_sum};
}
}  // namespace algo