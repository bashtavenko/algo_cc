#include "hash_tables/nearest_repeated.h"
#include <cstdint>
#include <limits>
#include <string>
#include <vector>
#include "unordered_map"

namespace algo {

int32_t FindNearestRepeated(const std::vector<std::string>& tokens) {
  std::unordered_map<std::string, size_t> word_to_index;
  size_t nearest_distance = std::numeric_limits<size_t>::max();

  for (size_t i = 0; i < tokens.size(); ++i) {
    if (auto it = word_to_index.find(tokens[i]); it != word_to_index.end()) {
      // Found
      nearest_distance = std::min(nearest_distance, i - it->second);
    }
    word_to_index[tokens[i]] = i;
  }

  return nearest_distance != std::numeric_limits<int32_t>::max()
             ? nearest_distance
             : -1;
}

}  // namespace algo
