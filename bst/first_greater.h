// 14.2 Find the first key greater than a given value in BST.
//                 43
//          29           47
//      23       37         53
// k = 23. Result = 29
// 1. Brute force: in-order walk
//    23 29 37 43 47 53
// 2. In-order walk iteratively.
//    Keeping where we came from.
//    Sort of binary search.

#ifndef ALGO_CC_BST_FIRST_GREATER_H_
#define ALGO_CC_BST_FIRST_GREATER_H_
#include <memory>
#include "bst/bst_node.h"

namespace algo {

BSTNode* FindFirstGreaterThanK(BSTNode* tree, int32_t k);

}  // namespace algo

#endif  // ALGO_CC_BST_FIRST_GREATER_H_
