#include "graphs/dijkstra/dijkstra_sp.h"
#include <limits>
#include "graphs/dijkstra/index_min_priority_queue.h"

namespace algo {

std::vector<double> ShortestPaths(const EdgeWeightedDigraph& graph, int32_t s) {
  const size_t vertices = graph.size();
  std::vector<double> dist_to(vertices, std::numeric_limits<double>::max());
  dist_to[s] = 0.0;
  auto pq = IndexMinPriorityQueue<double>(vertices);
  pq.Insert(s, 0.0);

  auto relax = [&](int32_t v) {
    const auto& edges = graph.at(v);
    for (const DirectedEdge& e : edges) {
      int32_t w = e.To();
      const double new_dist = dist_to[v] + e.Weight();
      if (dist_to[w] > new_dist) {
        dist_to[w] = new_dist;
        if (pq.Contains(w)) {
          pq.Change(w, dist_to[w]);
        } else {
          pq.Insert(w, dist_to[w]);
        }
      }
    }
  };

  while (!pq.Empty()) {
    int32_t min_vertex = pq.DelMin();
    relax(min_vertex);
  }
  return dist_to;
}

}  // namespace algo
