// """9.2 Write a program that checks that binary tree is symmetric.
//
// Meaning that corresponding nodes have the same values, but structurally the
// trees are the same.
//
#ifndef ALGO_CC_BINARY_TREES_SYMMETRIC_H_
#define ALGO_CC_BINARY_TREES_SYMMETRIC_H_
#include <memory>
#include "binary_trees/binary_tree_node.h"

namespace algo {

bool IsSymmetric(const BinaryTreeNode* tree);

}  // namespace algo

#endif  // ALGO_CC_BINARY_TREES_SYMMETRIC_H_
