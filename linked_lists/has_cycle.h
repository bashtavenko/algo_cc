// 7.3 Test for cyclicity
//

#ifndef ALGO_CC_LINKED_LISTS_HAS_CYCLE_H_
#define ALGO_CC_LINKED_LISTS_HAS_CYCLE_H_

#include "linked_lists/list_node.h"
#include <unordered_set>

namespace algo {
namespace cycle {

// Templated version of the linked list
template <typename T>
struct ListNode {
  T val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(T x) : val(x), next(nullptr) {}
  ListNode(T x, ListNode* next) : val(x), next(next) {}
};

template <typename T>
ListNode<T>* HasCycleWithTemplatedSet(ListNode<T>* head) {
  auto node = head;
  std::unordered_set<ListNode<T>*> set; // We store the pointers in the set.
  while (node && node->next) {
    if (set.contains(node)) return node; // Check for the pointer
    set.emplace(node);                   // Store the pointer
    node = node->next;
  }
  return nullptr;
}
} // namespace cycle

ListNode* HasCycleWithSet(ListNode* head);
ListNode* HasCycle(ListNode* head);

}  // namespace algo
#endif  // ALGO_CC_LINKED_LISTS_HAS_CYCLE_H_
