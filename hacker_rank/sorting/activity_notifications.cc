#include "hacker_rank/sorting/activity_notifications.h"
#include <algorithm>
#include <vector>

// [2 3 4 5] 1 2
// 2 3 4 2 3 6 8 4 5
// [2 3 4 2 3] => [2 2 3 3 4] m = 3 6 >= 2 * 3
// 1) Window; 2) Sort; 3) Median; 4) Check
int ActivityNotificationsBruteForce(std::vector<int>& history, int days) {
  int count = 0;
  size_t lo = 0;
  size_t hi = history.size();
  while (lo < hi) {
    // Window and sort
    size_t end = lo + days;
    if (end > history.size() - 1) break;
    std::vector<int> sorted(history.begin() + lo, history.begin() + end);
    std::sort(sorted.begin(), sorted.end());
    // Median
    double median = 0;
    if (sorted.size() % 2) {
      median = sorted[sorted.size() / 2];
    } else {
      int median_2_index = sorted.size() / 2;
      int median_1_index = median_2_index - 1;
      median = (sorted[median_1_index] + sorted[median_2_index]) / 2.;
    }
    //
    int current_day = history[end];
    if (current_day >= median * 2) ++count;
    ++lo;
  }

  return count;
}

int ActivityNotificationsTry2(std::vector<int>& expenditure, int d) {
  int count = 0;
  size_t lo = 0;
  size_t hi = expenditure.size();
  while (lo < hi) {
    size_t end = lo + d;
    if (end > expenditure.size() - 1) break;
    std::sort(expenditure.begin() + lo, expenditure.begin() + end);
    // Median
    double median = 0;
    if (d % 2) {
      median = expenditure[d / 2];
    } else {
      int median_2_index = expenditure[d / 2];
      int median_1_index = median_2_index - 1;
      median = (expenditure[median_1_index] + expenditure[median_2_index]) / 2.;
    }
    int current_day = expenditure[end];
    if (current_day >= median * 2) ++count;
    ++lo;
  }

  return count;
}

int ActivityNotifications(std::vector<int>& expenditure, int d) {
  int count = 0;
  std::vector<int> count_arr(201,
                             0);  // Assuming expenditures are between 0 and 200

  // Initialize the counting array for the first d days
  // For [1, 2, 3, 4, 4]
  // We have [0, 1, 1, 1, 1, 0, 0 ..]
  // For [2, 3, 4, 2, 3, 6, 8, 4, 5
  // We have [0, 0, 2, 2, 1, 0]
  for (int i = 0; i < d; i++) {
    ++count_arr[expenditure[i]];
  }

  auto find_median = [&count_arr, d](bool even) -> double {
    int count = 0;
    int first = 0;
    int second = 0;
    for (int i = 0; i < 201; ++i) {
      count += count_arr[i];
      if (even) {
        if (count == d / 2) {
          first = i;
        } else if (count > d / 2 && first != 0) {
          second = i;
          return (first + second) / 2.0;
        } else if (count > d / 2) {
          return i;
        }
      } else {
        if (count > d / 2) {
          return i;
        }
      }
    }
    return 0;  // This should never happen if the input is valid
  };

  for (size_t i = d; i < expenditure.size(); ++i) {
    double median = find_median(d % 2 == 0);

    if (expenditure[i] >= 2 * median) {
      ++count;
    }

    // Update the counting array
    --count_arr[expenditure[i - d]];
    ++count_arr[expenditure[i]];
  }

  return count;
}