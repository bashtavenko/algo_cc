#include "graphs/dijkstra/index_min_priority_queue.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {
using ::testing::Optional;

TEST(IndexMinPriorityQueue, Works) {
  auto data = std::vector<double>{0.26, 0.38, 0.32, 0.40, 0.52};

  const auto n = data.size();
  auto pq = IndexMinPriorityQueue<double>(n);
  for (size_t i = 0; i < n; ++i) {
    pq.Insert(i, data[i]);
  }

  EXPECT_TRUE(pq.Contains(0));
  pq.Change(0, 0.1);
  EXPECT_THAT(pq.Min(), Optional(0.1));
  EXPECT_THAT(pq.DelMin(), 0.1);
  EXPECT_THAT(pq.Min(), Optional(0.32));
}

}  // namespace
}  // namespace algo