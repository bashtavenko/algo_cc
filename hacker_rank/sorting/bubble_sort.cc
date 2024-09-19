#include "hacker_rank/sorting/bubble_sort.h"
#include <vector>

SortResult CountSwaps(std::vector<int>& a) {
  SortResult result;
  for (size_t i = 0; i < a.size(); i++) {
    for (size_t j = 0; j < a.size() - 1; j++) {
      if (a[j] > a[j + 1]) {
        std::swap(a[j], a[j + 1]);
        ++result.num_swaps;
      }
    }
  }
  result.first_element = a.front();
  result.last_element = a.back();
  return result;
}
