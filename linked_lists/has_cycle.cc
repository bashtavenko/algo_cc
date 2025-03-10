#include "linked_lists/has_cycle.h"
#include "linked_lists/list_node.h"
#include "unordered_set"

namespace algo {

ListNode* HasCycleWithSet(ListNode* head) {
  auto node = head;
  std::unordered_set<int32_t> set;

  while (node && node->next) {
    if (set.contains(node->val)) return node;
    set.emplace(node->val);
    node = node->next;
  }
  return nullptr;
}

// 1 -> 2 -> 3 -> 1
ListNode* HasCycle(ListNode* head) {
  // slow goes to the one
  // fast can jump more than one
  auto slow = head;
  auto fast = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;

    // Sooner or later during cycling slow can reach fast
    if (slow == fast) {
      return slow;
    }
  }
  return nullptr;
}

}  // namespace algo