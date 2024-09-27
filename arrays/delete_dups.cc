#include "arrays/delete_dups.h"
#include <vector>

namespace algo {

size_t DeleteDuplicates(std::vector<int32_t>& data) {
  if (data.empty()) return 0;

  size_t write_index = 1;
  for (size_t i = 1; i < data.size(); ++i) {
    if (data[write_index - 1] != data[i]) {
      data[write_index++] = data[i];
    }
  }
  return write_index - 1;
}
}  // namespace algo