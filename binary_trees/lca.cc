#include "binary_trees/lca.h"
#include <functional>

namespace algo {

BinaryTreeNode* ComputeLca(BinaryTreeNode* root, BinaryTreeNode* p,
                           BinaryTreeNode* q) {
  struct Status {
    int32_t num_nodes;         // Number of p and q nodes
    BinaryTreeNode* ancestor;  // Accessor with both p and q nodes
  };

  std::function<Status(BinaryTreeNode*)> lca = [&](BinaryTreeNode* node) {
    if (!node) return Status{0, nullptr};
    const Status left_result = lca(node->left);
    if (left_result.num_nodes == 2) return left_result;
    const Status right_result = lca(node->right);
    if (right_result.num_nodes == 2) return right_result;

    const int32_t num_nodes = left_result.num_nodes + right_result.num_nodes +
                              (node == p) + (node == q);

    return Status{num_nodes, num_nodes == 2 ? node : nullptr};
  };

  return lca(root).ancestor;
}

}  // namespace algo
