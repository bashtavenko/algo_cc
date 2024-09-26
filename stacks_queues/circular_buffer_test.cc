#include "stacks_queues/circular_buffer.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {
using testing::Eq;
using testing::Optional;

TEST(CircularBuffer, Works) {
  CircularBuffer buffer(3);
  ASSERT_THAT(buffer.Size(), 0);
  buffer.Enqueue(3);
  buffer.Enqueue(5);
  buffer.Enqueue(7);
  buffer.Enqueue(11);
  buffer.Enqueue(11);
  ASSERT_THAT(buffer.Size(), 5);
  EXPECT_THAT(buffer.Dequeue(), Optional(3));
  EXPECT_THAT(buffer.Dequeue(), Optional(5));
  ASSERT_THAT(buffer.Size(), 3);
}

TEST(CircularBufferBasic, Works) {
  CircularBufferBasic buffer(3);
  buffer.Push(1);
  buffer.Push(2);
  buffer.Push(3);
  EXPECT_TRUE(buffer.Full());
  EXPECT_THAT(buffer.Size(), 3);
  EXPECT_THAT(buffer.Pop(), Optional(1));
  EXPECT_FALSE(buffer.Full());
  EXPECT_THAT(buffer.Size(), 2);
  // We have [2, 3]
  buffer.Push(10);
  buffer.Push(11);
  // We have [3, 10, 11]
  EXPECT_THAT(buffer.Pop(), Optional(3));
  EXPECT_THAT(buffer.Pop(), Optional(10));
  EXPECT_THAT(buffer.Pop(), Optional(11));
  EXPECT_THAT(buffer.Pop(), Eq(absl::nullopt));
}

}  // namespace
}  // namespace algo
