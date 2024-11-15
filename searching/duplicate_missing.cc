#include "searching/duplicate_missing.h"
#include <cstdint>
#include <vector>

namespace algo {

DuplicateAndMissing FindDuplicateAndMissing(const std::vector<int32_t>& data) {
  size_t miss_xor_dup = 0;
  for (size_t i = 0; i < data.size(); ++i) {
    miss_xor_dup ^= i ^ data[i];
  }

  // for [5, 3, 0, 1, 2] we have 0x5 (0 1 0 1)
  // This bit-fiddling trick is similar to x &(x - 1)
  size_t differ_bit = miss_xor_dup & (~(miss_xor_dup - 1));
  // which it would be 0x1
  size_t miss_or_dup = 0;
  for (size_t i = 0; i < data.size(); ++i) {
    if (i & differ_bit) {
      miss_or_dup ^= i;
    }

    if (data[i] & differ_bit) {
      miss_or_dup ^= data[i];
    }
  }

  for (size_t i = 0; i < data.size(); ++i) {
    if (data[i] == data[miss_or_dup]) {
      return DuplicateAndMissing{.duplicate = miss_or_dup,
                                 .missing = miss_or_dup ^ miss_xor_dup};
    }
  }

  return DuplicateAndMissing{.duplicate = miss_or_dup ^ miss_xor_dup,
                             .missing = miss_or_dup};
}

}  // namespace algo