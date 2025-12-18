#include "linked_lists/has_cycle.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"
#include "linked_lists/list_node.h"

namespace algo {
namespace {
using ::testing::IsNull;
using ::testing::NotNull;

// 1 -> 2 -> 3 -> 1
TEST(HasCycle, CycleWorks) {
  auto l1 = std::make_unique<ListNode>(1);
  auto l2 = std::make_unique<ListNode>(2);
  auto l3 = std::make_unique<ListNode>(3);
  l1->next = l2.get();
  l2->next = l3.get();
  // Create a cycle
  l3->next = l1.get();

  ListNode* head = l1.get();
  auto result = HasCycle(head);
  EXPECT_THAT(result, NotNull());
  EXPECT_THAT(result->val, 1);
}


TEST(HasCycle, TemplatedCycleWorks) {
  auto l1 = std::make_unique<cycle::ListNode<int32_t>>(1);
  auto l2 = std::make_unique<cycle::ListNode<int32_t>>(2);
  auto l3 = std::make_unique<cycle::ListNode<int32_t>>(3);
  l1->next = l2.get();
  l2->next = l3.get();
  // Create a cycle
  l3->next = l1.get();

  cycle::ListNode<int32_t> * head = l1.get();
  auto result = cycle::HasCycleWithTemplatedSet<int32_t>(head);
  EXPECT_THAT(result, NotNull());
  EXPECT_THAT(result->val, 1);
}

TEST(HasCycle, NoCycleWorks) {
  auto l1 = std::make_unique<ListNode>(1);
  auto l2 = std::make_unique<ListNode>(2);
  auto l3 = std::make_unique<ListNode>(3);
  l1->next = l2.get();
  l2->next = l3.get();

  ListNode* head = l1.get();
  auto result = HasCycle(head);
  EXPECT_THAT(result, IsNull());
}

}  // namespace
}  // namespace algo
