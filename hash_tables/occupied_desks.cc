#include "hash_tables/occupied_desks.h"
#include <unordered_set>

namespace algo {

int32_t OccupiedDesks(int32_t number_seats,
                      const std::vector<int32_t>& occupied_desks) {
  int32_t count = 0;
  const std::unordered_set<int32_t> layout(occupied_desks.begin(),
                                     occupied_desks.end());

  for (int i = 0; i < number_seats; ++i) {
    // Check horizontal pairs
    if (i % 2 && i + 1 < number_seats && !layout.contains(i) &&
        !layout.contains(i + 1)) {
      ++count;
    }

    // Check vertical pairs
    if (i + 2 <= number_seats && !layout.contains(i) &&
        layout.contains(i + 2)) {
      ++count;
    }
  }

  return count;
}

}  // namespace algo