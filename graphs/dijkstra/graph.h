// Common types for graphs
#ifndef ALGO_CC_GRAPHS_DIJKSTRA_GRAPH_H_
#define ALGO_CC_GRAPHS_DIJKSTRA_GRAPH_H_

#include <cstdint>
#include <ostream>
#include "absl/container/flat_hash_map.h"
#include "absl/container/flat_hash_set.h"

namespace algo {

struct DirectedEdge {
 public:
  DirectedEdge(int32_t v, int32_t w, double weight)
      : v_(v), w_(w), weight_(weight) {};

  int32_t From() const { return v_; }
  int32_t To() const { return w_; };
  double Weight() const { return weight_; }

  bool operator==(const DirectedEdge& that) const {
    return that.From() == v_ && that.To() == w_;
  }

  friend std::ostream& operator<<(std::ostream& os, const DirectedEdge& that) {
    os << that.v_ << "->" << that.w_ << " " << that.weight_;
    return os;
  }

 private:
  int32_t v_;
  int32_t w_;
  double weight_;
};

struct DirectedEdgeHash {
  size_t operator()(const DirectedEdge& edge) const {
    size_t h1 = std::hash<int32_t>()(edge.From());
    size_t h2 = std::hash<int32_t>()(edge.To());
    size_t h3 = std::hash<double>()(edge.Weight());
    return h1 ^ (h2 << 1) ^ (h3 << 2);
  }
};

using EdgeWeightedDigraph =
    absl::flat_hash_map<int32_t,
                        absl::flat_hash_set<DirectedEdge, DirectedEdgeHash>>;

}  // namespace algo
#endif  // ALGO_CC_GRAPHS_DIJKSTRA_GRAPH_H_
