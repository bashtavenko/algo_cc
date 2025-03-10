#include "linked_lists/merge_sorted.h"

namespace algo {

ListNode* MergeTwoSorted(ListNode* l1, ListNode* l2) {
  // This dummy list node will be destroyed at the end of function
  auto dummy = std::make_unique<ListNode>(0);
  ListNode* tail = dummy.get();

  // Merge while both lists have nodes.
  while (l1 && l2) {
    if (l1->val <= l2->val) {
      tail->next = l1;
      l1 = l1->next;
    } else {
      tail->next = l2;
      l2 = l2->next;
    }
    tail = tail->next;
  }

  // Attach the remaining nodes.
  tail->next = l1 ? l1 : l2;

  ListNode* merged = dummy->next;
  // Maybe dummy.release() ?
  return merged;
}

}  // namespace algo