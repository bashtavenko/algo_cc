// 9.1 Test if binary tree is height-balanced.
// For each node the difference between left and right subtree
// is at most one.
//
// Each node reports:
//  a) if it's balanced;
//  b) height of its children
// So we either have to add those two attributes to each node, or recurse and
// return them.
// Do post order (left, right, than root)
//    1
//  2   3    b: true h: 2
//    1
//  2        b: true h: 2

#ifndef ALGO_CC_BINARY_TREES_HEIGHT_BALANCED_H_
#define ALGO_CC_BINARY_TREES_HEIGHT_BALANCED_H_

#include <memory>
#include "binary_trees/binary_tree_node.h"

namespace algo {

bool IsBalanced(const BinaryTreeNode* tree);

}  // namespace algo

#endif  // ALGO_CC_BINARY_TREES_HEIGHT_BALANCED_H_
