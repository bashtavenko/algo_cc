#include "strings/palidrome_index.h"
#include <cstdint>
#include "absl/strings/string_view.h"

namespace algo {

int32_t PalidromeIndex(absl::string_view s) {
  auto is_palidrome = [&](int32_t skip) {
    int32_t lo = 0;
    int32_t hi = s.size() - 1;
    while (lo < hi) {
      if (lo == skip) ++lo;
      if (hi == skip) --hi;
      if (lo < hi && s[lo] != s[hi]) return false;
      ++lo;
      --hi;
    }
    return true;
  };

  for (size_t i = 0; i < s.size(); ++i) {
    if (is_palidrome(i)) return i;
  }

  return -1;
}

}  // namespace algo
