#include "strings/reformat_license_key.h"
#include <algorithm>

namespace algo {

std::string Reformat(absl::string_view s, int32_t k) {
  std::string result;
  result.reserve(s.size());

  int count = 0;
  for (int i = s.length() - 1; i >= 0; --i) {
    if (!std::isalnum(s[i])) continue;
    result += std::toupper(s[i]);
    ++count;
    if (count == k) {
      result += "-";
      count = 0;
    }
  }

  // Remove any trailing dash if present
  if (!result.empty() && result.back() == '-') {
    result.pop_back();
  }

  std::ranges::reverse(result);
  return result;
}

}  // namespace algo