#include "linked_lists/merge_sorted.h"

namespace algo {

std::shared_ptr<ListNode> MergeTwoSorted(const std::shared_ptr<ListNode>& l1,
                                         const std::shared_ptr<ListNode>& l2) {
  auto first = l1;
  auto second = l2;
  auto dummy_head = ListNode::Create(0);
  auto tail = dummy_head;

  auto append_node = [&tail](std::shared_ptr<ListNode>& node) {
    tail->next = node;
    tail = node;
    node = node->next;
  };

  while (first && second) {
    append_node(first->data <= second->data ? first : second);
  }

  // Append remaining
  tail->next = first ? first : second;
  return dummy_head->next;
}

}  // namespace algo