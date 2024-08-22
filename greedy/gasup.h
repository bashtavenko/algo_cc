// 17.6 Gasup
//
// Given cities on the circular road, find an "ample" city, i.e. the one that
// will provide enough gas to go around
//
// Length of the road is 3,000 miles and vehicle get 20 m/g
//
// City  Fuel   Next city (miles)
// A    50      900
// B    20      600
// C    5       200
// D    30      400   => gets to E with
// E    25      600
// F    10      200
// G    10      100
//
// After clockwise
// Answer: D - can start without gas and complete the circle
//
// Does not work:
//- Start from a city with the most gas. A has most gas, but cannot get to C
//- Closest city
//- City with best distance to gas ratio
//
// Need to come to city with minimum of gas that could make the next trip
// B has 5 (50 - 45)
// C has -5 (5 -20 - 20)
// D has -10
#ifndef ALGO_CC_GREEDY_GASUP_H_
#define ALGO_CC_GREEDY_GASUP_H_
#include <cstdint>
#include <vector>

namespace algo {

int32_t FindAmpleCity(const std::vector<int32_t>& gallons,
                      const std::vector<int32_t>& distances);

}  // namespace algo

#endif  // ALGO_CC_GREEDY_GASUP_H_
