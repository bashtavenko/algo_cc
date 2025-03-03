// Given the root of a binary tree and an integer targetSum, return the number
// of paths where the sum of the values along the path equals targetSum.
//
// The path does not need to start or end at the root or a leaf, but it must go
// downwards (i.e., traveling only from parent nodes to child nodes).
//
#include "binary_trees/path_sum.h"
#include <functional>
#include <unordered_map>
#include "binary_trees/tree_node.h"

namespace leet_code {

int PathSum(const TreeNode* root, int target_sum) {
  // Prefix sum technique
  // As you traverse from the root down to a node, we accumulate the sum of
  // node values along the way. This running total is called the cumulative sum
  // or prefix sum.
  // So like [a, a + b, a + b + c, a + b +c + d]

  std::unordered_map<long, int> prefix;
  prefix[0] = 1;
  std::function<long(const TreeNode*, long)> dfs = [&](const TreeNode* node,
                                                       long cur_sum) {
    if (!node) return 0;

    cur_sum += node->val;
    // Number of times a cumulative sum has been encountered
    int paths = prefix[cur_sum - target_sum];
    prefix[cur_sum]++;
    paths += dfs(node->left, cur_sum);
    paths += dfs(node->right, cur_sum);

    // Backtrack after we explore the current node, we have one node extra
    prefix[cur_sum]--;
    return paths;
  };

  return dfs(root, 0);
}

}  // namespace leet_code
