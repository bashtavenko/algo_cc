// 7.2 Reverse a single sublist
// This could be done with stack stacks_queues/bootcamp_main.cc
#ifndef ALGO_CC_LINKED_LISTS_REVERSE_LIST_H_
#define ALGO_CC_LINKED_LISTS_REVERSE_LIST_H_
#include <memory>
#include "linked_lists/list_node.h"

namespace algo {

std::shared_ptr<ListNode> ReverseSublist(const std::shared_ptr<ListNode>& l,
                                         int32_t start, int32_t finish);

}  // namespace algo

#endif  // ALGO_CC_LINKED_LISTS_REVERSE_LIST_H_
