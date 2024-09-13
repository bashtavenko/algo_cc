#include "hacker_rank/arrays/minimum_swap.h"
#include <vector>

int InsertionSort(std::vector<int>& arr) {
  int swaps = 0;
  for (int i = 1; i < arr.size(); ++i) {
    int j = i;
    while (j > 0 && arr[j] < arr[j - 1]) {
      std::swap(arr[i], arr[j - 1]);
      ++swaps;
      --j;
    }
  }
  return swaps;
}

// 4, 3, 1, 2
// 1, 3, 4, 2 (0, 2)
// 1, 4, 3, 2 (1, 2)
// 1, 2, 3, 4 (1, 3)
int MinimumSwap(std::vector<int>& arr) { return InsertionSort(arr); }
