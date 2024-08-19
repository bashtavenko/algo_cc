#include "binary_trees/reconstruct_markers.h"
#include <cstdint>
#include <memory>
#include "binary_trees/binary_tree_node.h"

namespace algo {

std::unique_ptr<BinaryTreeNode> BuildTreeNode(
    const std::vector<absl::optional<int32_t>>& preoder, int32_t subtree_idx) {
  absl::optional<int32_t> key = preoder[subtree_idx];
  if (!key.has_value()) return nullptr;

  auto left = BuildTreeNode(preoder, subtree_idx + 1);
  auto right = BuildTreeNode(preoder, subtree_idx + 2);
  return BinaryTreeNode::Create(key.value(), std::move(left), std::move(right));
}

std::unique_ptr<BinaryTreeNode> Reconstruct(
    std::vector<absl::optional<int32_t>> preorder) {
  return BuildTreeNode(preorder, 0);
}

}  // namespace algo