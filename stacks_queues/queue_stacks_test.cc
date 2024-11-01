#include "stacks_queues/queue_stacks.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {
using ::testing::Optional;

TEST(Queue, Works) {
  Queue q;
  q.Enqueue(1);
  q.Enqueue(2);
  q.Enqueue(3);

  EXPECT_THAT(q.Dequeue(), Optional(1));
  EXPECT_THAT(q.Dequeue(), Optional(2));
  EXPECT_THAT(q.Dequeue(), Optional(3));
  EXPECT_THAT(q.Dequeue(), std::nullopt);
}

}  // namespace
}  // namespace algo