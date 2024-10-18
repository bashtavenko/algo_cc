#include "hacker_rank/one_month/week_1/pangram.h"
#include <algorithm>
#include <string>
#include <vector>

bool Pangram(const std::string& s) {
  std::vector<int> count(26, 0);
  for (const char& ch : s) {
    if (std::isalpha(ch)) {
      ++count[std::tolower(ch) - 'a'];
    }
  }
  return std::all_of(count.begin(), count.end(), [](int v) { return v > 0; });
}