#include "binary_trees/binary_tree_node.h"
#include <functional>
#include <queue>
#include <stack>
#include <vector>
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {
using ::testing::ElementsAreArray;

TEST(BinaryTreeNode, Works) {
  //                a(5)
  //          b(3)           e(4)
  //     c(1)      d(2)
  auto node_c = std::make_unique<BinaryTreeNode>(1);
  auto node_d = std::make_unique<BinaryTreeNode>(2);

  auto node_b = std::make_unique<BinaryTreeNode>(3, node_c.get(), node_d.get());
  auto node_e = std::make_unique<BinaryTreeNode>(4);
  auto tree = std::make_unique<BinaryTreeNode>(5, node_b.get(), node_e.get());
  std::vector<int32_t> result;

  // Cannot have const because of the queue
  std::function<void(algo::BinaryTreeNode*)> in_order =
      [&](algo::BinaryTreeNode* node) {
        if (!node) return;
        in_order(node->left);
        result.emplace_back(node->val);
        in_order(node->right);
      };

  std::function<void(const algo::BinaryTreeNode*)> pre_order =
      [&](const algo::BinaryTreeNode* node) {
        if (!node) return;
        result.emplace_back(node->val);
        pre_order(node->left);
        pre_order(node->right);
      };

  std::function<void(const algo::BinaryTreeNode*)> post_order =
      [&](const algo::BinaryTreeNode* node) {
        if (!node) return;
        post_order(node->left);
        post_order(node->right);
        result.emplace_back(node->val);
      };

  // Standard iterative in-order traversal
  //                a(5)
  //          b(3)           e(4)
  //     c(1)      d(2)
  auto in_order_iterative = [&](algo::BinaryTreeNode* tree) {
    std::stack<algo::BinaryTreeNode*> stack;
    algo::BinaryTreeNode* current = tree;
    while (current || !stack.empty()) {
      // Go as left as possible.
      while (current) {
        stack.push(current);
        current = current->left;
      }
      // Process the node at the top of the stack.
      current = stack.top();
      stack.pop();
      result.emplace_back(current->val);  // "process" the current node.
      // Now, traverse the right subtree.
      current = current->right;
    }
  };

  in_order(tree.get());
  EXPECT_THAT(result, ElementsAreArray(std::vector<int32_t>{1, 3, 2, 5, 4}));

  result.clear();

  pre_order(tree.get());
  EXPECT_THAT(result, ElementsAreArray(std::vector<int32_t>{5, 3, 1, 2, 4}));

  result.clear();

  post_order(tree.get());
  EXPECT_THAT(result, ElementsAreArray(std::vector<int32_t>{1, 2, 3, 4, 5}));

  result.clear();

  in_order_iterative(tree.get());
  EXPECT_THAT(result, ElementsAreArray(std::vector<int32_t>{1, 3, 2, 5, 4}));
}

}  // namespace
}  // namespace algo