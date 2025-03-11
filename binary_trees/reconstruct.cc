#include "binary_trees/reconstruct.h"
#include <cstdint>
#include <functional>
#include <memory>
#include <vector>
#include "absl/container/flat_hash_map.h"
#include "binary_trees/binary_tree_node.h"

namespace algo_alternative {

std::unique_ptr<BinaryTreeNode> Reconstruct(
    const std::vector<int32_t>& preorder, const std::vector<int32_t>& inorder) {
  // Because we are going to query inorder for a particular value,
  // it is more efficient to store the position of each element.
  // [2, 1, 3] => {{2: 0}, {1: 1}, {3: 2}}
  absl::flat_hash_map<int32_t, size_t> node_to_idx;
  for (size_t i = 0; i < inorder.size(); ++i) {
    node_to_idx.emplace(inorder[i], i);
  }

  std::function<std::unique_ptr<BinaryTreeNode>(size_t, size_t, size_t, size_t)>
      dfs = [&](size_t preorder_start, size_t preorder_end,
                size_t inorder_start, size_t inorder_end) {
        if (preorder_start >= preorder_end || inorder_start >= inorder_end)
          return BinaryTreeNode::Create(-1);

        size_t root_inorder_idx = node_to_idx.at(preorder[preorder_start]);
        size_t left_subtree_size = root_inorder_idx - inorder_start;

        auto left = dfs(/*preorder_start=*/preorder_start + 1,
                        /*preorder_end=*/preorder_start + 1 + left_subtree_size,
                        inorder_start, root_inorder_idx);
        auto right = dfs(
            /*preorder_start=*/preorder_start + 1 + left_subtree_size,
            /* preorder_end=*/preorder_end, root_inorder_idx + 1, inorder_end);

        return BinaryTreeNode::Create(/*value=*/preorder[preorder_start],
                                      std::move(left), std::move(right));
      };

  return dfs(/* preorder_start=*/0,
             /*preorder_end=*/preorder.size(),
             /*inorder_start=*/0,
             /* inorder_end=*/inorder.size());
}

}  // namespace algo_alternative