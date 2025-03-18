#ifndef LCA_H
#define LCA_H
#include "binary_tree_node.h"

namespace algo {

// Recursively move from root while returning
// the number of p and q nodes plus what was before
// As soon as we see the number of nodes of two, return
BinaryTreeNode* ComputeLca(BinaryTreeNode* root, BinaryTreeNode* p,
                           BinaryTreeNode* q);

}  // namespace algo

#endif  // LCA_H
