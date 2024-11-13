#include "graphs/dijkstra/dijkstra_sp.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "graphs/dijkstra/graph_builder.h"

namespace algo {
namespace {
using ::testing::UnorderedElementsAreArray;

TEST(ShortestPaths, Works) {
  auto edges = std::vector<DirectedEdge>{
      DirectedEdge(0, 1, 5.),  DirectedEdge(0, 4, 9.),  DirectedEdge(0, 7, 8.),
      DirectedEdge(1, 2, 12.), DirectedEdge(1, 3, 15.), DirectedEdge(1, 7, 4.),
      DirectedEdge(2, 3, 3.),  DirectedEdge(2, 6, 11.), DirectedEdge(3, 6, 9.),
      DirectedEdge(4, 5, 4.),  DirectedEdge(4, 6, 20.), DirectedEdge(4, 7, 5.),
      DirectedEdge(5, 2, 1.),  DirectedEdge(5, 6, 13.), DirectedEdge(7, 5, 6.),
      DirectedEdge(7, 2, 7.)};

  GraphBuilder gb;
  for (const auto& edge : edges) {
    gb.AddEdge(edge);
  }

  std::vector<double> dist_to = ShortestPaths(gb.Graph(), 0);
  EXPECT_THAT(dist_to, UnorderedElementsAreArray({0, 5, 14, 17, 9, 13, 25, 8}));
  EXPECT_THAT(dist_to[2], 14);  // 0 -> 4 -> 5 -> 2 is still better than 0 -> 7
}

}  // namespace
}  // namespace algo