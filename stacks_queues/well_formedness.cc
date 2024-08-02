#include "stacks_queues/well_formedness.h"
#include <stack>
#include "absl/container/flat_hash_map.h"
#include "absl/strings/string_view.h"

namespace algo {

// In simple case of one or two tokens this can be done without stack.
bool IsWellFormed(absl::string_view s) {
  const absl::flat_hash_map<char8_t, char8_t> kDictionary = {
      {'{', '}'}, {'(', ')'}, {'[', ']'}};
  std::stack<char8_t> tokens;
  for (size_t i = 0; i < s.size(); ++i) {
    // std::unordered_map::count - returns the number of key elements
    if (kDictionary.count(s[i])) {
      tokens.emplace(s[i]);
    } else {
      if (tokens.empty() || kDictionary.at(tokens.top()) != s[i]) {
        // If we fail to pop up corresponding token, then it is not well-formed.
        return false;
      }
      tokens.pop();
    }
  }
  return tokens.empty();
}

}  // namespace algo