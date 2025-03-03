#include "binary_trees/good_nodes.h"
#include <functional>
#include <numeric>
#include "binary_trees/tree_node.h"

namespace leet_code {

// On DFS in binary tree vs graph.
// In a binary tree, each node (except the root) has exactly one parent, and
// there are no cycles. This means that there's only one unique path from the
// root to any given node. When performing DFS on a tree, you naturally visit
// each node only once without the risk of re-entering a node via a different
// path.
//
// In contrast, a graph can have cycles or multiple paths leading to the same
// node, so a visited set is essential in DFS for graphs to prevent infinite
// loops and redundant processing.

int GoogNodes(TreeNode* root) {
  int count = 0;

  std::function<void(const TreeNode*, int)> dfs = [&](const TreeNode* node,
                                                      int cur_max) {
    if (!node) return;

    if (node->val >= cur_max) {
      ++count;
    }
    cur_max = std::max(cur_max, node->val);
    dfs(node->left, cur_max);
    dfs(node->right, cur_max);
  };

  dfs(root, root->val);
  return count;
}

}  // namespace leet_code