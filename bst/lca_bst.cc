#include "bst/lca_bst.h"
#include <memory>
#include "bst/bst_node.h"

namespace algo {

BSTNode* FindLCA(const std::unique_ptr<BSTNode>& root, int32_t n1, int32_t n2) {
  // Because it is iterative, we need a pointer as opposed to
  // reference
  BSTNode* node = root.get();

  while (node->data < n1 || node->data > n2) {
    while (node->data < n1) {
      node = node->right.get();  // Too small, go right
    }

    while (node->data > n2) {
      node = node->left.get();  // Way too big, go left
    }
  }
  return node;
}
};  // namespace algo
