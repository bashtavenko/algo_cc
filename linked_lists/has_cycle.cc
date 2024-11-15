#include "linked_lists/has_cycle.h"
#include "linked_lists/list_node.h"
#include "unordered_set"

namespace algo {

std::shared_ptr<ListNode> HasCycleWithSet(
    const std::shared_ptr<ListNode>& head) {
  auto node = head;
  std::unordered_set<int32_t> set;

  while (node && node->next) {
    if (set.contains(node->data)) return node;
    set.emplace(node->data);
    node = node->next;
  }
  return nullptr;
}

// 1 -> 2 -> 3 -> 1
std::shared_ptr<ListNode> HasCycle(const std::shared_ptr<ListNode>& head) {
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