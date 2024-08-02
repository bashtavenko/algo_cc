#include "stacks_queues/stack_max.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {
using testing::Optional;

TEST(StackMax, Works) {
  Stack stack;
  EXPECT_TRUE(stack.Empty());

  stack.Push(1);
  EXPECT_THAT(stack.Max(), Optional(1));

  stack.Push(2);
  EXPECT_THAT(stack.Max(), Optional(2));

  stack.Push(7);
  EXPECT_THAT(stack.Max(), Optional(7));

  stack.Push(4);
  EXPECT_THAT(stack.Max(), Optional(7));

  EXPECT_THAT(stack.Pop(), Optional(4));
  EXPECT_THAT(stack.Pop(), Optional(7));
  EXPECT_THAT(stack.Pop(), Optional(2));
  EXPECT_THAT(stack.Pop(), Optional(1));

  EXPECT_TRUE(stack.Empty());
}

}  // namespace
}  // namespace algo