#include "strings/mnemonic.h"
#include <functional>
#include <string>
#include <vector>

namespace algo {

// 0: "O", 1: "1", 2: "ABC", ...
const std::vector<std::string> kMapping = {
    {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"}};

std::vector<std::string> PhoneMnemonic(absl::string_view phone_number) {
  // Temporary buffer of 0 for the length of the phone number (one mnemonic)
  std::string partial(phone_number.size(), 0);
  std::vector<std::string> result;

  // If we had two keys, there could be a double for-loop. In 7 keys, it would
  // be a mess of 7 for-loops and that is why this recurses.
  // * digit for-loop index
  // * partial - temporary (last) mnemonic
  // * result
  std::function<void(absl::string_view, size_t)> run =
      [&](absl::string_view phone_number, size_t digit) {
        if (digit == phone_number.size()) {
          result.push_back(partial);
        } else {
          // Just one for-loop
          for (char8_t c : kMapping[phone_number[digit] - '0']) {
            (partial)[digit] = c;
            run(phone_number, digit + 1);
          }
        }
      };
  run(phone_number, 0);
  return result;
}
}  // namespace algo
