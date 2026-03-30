#include "hash_tables/palidrom.h"
#include "absl/container/flat_hash_set.h"

#include <string_view>

namespace algo {

bool CanFormPalidrome(std::string_view s) {
  absl::flat_hash_set<char8_t> single_chars;
  for (char8_t c : s) {
    // Invariant - keep single_chars single.
    if (single_chars.count(c)) {
      single_chars.erase(c);  // wipe out this char
    } else {
      single_chars.insert(c);
    }
  }

  return single_chars.size() <= 1;
}

}  // namespace algo
