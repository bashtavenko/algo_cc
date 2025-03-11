// 8.6 Compute binary tree nodes in order of increasing depth
#ifndef ALGO_CC_STACKS_QUEUES_BINARY_TREE_DEPTH_H_
#define ALGO_CC_STACKS_QUEUES_BINARY_TREE_DEPTH_H_
#include <vector>
#include "binary_trees/binary_tree_node.h"

namespace algo {

std::vector<std::vector<int32_t>> BinaryTreeDepthOrder(BinaryTreeNode* tree);

}  // namespace algo

#endif  // ALGO_CC_STACKS_QUEUES_BINARY_TREE_DEPTH_H_
