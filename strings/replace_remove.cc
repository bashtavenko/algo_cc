#include "strings/replace_remove.h"
#include "cstdint"

namespace algo {

uint32_t ReplaceAndRemove(uint32_t size, char8_t s[]) {
  // Forward, left to write. Delete 'b'. Count 'a'.
  // Deletion requires write_idx;
  int32_t write_idx = 0;
  int32_t a_count = 0;
  for (uint32_t i = 0; i < size; ++i) {
    if (s[i] != 'b') {
      s[write_idx++] = s[i];
    }
    if (s[i] == 'a') ++a_count;
  }

  // Backward. Replace 'a' with "dd" starting from back.
  int cur_idx = write_idx - 1;
  write_idx = write_idx + a_count - 1;
  uint32_t const final_size = write_idx + 1;
  while (cur_idx >= 0) {
    if (s[cur_idx] == 'a') {
      s[write_idx--] = 'd';
      s[write_idx--] = 'd';
    } else {
      s[write_idx--] = s[cur_idx];
    }
    --cur_idx;
  }
  return final_size;
}

}  // namespace algo
