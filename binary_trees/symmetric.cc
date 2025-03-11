#include "binary_trees/symmetric.h"
#include <functional>
#include "binary_trees/binary_tree_node.h"

namespace algo {

bool IsSymmetric(const BinaryTreeNode* tree) {
  std::function<bool(const BinaryTreeNode*, const BinaryTreeNode*)> check =
      [&](const BinaryTreeNode* subtree_1, const BinaryTreeNode* subtree_2) {
        if (subtree_1 == nullptr && subtree_2 == nullptr) {
          return true;
        } else if (subtree_1 != nullptr && subtree_2 != nullptr) {
          return subtree_1->val == subtree_2->val &&
                 check(subtree_1->left, subtree_2->right) &&
                 check(subtree_1->right, subtree_2->left);
        } else {
          // one subtree is nullptr
          return false;
        }
      };
  return tree == nullptr || check(tree->left, tree->right);
}

}  // namespace algo