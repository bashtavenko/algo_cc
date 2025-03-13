#include "bst/first_greater.h"
#include <memory>
#include "bst/bst_node.h"

namespace algo {

BSTNode* FindFirstGreaterThanK(BSTNode* node, int32_t k) {
  BSTNode* result = nullptr;

  while (node) {
    if (node->data > k) {
      result = node;
      node = node->left;
    } else {
      // node->data <= k
      // At this point we have the previous in result
      // Ignore or break;
      node = node->right;
    }
  }

  return result;
}

}  // namespace algo