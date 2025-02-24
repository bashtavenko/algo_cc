#include "stacks_queues/decode_string.h"
#include <stack>

namespace algo {

// "3[a]2[bc]"
// "aaabcbc"
// stack numbers [3]
// stack val [a]
// multiple: 3
// value: a
// ]
// 3[a2[c]]
// accaccacc
std::string DecodeString(absl::string_view s) {
  std::stack<int32_t> numbers;
  std::stack<std::string> values;
  std::string result;
  int32_t k = 0;

  for (auto c : s) {
    if (std::isdigit(c)) {
      k = k * 10 + (c - '0');
    } else if (c == '[') {
      numbers.push(k);
      values.push(result);
      // Reset
      k = 0;
      result = "";
    } else if (c == ']') {
      int32_t multiplier = numbers.top();
      numbers.pop();
      std::string prev = values.top();
      values.pop();

      // Multiply
      std::string temp;
      for (int i = 0; i < multiplier; ++i) {
        temp += result;
      }
      result = prev + temp;
    } else {
      result += c;
    }
  }

  return result;
}

}  // namespace algo