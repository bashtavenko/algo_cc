#include "stacks_queues/remove_stars.h"
#include <algorithm>
#include <stack>

namespace algo {

// leet**cod*e"
// "lecoe"
// stack: eocel
std::string RemoveStars(absl::string_view s) {
  // Assume valid string

  // Or... it can be with std::string.
  // It has push_back and pop_back
  std::stack<char8_t> chars;
  for (char8_t c : s) {
    if (c == '*') {
      if (!chars.empty()) chars.pop();
    } else {
      chars.push(c);
    }
  }
  std::string result;
  while (!chars.empty()) {
    result += chars.top();
    chars.pop();
  }
  std::reverse(result.begin(), result.end());
  return result;
}

}  // namespace algo