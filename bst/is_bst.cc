#include "bst/is_bst.h"
#include <functional>
#include <limits>
#include <memory>
#include <queue>
#include "bst/bst_node.h"

namespace algo {

//  Valid
//            15
//     10              25
// 5        12      20     30
// ---------------------------
//  Invalid
//            15
//     10              25
// 5        12      13     30

bool IsBinaryTreeBST(const std::unique_ptr<BSTNode>& tree) {
  std::function<bool(const std::unique_ptr<BSTNode>&, int32_t, int32_t)>
      are_keys_in_range =
          [&](const std::unique_ptr<BSTNode>& tree, int32_t lo, int32_t hi) {
            if (!tree) return true;
            if (tree->data < lo || tree->data > hi) return false;
            return are_keys_in_range(tree->left, lo, tree->data) &&
                   are_keys_in_range(tree->right, tree->data, hi);
          };

  return are_keys_in_range(tree, std::numeric_limits<int32_t>::min(),
                           std::numeric_limits<int32_t>::max());
}

struct QueueEntry {
  const std::unique_ptr<BSTNode>& node;
  int32_t lo;
  int32_t hi;
};

bool IsBinaryTreeBFS(const std::unique_ptr<BSTNode>& tree) {
  std::queue<QueueEntry> bfs_queue;
  bfs_queue.emplace(QueueEntry{tree, std::numeric_limits<int32_t>::min(),
                               std::numeric_limits<int32_t>::max()});

  while (!bfs_queue.empty()) {
    const QueueEntry& current = bfs_queue.front();
    if (current.node.get()) {
      if (current.node->data < bfs_queue.front().lo ||
          current.node->data > bfs_queue.front().hi) {
        return false;
      }
      bfs_queue.emplace(
          QueueEntry{current.node->left, current.lo, current.node->data});
      bfs_queue.emplace(
          QueueEntry{current.node->right, current.node->data, current.hi});
    }
    bfs_queue.pop();
  }
  return true;
}

}  // namespace algo
