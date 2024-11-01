#include "hacker_rank/one_month/week_3/reverse_list.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {
using ::testing::IsNull;
using ::testing::NotNull;

TEST(Reverse, Works) {
  auto node3 = std::make_shared<SinglyLinkedListNode>(3, nullptr);
  auto node2 = std::make_shared<SinglyLinkedListNode>(2, node3.get());
  auto head = std::make_shared<SinglyLinkedListNode>(1, node2.get());
  auto new_head = Reverse(head.get());
  EXPECT_THAT(new_head, NotNull());
  EXPECT_THAT(new_head->data, 3);
  EXPECT_THAT(new_head->next->data, 2);
  EXPECT_THAT(new_head->next->next->data, 1);
  EXPECT_THAT(new_head->next->next->next, IsNull());
}

TEST(DoubleReverse, Works) {
  auto node3 = std::make_shared<DoublyLinkedListNode>(3);
  auto node2 = std::make_shared<DoublyLinkedListNode>(2);
  auto head = std::make_shared<DoublyLinkedListNode>(1);
  head->next = node2.get();
  node2->prev = head.get();
  node2->next = node3.get();
  node3->prev = node2.get();

  auto new_head = Reverse(head.get());
  EXPECT_THAT(new_head, NotNull());
  EXPECT_THAT(new_head->data, 3);
  EXPECT_THAT(new_head->next->data, 2);
  EXPECT_THAT(new_head->next->next->data, 1);
  EXPECT_THAT(new_head->next->next->next, IsNull());
}

}  // namespace
