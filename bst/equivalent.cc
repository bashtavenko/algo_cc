#include "bst/equivalent.h"
#include <functional>
#include <stack>

namespace algo {

//     2
//  1     3
//
bool IsEquivalentInOrderDump(BSTNode* first, BSTNode* second) {
  std::vector<int32_t> in_order_first;
  std::vector<int32_t> in_order_second;

  std::function<void(const BSTNode*, std::vector<int32_t>*)> dfs =
      [&](const BSTNode* node, std::vector<int32_t>* in_order) {
        if (!node) return;
        dfs(node->left, in_order);
        in_order->push_back(node->data);
        dfs(node->right, in_order);
      };

  dfs(first, &in_order_first);
  dfs(second, &in_order_second);

  if (in_order_first.size() != in_order_second.size()) return false;
  for (size_t i = 0; i < in_order_first.size(); ++i) {
    if (in_order_first[i] != in_order_second[i]) return false;
  }

  return true;
}

bool IsEquivalent(BSTNode* first, BSTNode* second) {
  std::stack<BSTNode*> s1;
  std::stack<BSTNode*> s2;

  while (true) {
    // Traverse leftmost nodes of both trees
    while (first) {
      s1.push(first);
      first = first->left;
    }
    while (second) {
      s2.push(second);
      second = second->left;
    }

    // If one stack is empty and the other is not, they are not equivalent
    if (s1.empty() != s2.empty()) return false;
    if (s1.empty()) break;

    // Pop next elements from both stacks
    first = s1.top();
    s1.pop();
    second = s2.top();
    s2.pop();

    // Compare values
    if (first->data != second->data) return false;

    // Move to the right subtree
    first = first->right;
    second = second->right;
  }

  return true;
}
}  // namespace algo
