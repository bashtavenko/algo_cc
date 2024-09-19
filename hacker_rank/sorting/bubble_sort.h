// Given an array of integers, print the sort parameters.
//

#ifndef ALGO_CC_HASH_TABLES_SORTING_BUBBLE_SORT_H_
#define ALGO_CC_HASH_TABLES_SORTING_BUBBLE_SORT_H_

#include <vector>
#include "absl/strings/str_format.h"

struct SortResult {
  int num_swaps = 0;
  int first_element = 0;
  int last_element = 0;

  bool operator==(const SortResult& other) const {
    return num_swaps == other.num_swaps &&
           first_element == other.first_element &&
           last_element == other.last_element;
  }

  template <typename Sink>
  void AbslStringfy(Sink sink, const SortResult& result) {
    absl::Format(&sink, "%v", result);
  }

  friend std::ostream& operator<<(std::ostream& os, const SortResult& that) {
    os << absl::StrFormat("(%i, %i, %i)", that.num_swaps, that.first_element,
                          that.last_element);
    return os;
  }
};

SortResult CountSwaps(std::vector<int>& a);

#endif  // ALGO_CC_HASH_TABLES_SORTING_BUBBLE_SORT_H_
