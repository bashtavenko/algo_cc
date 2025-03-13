// 14.5 Reconstruct BST.
// We need PRE-ORDER traversal sequence. Note that this binary SEARCH
// tree.
//
//
//      20
//   10        30
// 8    12  25    40
//
// 20, 10, 8, 12, 30, 25, 40
//
// Since it's PRE-ORDER, left subtree is whatever less than root,
// right is whatever is greater.
// Get 20, it's root, find index of first element greater than 20, that's 30
// Get 10, 8, 12, that's left subtree. Get 30, 25, 40, that's right subtree.
// Recurse
//
// This is only possible in BST and NOT a binary tree.
// For BINARY trees we need both pre-order and in-order or alternatively,
// pre-order with markers.
//
#ifndef ALGO_CC_BST_RECONSTRUCT_H_
#define ALGO_CC_BST_RECONSTRUCT_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "bst/bst_node.h"

namespace algo_alternative {

std::unique_ptr<BSTNode> Reconstruct(const std::vector<int32_t> pre_order);

}  // namespace algo_alternative

#endif  // ALGO_CC_BST_RECONSTRUCT_H_
