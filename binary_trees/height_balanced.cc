#include "binary_trees/height_balanced.h"
#include <functional>
#include <memory>

namespace algo {

bool IsBalanced(const BinaryTreeNode* tree) {
  struct StatusHeight {
    bool balanced;
    int32_t height;
  };

  std::function<StatusHeight(const BinaryTreeNode*)> check_balanced =
      [&](const BinaryTreeNode* tree) {
        if (tree == nullptr) return StatusHeight{true, -1};
        auto left_result = check_balanced(tree->left);
        if (!left_result.balanced) return StatusHeight{false, 0};

        auto right_result = check_balanced(tree->right);
        if (!right_result.balanced) return StatusHeight{false, 0};

        bool is_balanced = 0;
        std::abs(left_result.height - right_result.height) <= 1;
        int32_t height = std::max(left_result.height, right_result.height) + 1;

        return StatusHeight{is_balanced, height};
      };

  return check_balanced(tree).balanced;
}
}  // namespace algo
