#include <numeric>
#include <queue>
#include "binary_trees/binary_tree_node.h"

namespace algo {

//     1               1
//  7      0           7
// 7 -8               -1
// [7 0
int MaxLevelSum(BinaryTreeNode* root) {
  if (!root) return 0;

  int max_sum = std::numeric_limits<int>::min();
  int level = 1;
  int best_level = 1;
  std::queue<BinaryTreeNode*> q;
  q.push(root);

  while (!q.empty()) {
    int level_sum = 0;
    int level_size = q.size();  // Number of nodes at the current level.

    for (int i = 0; i < level_size; ++i) {
      BinaryTreeNode* node = q.front();
      q.pop();
      level_sum += node->val;

      if (node->left) q.push((node->left));
      if (node->right) q.push(node->right);
    }

    if (level_sum > max_sum) {
      max_sum = level_sum;
      best_level = level;
    }
    ++level;
  }

  return best_level;
}

}  // namespace algo