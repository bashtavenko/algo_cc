#include "stacks_queues/well_formedness.h"
#include <stack>
#include "absl/container/flat_hash_map.h"
#include "absl/strings/string_view.h"

namespace algo {

// In the simple case of one or two tokens, this can be done without a stack.
bool IsWellFormed(absl::string_view s) {
  const absl::flat_hash_map<char8_t, char8_t> kDictionary = {
      {'{', '}'}, {'(', ')'}, {'[', ']'}};
  std::stack<char8_t> tokens;
  for (auto& c : s) {
    // std::unordered_map::count - returns the number of key elements
    // or .contains
    if (kDictionary.count(c)) {
      tokens.emplace(c);
    } else {
      if (tokens.empty() || kDictionary.at(tokens.top()) != c) {
        // If we fail to pop up the corresponding token, then it is not well-formed.
        return false;
      }
      tokens.pop();
    }
  }
  return tokens.empty();
}

}  // namespace algo