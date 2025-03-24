// Given an array of occupied desks and the total number of desks, return the
// number of ways students can seat next to each other.
// The desks are arranged in one column with two seats.
//
#ifndef OCCUPIED_DESKS_H
#define OCCUPIED_DESKS_H
#include <cstdint>
#include <vector>

namespace algo {

int32_t OccupiedDesks(int32_t number_seats,
                      const std::vector<int32_t>& occupied_desks);

}  // namespace algo

#endif  // OCCUPIED_DESKS_H
