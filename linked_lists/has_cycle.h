// 7.3 Test for cyclicity
//

#ifndef ALGO_CC_LINKED_LISTS_HAS_CYCLE_H_
#define ALGO_CC_LINKED_LISTS_HAS_CYCLE_H_

#include <memory>
#include "linked_lists/list_node.h"

namespace algo {

std::shared_ptr<ListNode> HasCycleWithSet(
    const std::shared_ptr<ListNode>& head);
std::shared_ptr<ListNode> HasCycle(const std::shared_ptr<ListNode>& head);

}  // namespace algo
#endif  // ALGO_CC_LINKED_LISTS_HAS_CYCLE_H_
