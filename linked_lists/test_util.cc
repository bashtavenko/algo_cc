#include "linked_lists/test_util.h"

namespace algo {

std::vector<int32_t> ConvertListToVector(
    const std::shared_ptr<ListNode>& head) {
  std::vector<int32_t> result;
  auto node = head;
  while (node) {
    result.emplace_back(node->data);
    node = node->next;
  }
  return result;
}

}  // namespace algo