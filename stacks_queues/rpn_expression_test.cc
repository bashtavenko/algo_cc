#include "stacks_queues/rpn_expression.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {

TEST(RpnExpression, Works) {
  EXPECT_THAT(Evaluate("2 3 *"), 6);
  EXPECT_THAT(Evaluate("2 3 * 6 /"), 1);
}

}  // namespace
}  // namespace algo