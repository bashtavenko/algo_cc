#include "linked_lists/odd_even.h"
#include <memory>

namespace algo {

// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]
// 1, 3, 5
ListNode* OddEvenList(ListNode* head) {
  if (!head || !head->next) return head;

  // Initialize odd and even pointers.
  ListNode* odd = head;
  ListNode* even = head->next;
  ListNode* even_head = even;  // we need to connect even to odd at the end

  // Reorder the list.
  while (even && even->next) {
    odd->next = even->next;  // even->next == odd
    odd = odd->next;         // Advance odd pointer.
    even->next = odd->next;  // Same thing, odd->next == even
    even = even->next;       // Advance even pointer.
  }

  // Connect the end of the odd list to the head of the even list.
  odd->next = even_head;

  return head;
}

}  // namespace algo