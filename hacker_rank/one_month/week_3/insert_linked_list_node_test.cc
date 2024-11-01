#include "hacker_rank/one_month/week_3/insert_linked_list_node.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {
using ::testing::IsNull;
using ::testing::NotNull;

TEST(InsertNodeAtPosition, Works) {
  auto node3 = std::make_shared<SinglyLinkedListNode>(3, nullptr);
  auto node2 = std::make_shared<SinglyLinkedListNode>(2, node3.get());
  auto head = std::make_shared<SinglyLinkedListNode>(1, node2.get());
  auto new_head = InsertNodeAtPosition(head.get(), 4, 2);
  EXPECT_THAT(new_head, NotNull());
  EXPECT_THAT(new_head->data, 1);
  EXPECT_THAT(new_head->next->data, 2);
  EXPECT_THAT(new_head->next->next->data, 4);
  EXPECT_THAT(new_head->next->next->next->data, 3);
  EXPECT_THAT(new_head->next->next->next->next, IsNull());
}

}  // namespace