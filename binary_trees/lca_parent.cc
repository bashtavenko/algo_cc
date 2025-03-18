#include "binary_trees/lca_parent.h"
#include <memory>

namespace algo {

BinaryTreeNode* ComputeLca(BinaryTreeNode* node_0, BinaryTreeNode* node_1) {
  auto get_depth = [&](const BinaryTreeNode* node) {
    int32_t depth = 0;
    while (node->parent) {
      ++depth;
      node = node->parent;
    }
    return depth;
  };

  // Makes iter_0 as the deepest node to simplify
  int32_t depth_0 = get_depth(node_0);
  int32_t depth_1 = get_depth(node_1);
  if (depth_1 > depth_0) std::swap(depth_0, depth_1);

  // Ascend from the deeper node.
  int32_t depth_diff = std::abs(depth_0 - depth_1);
  while (depth_diff--) {
    node_0 = node_0->parent;
  }

  // Ascend from both until we reach LCA
  while (node_0 != node_1) {
    node_0 = node_0->parent;
    node_1 = node_1->parent;
  }
  return node_0;
}

}  // namespace algo
