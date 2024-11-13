// Utility to make graphs
//
#ifndef ALGO_CC_GRAPHS_DIJKSTRA_GRAPH_BUILDER_H_
#define ALGO_CC_GRAPHS_DIJKSTRA_GRAPH_BUILDER_H_
#include "graphs/dijkstra/graph.h"

namespace algo {

// Holds graph. Needs to outlive other parts.
class GraphBuilder {
 public:
  GraphBuilder() {};
  void AddEdge(const DirectedEdge& e);
  EdgeWeightedDigraph& Graph();

 private:
  bool HasVertex(int32_t v);
  EdgeWeightedDigraph g_;
};

}  // namespace algo

#endif  // ALGO_CC_GRAPHS_DIJKSTRA_GRAPH_BUILDER_H_
