#include "hacker_rank/arrays/minimum_swap.h"
#include <vector>

// Insertion sort makes more swaps than necessary.
// It is not needed because the input has consecutive integers.
void InsertionSort(std::vector<int>& arr) {
  int swaps = 0;
  for (size_t i = 0; i < arr.size(); ++i) {
    int j = i;
    while (j > 0 && arr[j] < arr[j - 1]) {
      std::swap(arr[j], arr[j - 1]);
      ++swaps;
    }
  }
}

// 4, 3, 1, 2
// 1, 3, 4, 2 (0, 2)
// 1, 4, 3, 2 (1, 2)
// 1, 2, 3, 4 (1, 3)
int MinimumSwap(std::vector<int>& arr) {
  int swaps = 0;
  // Because arrays has consecutive integers, no need for insertion sort.
  for (size_t i = 0; i < arr.size(); ++i) {
    while (arr[i] != static_cast<int>(i + 1)) {
      int temp = arr[i];
      std::swap(arr[i], arr[temp - 1]);
      ++swaps;
    }
  }
  return swaps;
}
