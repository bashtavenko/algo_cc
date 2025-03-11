#include "binary_trees/reconstruct_markers.h"
#include <cstdint>
#include <functional>
#include <memory>
#include "binary_trees/binary_tree_node.h"

namespace algo_alternative {

std::unique_ptr<BinaryTreeNode> Reconstruct(
    std::vector<absl::optional<int32_t>> preorder) {
  std::function<std::unique_ptr<BinaryTreeNode>(int32_t)> build_node =
      [&](int32_t subtree_idx) {
        absl::optional<int32_t> key = preorder[subtree_idx];
        if (!key.has_value()) return BinaryTreeNode::Create(-1);

        auto left = build_node(subtree_idx + 1);
        auto right = build_node(subtree_idx + 2);
        return BinaryTreeNode::Create(key.value(), std::move(left),
                                      std::move(right));
      };

  return build_node(0);
}

}  // namespace algo_alternative