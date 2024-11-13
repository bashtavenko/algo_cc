#include "graphs/dijkstra/graph_builder.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {
using ::testing::UnorderedElementsAreArray;

TEST(GraphBuilder, Works) {
  auto edges = std::vector<DirectedEdge>{
      DirectedEdge(0, 2, 0.26), DirectedEdge(0, 4, 0.38),
      DirectedEdge(1, 3, 0.29), DirectedEdge(2, 7, 0.34),
      DirectedEdge(3, 6, 0.52), DirectedEdge(4, 7, 0.37),
      DirectedEdge(4, 5, 0.35), DirectedEdge(5, 1, 0.32),
      DirectedEdge(5, 7, 0.28), DirectedEdge(5, 4, 0.35),
  };

  GraphBuilder gb;
  for (const auto& edge : edges) {
    gb.AddEdge(edge);
  }
  auto neighbors = std::vector<DirectedEdge>(gb.Graph().at(5).begin(),
                                             gb.Graph().at(5).end());

  EXPECT_THAT(neighbors, UnorderedElementsAreArray(std::vector<DirectedEdge>{
                             DirectedEdge(5, 1, 0.32), DirectedEdge(5, 7, 0.28),
                             DirectedEdge(5, 4, 0.35)}));
}

}  // namespace
}  // namespace algo