#include "hacker_rank/one_month/week_2/caesar_cipher.h"
#include <string>

std::string CaesarCipher(const std::string& s, int k) {
  std::string result;
  for (const char& c : s) {
    if (std::isalpha(c)) {
      // There is no reason to have an explicit alphabet, just append to base.
      char base = std::islower(c) ? 'a' : 'A';
      char shifted = (c - base + k) % 26 + base;
      result += shifted;
    } else {
      result += c;  // Non-alphabetical characters remain unchanged
    }
  }

  return result;
}
