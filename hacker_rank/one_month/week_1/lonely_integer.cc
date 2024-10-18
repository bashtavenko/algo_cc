#include "hacker_rank/one_month/week_1/lonely_integer.h"

// Assuming that integers are between 1..100
int LonelyIntegerBasics(std::vector<int> arr) {
  std::vector<int> dups = std::vector<int>(100, 0);
  for (const auto& value : arr) {
    ++dups[value];
  }

  for (size_t i = 0; i < dups.size(); ++i) {
    if (dups[i] == 1) return i;
  }
  return -1;
}

// Iterating over an array, every element that appears twice cancels out,
// leaving only the element that appears once.
int LonelyInteger(std::vector<int> a) {
  int result = 0;
  for (const auto& value : a) {
    result ^= value;
  }
  return result;
}