#include "strings/max_vowels_substring.h"
#include <unordered_set>

namespace algo {

// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.
int32_t MaxVowelsDoubleForLoop(absl::string_view s, int32_t k) {
  // Assuming valid input

  static const std::unordered_set<char8_t> kVowels = {'a', 'e', 'i', 'o', 'u'};
  const int32_t n = s.size();
  int32_t max_vowels = 0;
  for (int32_t i = 0; i < n; ++i) {
    int32_t window_vowels_count = 0;
    for (int32_t j = 0; j < k; ++j) {
      if (i + j < n) {
        window_vowels_count += kVowels.contains(s[i + j]);
      }
    }
    max_vowels = std::max(max_vowels, window_vowels_count);
  }

  return max_vowels;
}

int32_t MaxVowels(absl::string_view s, int32_t k) {
  static const std::unordered_set<char8_t> kVowels = {'a', 'e', 'i', 'o', 'u'};
  int32_t window_vowels = 0;

  // Count vowels in the initial window
  for (int32_t i = 0; i < k; ++i) {
    window_vowels += kVowels.contains(s[i]);
  }

  int32_t max_vowels = 0;
  max_vowels = window_vowels;

  // Slide the window across the string
  for (int32_t i = k; i < s.size(); ++i) {
    window_vowels += kVowels.contains(s[i]);      // Add new character
    window_vowels -= kVowels.contains(s[i - k]);  // Remove old character
    max_vowels = std::max(max_vowels, window_vowels);
  }

  return max_vowels;
}

}  // namespace algo