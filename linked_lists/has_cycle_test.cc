#include "linked_lists/has_cycle.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"
#include "linked_lists/list_node.h"

namespace algo {
namespace {

// 1 -> 2 -> 3 -> 1
TEST(HasCycle, CycleWorks) {
  auto l1 = ListNode::Create(1);
  auto l2 = ListNode::Create(2);
  auto l3 = ListNode::Create(3);
  l1->next = l2;
  l2->next = l3;
  // Create a cycle
  l3->next = l1;

  std::shared_ptr<ListNode> head = l1;
  auto result = HasCycle(head);
  EXPECT_THAT(result, testing::NotNull());
  EXPECT_THAT(result->data, 1);
}

TEST(HasCycle, NoCycleWorks) {
  auto l1 = ListNode::Create(1);
  auto l2 = ListNode::Create(2);
  auto l3 = ListNode::Create(3);
  l1->next = l2;
  l2->next = l3;

  std::shared_ptr<ListNode> head = l1;
  auto result = HasCycle(head);
  EXPECT_THAT(result, testing::IsNull());
}

}  // namespace
}  // namespace algo
