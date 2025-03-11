// Given the root of a binary tree, the level of its root is 1, the level of its
// children is 2, and so on.
//
// Return the smallest level x such that the sum of all the values of nodes at
// level x is maximal.
// Input: root = [1,7,0,7,-8,null,null]
// Output: 2
// Explanation:
// Level 1 sum = 1.
// Level 2 sum = 7 + 0 = 7.
// Level 3 sum = 7 + -8 = -1.
#ifndef ALGO_CC_BINARY_TREES_MAX_LEVEL_SUM_H_
#define ALGO_CC_BINARY_TREES_MAX_LEVEL_SUM_H_
#include "binary_trees/binary_tree_node.h"

namespace algo {

int MaxLevelSum(BinaryTreeNode* root);

}

#endif  // ALGO_CC_BINARY_TREES_MAX_LEVEL_SUM_H_
