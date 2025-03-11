// 9.12 Reconstruct a binary tree from traversal data.
//   1
// 2   3
// PRE: 1, 2, 3
// I:    2, 1, 3
//
//       1
//   2        3
// 4    5   6   7
//   8
//
// PRE: 1, 2, 4, 8, 5, 3, 6, 7
// I:   4, 8, 2, 5, 1, 6, 3, 7
//
// Must have BOTH pre-order and in-order.
// 1. Find the first element in pre-order, that's root
// 2. Find matching element in in-order, these are left and right branches
// 3. Recurse
//
// Since this is binary tree, we can't get away with just pre-order along since
// we don't know if nodes are less or greater.
//
// The only way to reconstruct binary tree from just pre-order is to store
// pre-order marker a, b, None, None.

#ifndef ALGO_CC_BINARY_TREES_RECONSTRUCT_H_
#define ALGO_CC_BINARY_TREES_RECONSTRUCT_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "binary_trees/binary_tree_node.h"

namespace algo_alternative {

// This requires a BinaryTreeNode which owns data
std::unique_ptr<BinaryTreeNode> Reconstruct(
    const std::vector<int32_t>& preorder, const std::vector<int32_t>& inorder);

}  // namespace algo_alternative
#endif  // ALGO_CC_BINARY_TREES_RECONSTRUCT_H_
