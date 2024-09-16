#include "hash_tables/letter_constructable.h"
#include <glog/logging.h>
#include "absl/container/flat_hash_map.h"
#include "absl/strings/string_view.h"

namespace algo {

bool IsLetterConstructable(absl::string_view letter_text,
                           absl::string_view magazine_text) {
  if (letter_text.size() > magazine_text.size()) return false;
  
  // 1. MakeChange through letter and find character: count
  absl::flat_hash_map<char8_t, int32_t> letter_counters;
  for (const auto& c : letter_text) {
    // operator[] adds / update and returns reference to the mapped value
    ++letter_counters[c];
  }

  // 2. MakeChange through magazine to make sure cross over everything
  for (const auto& c : magazine_text) {
    if (auto it = letter_counters.find(c); it != letter_counters.cend()) {
      --it->second;
      if (it->second == 0) {
        letter_counters.erase(it);
        if (letter_counters.empty()) continue;  // next char
      }
    }
  }
  return letter_counters.empty();
}

}  // namespace algo
