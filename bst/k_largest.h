// 14.3 Find the largest k-elements in BST
// We could do in-order traversal, put elements into queue of size k elements
// and return queue, but that would defeat the purpose of BST. It would process
// too many nodes that are not going to be a part of the result.
// Better approach is start from what we want_vertices which is the largest
// which ends up reverse in-order traversal
#ifndef ALGO_CC_BST_K_LARGEST_H_
#define ALGO_CC_BST_K_LARGEST_H_

#include <memory>
#include <vector>
#include "bst/bst_node.h"

namespace algo {

std::vector<int32_t> FindKLargestBst(const std::unique_ptr<BSTNode>& tree,
                                     size_t k);

}  // namespace algo

#endif  // ALGO_CC_BST_K_LARGEST_H_
