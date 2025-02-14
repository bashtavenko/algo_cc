#include "stacks_queues/binary_tree_depth.h"
#include <queue>
#include <vector>
#include "binary_trees/binary_tree_node.h"

namespace algo {

std::vector<std::vector<int32_t>> BinaryTreeDepthOrder(
    const std::unique_ptr<BinaryTreeNode>& tree) {
  std::vector<std::vector<int32_t>> result;
  std::queue<BinaryTreeNode*> q({tree.get()});
  while (!q.empty()) {
    std::queue<BinaryTreeNode*> next_q;
    std::vector<int32_t> this_level;
    while (!q.empty()) {
      auto curr = q.front();
      q.pop();
      this_level.emplace_back(curr->data);

      if (curr->left) {
        next_q.emplace(curr->left.get());
      }
      if (curr->right) {
        next_q.emplace(curr->right.get());
      }
    }
    result.emplace_back(this_level);
    q = next_q;
  }

  return result;
}

}  // namespace algo