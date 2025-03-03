// Given a binary tree root, a node X in the tree is named good if in the path
// from root to X there are no nodes with a value greater than X.
//
// Return the number of good nodes in the binary tree.
//
#ifndef ALGO_CC_BINARY_TREES_GOOD_NODES_H_
#define ALGO_CC_BINARY_TREES_GOOD_NODES_H_

#include "binary_trees/tree_node.h"

namespace leet_code {

int GoogNodes(TreeNode* root);

}  // namespace leet_code

#endif  // ALGO_CC_BINARY_TREES_GOOD_NODES_H_
