// 9.13 Reconstruct binary tree with preorder traversals and markers
//   1
// 2   3
//
// 1, 2, {}, {}, 3, {}, {}
//

#ifndef ALGO_CC_BINARY_TREES_RECONSTRUCT_MARKERS_H_
#define ALGO_CC_BINARY_TREES_RECONSTRUCT_MARKERS_H_

#include <cstdint>
#include <memory>
#include <vector>
#include "absl/types/optional.h"
#include "binary_trees/binary_tree_node.h"

namespace algo_alternative {

std::unique_ptr<BinaryTreeNode> Reconstruct(
    std::vector<absl::optional<int32_t>> preoder);

}  // namespace algo_alternative

#endif  // ALGO_CC_BINARY_TREES_RECONSTRUCT_MARKERS_H_
