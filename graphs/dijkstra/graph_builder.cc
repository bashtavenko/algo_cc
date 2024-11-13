#include "graphs/dijkstra/graph_builder.h"

namespace algo {

void GraphBuilder::AddEdge(const algo::DirectedEdge& e) {
  if (!HasVertex(e.From())) {
    g_[e.From()] = absl::flat_hash_set<DirectedEdge, DirectedEdgeHash>();
  }
  if (!HasVertex(e.To())) {
    g_[e.To()] = absl::flat_hash_set<DirectedEdge, DirectedEdgeHash>();
  }
  g_[e.From()].insert(e);
}

EdgeWeightedDigraph& GraphBuilder::Graph() { return g_; }

bool GraphBuilder::HasVertex(int32_t v) { return g_.contains(v); }

}  // namespace algo
