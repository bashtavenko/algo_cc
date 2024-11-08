// The Mayor wants to install radio transmitters on the roofs of the city's
// houses. Each transmitter has a fixed range meaning it can transmit a signal
// to all houses within that number of units distance away.
//
// Given a map and transmission range, determine the minimum
// number of transmitters so that every house is within range of at least one
// transmitter. Each transmitter must be installed on top of an existing house.
//
// Example:
// [1, 2, 3, 5, 9] and k = 1
// There are three transmitters that cover the whole city [1, 2, 3], [5], [9]
#ifndef ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_4_TRANSMITTERS_H_
#define ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_4_TRANSMITTERS_H_
#include <vector>
int Transmitters(std::vector<int> x, int k);

#endif  // ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_4_TRANSMITTERS_H_
