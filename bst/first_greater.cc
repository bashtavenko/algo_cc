#include "bst/first_greater.h"
#include <memory>
#include "bst/bst_node.h"

namespace algo {

BSTNode* FindFirstGreaterThanK(const std::unique_ptr<BSTNode>& tree,
                               int32_t k) {
  BSTNode* node = tree.get();
  BSTNode* result = nullptr;

  while (node) {
    if (node->data > k) {
      result = node;
      node = node->left.get();
    } else {
      // node->data <= k
      // At this point we have the previous in result
      // Ignore or break;
      node = node->right.get();
    }
  }

  return result;
}

}  // namespace algo