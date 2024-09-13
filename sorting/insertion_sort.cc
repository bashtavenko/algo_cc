#include "sorting/insertion_sort.h"
#include <cstdint>
#include <vector>

void SortInsertion(std::vector<int32_t>& data) {
  for (size_t i = 1; i < data.size(); ++i) {
    int j = i;
    while (j > 0 && data[j] < data[j - 1]) {
      std::swap(data[j], data[j - 1]);
      --j;
    }
  }
}
