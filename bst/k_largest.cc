#include <functional>
#include <memory>
#include <vector>
#include "bst/bst_node.h"

namespace algo {

std::vector<int32_t> FindKLargestBst(const BSTNode* tree,
                                     size_t k) {
  std::vector<int32_t> result;
  std::function<void(const BSTNode*)> reverse_in_order =
      [&](const BSTNode* node) {
        if (node) {
          reverse_in_order(node->right);
          if (result.size() < k) {
            result.emplace_back(node->data);
            reverse_in_order(node->left);
          }
        }
      };
  reverse_in_order(tree);
  return result;
}

}  // namespace algo
