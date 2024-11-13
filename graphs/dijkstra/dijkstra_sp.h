// Dijkstra's shortest-path classic
#ifndef ALGO_CC_GRAPHS_DIJKSTRA_DIJKSTRA_SP_H_
#define ALGO_CC_GRAPHS_DIJKSTRA_DIJKSTRA_SP_H_
#include "absl/container/flat_hash_map.h"
#include "absl/container/flat_hash_set.h"
#include "graphs/dijkstra/graph.h"
#include "graphs/dijkstra/index_min_priority_queue.h"

namespace algo {

// For the given starting point s, returns distances to each vertex.
std::vector<double> ShortestPaths(const EdgeWeightedDigraph& graph, int32_t s);

}  // namespace algo

#endif  // ALGO_CC_GRAPHS_DIJKSTRA_DIJKSTRA_SP_H_
