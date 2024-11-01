#include "hacker_rank/one_month/week_3/valid_string.h"
#include <string>
#include <unordered_map>

bool IsValidMayorityElement(const std::string& s) {
  // char:frequencies {'a' : 1, 'b' : 1, 'c' : 2}
  std::unordered_map<char, int> char_freq;
  for (const auto& c : s) {
    ++char_freq[c];
  }

  // Find majority element from frequencies
  auto majority_element = [&]() {
    int candidate;
    int candidate_count = 0;
    for (const auto& [_, count] : char_freq) {
      if (candidate_count == 0) {
        candidate = count;
        candidate_count = 1;
      } else if (candidate == count) {
        ++candidate_count;
      } else {
        --candidate_count;
      }
    }
    return candidate;
  };

  int count_from_majority = 0;
  int majority = majority_element();
  for (const auto& [_, count] : char_freq) {
    if (std::abs(majority - count) >= 1) ++count_from_majority;
  }

  return count_from_majority <= 1;
}

bool IsValid(const std::string& s) {
  std::unordered_map<char, int> char_freq;
  for (const auto& c : s) {
    ++char_freq[c];
  }

  // Frequency of frequencies
  std::unordered_map<int, int> freq_count;
  for (const auto& [_, count] : char_freq) {
    ++freq_count[count];
  }

  if (freq_count.size() == 1) {
    // All characters have the same frequency
    return true;
  }

  // We only care about frequency count of 2. Anything above 2 would be invalid.
  if (freq_count.size() == 2) {
    auto it = freq_count.begin();
    // Structured binding, nice trick.
    auto [freq_1, count_1] = *it++;
    auto [freq_2, count_2] = *it;

    // Check if one frequency is 1 and appears once
    if ((freq_1 == 1 && count_1 == 1) || (freq_2 == 1 && count_2 == 1)) {
      return true;
    }

    // Check if difference between frequencies is 1 and the larger one appears
    // only once
    if (std::abs(freq_1 - freq_2) == 1 && ((count_1 == 1 && freq_1 > freq_2) ||
                                           (count_2 == 1 && freq_2 > freq_1))) {
      return true;
    }
  }

  return false;
}