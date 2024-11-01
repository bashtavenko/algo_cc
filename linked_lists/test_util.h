#ifndef ALGO_CC_LINKED_LISTS_TEST_UTIL_H_
#define ALGO_CC_LINKED_LISTS_TEST_UTIL_H_
#include <vector>
#include "linked_lists/list_node.h"

namespace algo {

std::vector<int32_t> ConvertListToVector(const std::shared_ptr<ListNode>& head);

}  // namespace algo

#endif  // ALGO_CC_LINKED_LISTS_TEST_UTIL_H_
