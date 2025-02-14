#include "linked_lists/reverse_list.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "linked_lists/test_util.h"

namespace algo {
namespace {
using ::testing::Eq;

TEST(ReverseSublist, Works) {
  auto l3 = ListNode::Create(3);
  auto l2 = ListNode::Create(2, l3);
  auto l1 = ListNode::Create(1, l2);

  EXPECT_THAT(ConvertListToVector(ReverseSublist(l1, 1, 3)),
              Eq(std::vector<int32_t>{3, 2, 1}));
}

}  // namespace
}  // namespace algo