// Given the root of a binary tree and an integer targetSum, return the number
// of paths where the sum of the values along the path equals targetSum.
//
// The path does not need to start or end at the root or a leaf, but it must go
// downwards (i.e., traveling only from parent nodes to child nodes).
//
//
#ifndef ALGO_CC_BINARY_TREES_PATH_SUM_H_
#define ALGO_CC_BINARY_TREES_PATH_SUM_H_

#include "binary_trees/binary_tree_node.h"
#include "binary_trees/path_sum.h"

namespace algo {

int PathSum(const BinaryTreeNode* root, int target_sum);

}  // namespace algo

#endif  // ALGO_CC_BINARY_TREES_PATH_SUM_H_
