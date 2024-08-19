#include <memory>
#include <vector>
#include "bst/bst_node.h"

namespace algo {

void Traverse(const std::unique_ptr<BSTNode>& tree, size_t k,
              std::vector<int32_t>* result) {
  if (tree && result->size() < k) {    // Maybe don't need &&
    Traverse(tree->right, k, result);  // reverse in-order
    if (result->size() < k) {
      result->emplace_back(tree->data);
      Traverse(tree->left, k, result);
    }
  }
}

std::vector<int32_t> FindKLargestBst(const std::unique_ptr<BSTNode>& tree,
                                     size_t k) {
  std::vector<int32_t> result;
  Traverse(tree, k, &result);
  return result;
}

}  // namespace algo
