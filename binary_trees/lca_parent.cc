#include "binary_trees/lca_parent.h"
#include <memory>

namespace algo {

BinaryTreeNode* ComputeLca(BinaryTreeNode* node_0, BinaryTreeNode* node_1) {
  // Binds refs
  auto iter_0 = node_0;
  auto iter_1 = node_1;

  auto get_depth = [&](const BinaryTreeNode* node) {
    int32_t depth = 0;
    while (node->parent) {
      ++depth;
      node = node->parent;
    }
    return depth;
  };

  // Makes iter_0 as the deepest node to simplify
  int32_t depth_0 = get_depth(iter_0);
  int32_t depth_1 = get_depth(iter_1);
  if (depth_1 > depth_0) std::swap(depth_0, depth_1);

  // Ascend from the deeper node.
  int32_t depth_diff = std::abs(depth_0 - depth_1);
  while (depth_diff--) {
    iter_0 = iter_0->parent;
  }

  // Ascend from both until we reach LCA
  while (iter_0 != iter_1) {
    iter_0 = iter_0->parent;
    iter_1 = iter_1->parent;
  }
  return iter_0;
}

}  // namespace algo
