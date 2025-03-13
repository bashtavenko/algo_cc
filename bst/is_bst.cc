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

bool IsBinaryTreeBST(const BSTNode* tree) {
  std::function<bool(const BSTNode*, int32_t, int32_t)> are_keys_in_range =
      [&](const BSTNode* tree, int32_t lo, int32_t hi) {
        if (!tree) return true;
        if (tree->data < lo || tree->data > hi) return false;
        return are_keys_in_range(tree->left, lo, tree->data) &&
               are_keys_in_range(tree->right, tree->data, hi);
      };

  return are_keys_in_range(tree, std::numeric_limits<int32_t>::min(),
                           std::numeric_limits<int32_t>::max());
}

bool IsBinaryTreeBFS(const BSTNode* tree) {
  struct QueueEntry {
    const BSTNode* node;
    int32_t lo;
    int32_t hi;
  };

  std::queue<QueueEntry> q;
  q.emplace(QueueEntry{tree, std::numeric_limits<int32_t>::min(),
                       std::numeric_limits<int32_t>::max()});

  while (!q.empty()) {
    const QueueEntry& current = q.front();
    if (current.node) {
      if (current.node->data < q.front().lo ||
          current.node->data > q.front().hi) {
        return false;
      }
      q.emplace(QueueEntry{current.node->left, current.lo, current.node->data});
      q.emplace(
          QueueEntry{current.node->right, current.node->data, current.hi});
    }
    q.pop();
  }
  return true;
}

}  // namespace algo
