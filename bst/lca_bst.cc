#include "bst/lca_bst.h"
#include <memory>
#include "bst/bst_node.h"

namespace algo {

BSTNode* FindLCA(BSTNode* node, int32_t n1, int32_t n2) {
  // Because it is iterative, we need a pointer as opposed to
  // reference
  while (node) {
    if (n1 < node->data && n2 < node->data) {
      node = node->left;
    } else if (n1 > node->data && n2 > node->data) {
      node = node->right;
    } else {
      return node;
    }
  }
  return nullptr;
}
};  // namespace algo
