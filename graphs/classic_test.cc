#include "graphs/classic.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>

namespace algo {
namespace {

using testing::UnorderedElementsAreArray;

//   1 -> 2 -> 3 -> 4
//   | -------------^
//

TEST(Graph, BasicWorks) {
  Graph<int32_t> g;
  g.AddEdge(1, 2);
  g.AddEdge(2, 3);
  g.AddEdge(3, 4);
  g.AddEdge(1, 4);

  EXPECT_THAT(g.Size(), 4);

  const std::vector<int32_t> want_vertices{1, 2, 3, 4};
  EXPECT_THAT(g.GetVertices(), UnorderedElementsAreArray(want_vertices));

  const std::vector<int32_t> want_neighbors{2, 4};
  EXPECT_THAT(g.GetNeighbors(1), UnorderedElementsAreArray(want_neighbors));
  EXPECT_TRUE(g.IsReachableDFS(1, 4));

  const std::vector<int32_t> want_path{1, 4};
  EXPECT_THAT(g.ShortestPath(1, 4), UnorderedElementsAreArray(want_path));
  EXPECT_TRUE(g.IsReachableBFS(1, 3));
}

}  // namespace
}  // namespace algo