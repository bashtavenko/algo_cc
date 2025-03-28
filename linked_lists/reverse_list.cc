#include "linked_lists/reverse_list.h"
#include <functional>
#include "linked_lists/list_node.h"

namespace algo {

ListNode* ReverseSublist(ListNode* l, int32_t start, int32_t finish) {
  auto dummy_head = std::make_unique<ListNode>(0);
  auto sublist_head = dummy_head.get();
  sublist_head->next = l;

  for (int k = 1; k < start; ++k) {
    sublist_head = sublist_head->next;
  }

  // Reversing
  auto node = sublist_head->next;
  while (start < finish) {
    // For 1 -> 2 -> 3 => 3 -> 2 -> 1
    // temp = 2
    // iter(next) = 3
    // temp(next) = 1
    // 1 - 3
    auto temp = node->next;
    node->next = temp->next;
    temp->next = sublist_head->next;
    sublist_head->next = temp;
    ++start;
  }

  return dummy_head->next;
}

}  // namespace algo
