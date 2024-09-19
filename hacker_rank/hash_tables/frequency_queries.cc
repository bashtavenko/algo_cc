#include "hacker_rank/hash_tables/frequency_queries.h"
#include <algorithm>
#include <unordered_map>
#include <vector>

std::vector<int> FreqQueryBruteForce(
    const std::vector<std::vector<int>>& queries) {
  // O(n^2) because of rebuilding hashmap
  std::vector<int> data;
  std::vector<int> result;
  for (const auto& query : queries) {
    int op = query[0];
    int value = query[1];
    if (op == 1) {
      data.push_back(value);
    } else if (op == 3) {
      std::unordered_map<int, int> freq;
      for (const int& v : data) {
        ++freq[v];
      }
      int found = 0;
      for (const auto& [_, f] : freq) {
        if (f == value) {
          found = 1;
          break;
        }
      }
      result.push_back(found);
    } else {
      data.erase(std::remove(data.begin(), data.end(), value), data.end());
    }
  }
  return result;
}

std::vector<int> FreqQuery(const std::vector<std::vector<int>>& queries) {
  std::unordered_map<int, int> value_freq;  // Frequency of each value
  std::unordered_map<int, int> freq_count;  // Count of each frequency
  std::vector<int> result;

  for (const auto& query : queries) {
    int op = query[0];
    int value = query[1];

    switch (op) {
      case 1: {  // Insert
        int old_freq = value_freq[value];
        ++value_freq[value];
        --freq_count[old_freq];
        ++freq_count[old_freq + 1];
        break;
      }
      case 2: {  // Delete
        if (value_freq[value] > 0) {
          int old_freq = value_freq[value];
          --value_freq[value];
          --freq_count[old_freq];
          ++freq_count[old_freq - 1];
        }
        break;
      }
      case 3: {  // Query
        result.push_back(freq_count[value] > 0 ? 1 : 0);
        break;
      }
    }
  }

  return result;
}