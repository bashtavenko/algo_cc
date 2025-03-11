// 9.4 Compute LCA when nodes have parent nodes
// A brute force is to store nodes from the first tree in a hashtable
// {node:parent}. Then walk through the second tree to until the parent is
// in a hashtable.
// Alternatively, walk both trees if they are at the same depth which would
// require: 1) Find depth; 2) Align both and finally walk up.

#ifndef ALGO_CC_BINARY_TREES_LCA_PARENT_H_
#define ALGO_CC_BINARY_TREES_LCA_PARENT_H_

#include <memory>
#include "binary_trees/binary_tree_node.h"

namespace algo {

BinaryTreeNode* ComputeLca(BinaryTreeNode* node_0, BinaryTreeNode* node_1);
}  // namespace algo

#endif  // ALGO_CC_BINARY_TREES_LCA_PARENT_H_
