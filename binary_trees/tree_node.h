#ifndef ALGO_CC_BINARY_TREES_TREE_NODE_H_
#define ALGO_CC_BINARY_TREES_TREE_NODE_H_

namespace leet_code {

struct TreeNode {
  int val;
  // Raw points are fine in a sample, but require ownership in test code and
  // each node must have std::unique_ptr and not temporary,
  // otherwise they need std::move.
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

}  //  namespace leet_code

#endif  // ALGO_CC_BINARY_TREES_TREE_NODE_H_
