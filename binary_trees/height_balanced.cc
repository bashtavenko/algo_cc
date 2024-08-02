#include "binary_trees/height_balanced.h"
#include <memory>

namespace algo {

struct StatusHeight {
  bool balanced;
  int32_t height;
};

StatusHeight CheckBalanced(const std::unique_ptr<BinaryTreeNode>& tree) {
  if (tree == nullptr) return {true, -1};

  auto left_result = CheckBalanced(tree->left);
  if (!left_result.balanced) return {false, 0};

  auto right_result = CheckBalanced(tree->right);
  if (!right_result.balanced) return {false, 0};

  bool is_balanced = std::abs(left_result.height - right_result.height) <= 1;
  int32_t height = std::max(left_result.height, right_result.height) + 1;

  return {is_balanced, height};
}

bool IsBalanced(const std::unique_ptr<BinaryTreeNode>& tree) {
  return CheckBalanced(tree).balanced;
}
}  // namespace algo
