#include "binary_trees/symmetric.h"
#include <memory>
#include "binary_trees/binary_tree_node.h"

namespace algo {

bool CheckSymmetric(const std::unique_ptr<BinaryTreeNode>& subtree_1,
                    const std::unique_ptr<BinaryTreeNode>& subtree_2) {
  if (subtree_1 == nullptr && subtree_2 == nullptr) {
    return true;
  } else if (subtree_1 != nullptr && subtree_2 != nullptr) {
    return subtree_1->data == subtree_2->data &&
           CheckSymmetric(subtree_1->left, subtree_2->right) &&
           CheckSymmetric(subtree_1->right, subtree_2->left);
  } else {
    // one subtree is nullptr
    return false;
  }
}

bool IsSymmetric(const std::unique_ptr<BinaryTreeNode>& tree) {
  return tree == nullptr || CheckSymmetric(tree->left, tree->right);
}

}  // namespace algo