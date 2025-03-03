// There are n cities. Some of them are connected, while some are not. If city a
// is connected directly with city b, and city b is connected directly with city
// c, then city a is connected indirectly with city c.
//
// A province is a group of directly or indirectly connected cities and no other
// cities off the group.
//
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
// ith city and the jth city are directly connected, and isConnected[i][j] = 0
// otherwise.
//
// Return the total number of provinces.
// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
#ifndef ALGO_CC_GRAPHS_CONNECTED_COMPONENTS_H_
#define ALGO_CC_GRAPHS_CONNECTED_COMPONENTS_H_
#include <cstdint>
#include <vector>

namespace algo {

int32_t FindConnectedComponents(
    const std::vector<std::vector<int32_t>>& matrix);

}  // namespace algo

#endif  // ALGO_CC_GRAPHS_CONNECTED_COMPONENTS_H_
