// 7.1 Merge two-sorted lists
//
#ifndef ALGO_CC_LINKED_LISTS_MERGE_SORTED_H_
#define ALGO_CC_LINKED_LISTS_MERGE_SORTED_H_
#include "linked_lists/list_node.h"

namespace algo {

std::shared_ptr<ListNode> MergeTwoSorted(const std::shared_ptr<ListNode>& l1,
                                         const std::shared_ptr<ListNode>& l2);

}  // namespace algo

#endif  // ALGO_CC_LINKED_LISTS_MERGE_SORTED_H_
