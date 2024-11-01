#include "linked_lists/test_util.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {

TEST(ConvertListToVector, Works) {
  auto l3 = ListNode::Create(3);
  auto l2 = ListNode::Create(2, l3);
  auto l1 = ListNode::Create(1, l2);

  EXPECT_THAT(ConvertListToVector(l1), testing::Eq(std::vector<int>{1, 2, 3}));
}

}  // namespace
}  // namespace algo