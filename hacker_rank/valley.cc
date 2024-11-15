#include "hacker_rank/valley.h"
#include <vector>

// "UDDDUDUU"
int CountValleys(int steps, const std::string& path) {
  // Part 1 - convert path to vector
  std::vector<int> data;
  int level = 0;
  data.push_back(0);
  for (const auto& c : path) {
    if (c == 'U') {
      ++level;
    } else {
      --level;
    }
    data.push_back(level);
  }

  // Part 2 - find number of values;
  // [0, 1, 0, -1, -2, -1, -2, -1, 0]
  int number_of_valleys = 0;
  for (size_t i = 1; i < data.size(); ++i) {
    if (data[i] < data[i - 1]) {
      // Going down
      if (data[i - 1] == 0) {
        // Real valley
        ++number_of_valleys;
      }
    }
  }

  return number_of_valleys;
}

// Claude
int CountValleys2(int steps, const std::string& path) {
  int level = 0;
  int number_of_valleys = 0;

  for (char c : path) {
    int previous_level = level;
    level += (c == 'U') ? 1 : -1;

    if (previous_level == -1 && level == 0) {
      ++number_of_valleys;
    }
  }

  return number_of_valleys;
}