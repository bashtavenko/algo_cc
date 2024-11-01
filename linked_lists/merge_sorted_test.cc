#include "linked_lists/merge_sorted.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "linked_lists/test_util.h"

namespace algo {
namespace {
using ::testing::Eq;

TEST(MergeTwoSorted, Works) {
  auto l7 = ListNode::Create(7);
  auto l5 = ListNode::Create(5, l7);
  auto l2 = ListNode::Create(2, l5);
  auto first = l2;

  auto l11 = ListNode::Create(11);
  auto l3 = ListNode::Create(3, l11);
  auto second = l3;

  EXPECT_THAT(ConvertListToVector(MergeTwoSorted(first, second)),
              Eq(std::vector<int32_t>{2, 3, 5, 7, 11}));
}

}  // namespace
}  // namespace algo