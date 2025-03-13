#include "bst/reconstruct.h"
#include <algorithm>
#include <cstdint>
#include <memory>
#include <vector>
#include "bst/bst_node.h"

namespace algo_alternative {

std::unique_ptr<BSTNode> RebuildHelper(const std::vector<int32_t>& pre_order,
                                       size_t lo, size_t hi) {
  if (lo >= hi) return nullptr;

  int32_t root_value = pre_order[lo];
  // std::upper_bound finds the first element in the range that is greater than
  // the given value, which is exactly what we need for BST reconstruction
  // from a preorder traversal.
  auto it = std::upper_bound(pre_order.begin() + lo + 1, pre_order.begin() + hi,
                             root_value);
  size_t point = std::distance(pre_order.begin(), it);
  auto left_node = RebuildHelper(pre_order, lo + 1, point);
  auto right_node = RebuildHelper(pre_order, point, hi);
  return BSTNode::Create(pre_order[lo], std::move(left_node),
                         std::move(right_node));
}

std::unique_ptr<BSTNode> Reconstruct(const std::vector<int32_t> pre_order) {
  return RebuildHelper(pre_order, 0, pre_order.size());
}

}  // namespace algo_alternative