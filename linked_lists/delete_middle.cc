#include "linked_lists/delete_middle.h"
#include <cstdint>

namespace leet_code {

ListNode* DeleteMiddleThisWorks(ListNode* head) {
  if (!head || !head->next) return nullptr;

  int32_t count = 0;
  auto node = head;
  while (node) {
    ++count;
    node = node->next;
  }
  ListNode* middle = head;
  for (int32_t node_count = 1; node_count < count / 2; ++node_count) {
    middle = middle->next;
  }
  middle->next = middle->next->next;
  return head;
}

ListNode* DeleteMiddle(ListNode* head) {
  // If the list is empty or has only one node, return nullptr.
  if (!head || !head->next) return nullptr;

  ListNode* slow = head;
  ListNode* fast = head;
  ListNode* prev = nullptr;

  // Move fast two steps and slow one step until fast reaches the end.
  // If the list has n nodes, the fast pointer will cover approximately n nodes
  // by moving 2 steps at a time, while the slow pointer will cover about n/2
  // nodes, landing right at the middle.
  while (fast && fast->next) {
    fast = fast->next->next;
    prev = slow;
    slow = slow->next;
  }

  // Now, slow points to the middle node. Remove it.
  prev->next = slow->next;
  // Optionally, free slow if needed:
  // delete slow;

  return head;
}

}  // namespace leet_code