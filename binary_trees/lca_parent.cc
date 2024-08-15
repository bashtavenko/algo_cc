#include "binary_trees/lca_parent.h"
#include <memory>

namespace algo {

int32_t GetDepth(const std::shared_ptr<BinaryTreeNode>& tree) {
  int32_t depth = 0;
  auto node = tree;
  while (node->parent.lock()) {
    ++depth;
    node = node->parent.lock();
  }
  return depth;
}

BinaryTreeNode* ComputeLca(const std::shared_ptr<BinaryTreeNode>& node_0,
                           const std::shared_ptr<BinaryTreeNode>& node_1) {
  // Binds refs
  auto iter_0 = node_0;
  auto iter_1 = node_1;

  // Makes iter_0 as the deepest node to simplify
  int32_t depth_0 = GetDepth(iter_0);
  int32_t depth_1 = GetDepth(iter_1);
  if (depth_1 > depth_0) std::swap(depth_0, depth_1);

  // Ascend from the deeper node.
  int32_t depth_diff = std::abs(depth_0 - depth_1);
  while (depth_diff--) {
    iter_0 = iter_0->parent.lock();
  }

  // Ascend from both until we reach LCA
  while (iter_0 != iter_1) {
    iter_0 = iter_0->parent.lock();
    iter_1 = iter_1->parent.lock();
  }
  return iter_0.get();
}

}  // namespace algo