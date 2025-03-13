// 14.9 Build a minimum height BST from a sorted array.
//
// Find medium recursively.
#ifndef ALGO_CC_BST_MIN_HEIGHT_FROM_SORTED_H_
#define ALGO_CC_BST_MIN_HEIGHT_FROM_SORTED_H_
#include <vector>
#include "bst/bst_node.h"

namespace algo_alternative {

std::unique_ptr<BSTNode> BuildMinHeight(const std::vector<int32_t>& data);

}  // namespace algo_alternative

#endif  // ALGO_CC_BST_MIN_HEIGHT_FROM_SORTED_H_
