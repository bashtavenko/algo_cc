#include "stacks_queues/circular_buffer.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {

TEST(CircularBuffer, Works) {
  CircularBuffer buffer(3);
  ASSERT_THAT(buffer.Size(), 0);
  buffer.Enqueue(3);
  buffer.Enqueue(5);
  buffer.Enqueue(7);
  buffer.Enqueue(11);
  buffer.Enqueue(11);
  ASSERT_THAT(buffer.Size(), 5);
  EXPECT_THAT(buffer.Dequeue(), testing::Optional(3));
  EXPECT_THAT(buffer.Dequeue(), testing::Optional(5));
  ASSERT_THAT(buffer.Size(), 3);
}

}  // namespace
}  // namespace algo
