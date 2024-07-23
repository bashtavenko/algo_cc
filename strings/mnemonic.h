// 6.7 Compute mnemonic for the phone number
#ifndef ALGO_CC_STRINGS_MNEMONIC_H_
#define ALGO_CC_STRINGS_MNEMONIC_H_

#include <string>
#include <vector>
#include "absl/strings/string_view.h"

namespace algo {

std::vector<std::string> PhoneMnemonic(absl::string_view phone_number);

}  // namespace algo

#endif  // ALGO_CC_STRINGS_MNEMONIC_H_
