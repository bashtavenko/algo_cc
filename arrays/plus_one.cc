#include "arrays/plus_one.h"
#include <vector>

namespace algo {

std::vector<int32_t> PlusOne(const std::vector<int32_t>& data) {
  std::vector<int32_t> result(data.begin(), data.end());
  ++result.back();

  for (size_t i = result.size() - 1; i > 0 && result[i] == 10; --i) {
    result[i] = 0;
    ++result[i - 1];
  }

  if (result[0] == 10) {
    result[0] = 1;
    result.emplace_back(0);
  }

  return result;
}

}  // namespace algo
