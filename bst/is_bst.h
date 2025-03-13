// 14.1 Check if BST.
//
// No key in the left is greater
//
// 1. Meaning we can check every node to lo/hi and
// start from -+ infinity
// is subtree bst
//
// 2. Do inorder traversal which means all keys
// should be in order. BFS. This is very straightforward with
// the same idea of lo and hi ranges.
//
#ifndef ALGO_CC_BST_IS_BST_H_
#define ALGO_CC_BST_IS_BST_H_

#include <memory>
#include "bst/bst_node.h"

namespace algo {

bool IsBinaryTreeBST(const BSTNode* tree);
bool IsBinaryTreeBFS(const BSTNode* tree);

}  // namespace algo

#endif  // ALGO_CC_BST_IS_BST_H_
