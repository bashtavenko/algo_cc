#include "binary_trees/binary_tree_node.h"
#include <functional>
#include <queue>
#include <vector>
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {
using ::testing::ElementsAreArray;

std::vector<int32_t> TraverseInOrder(
    const std::unique_ptr<BinaryTreeNode>& tree) {}

TEST(BinaryTreeNode, Works) {
  //                a(5)
  //          b(3)           e(4)
  //     c(1)      d(2)
  auto b = BinaryTreeNode::Create(3, BinaryTreeNode::Create(1),
                                  BinaryTreeNode::Create(2));
  auto tree =
      BinaryTreeNode::Create(5, std::move(b), BinaryTreeNode::Create(4));
  std::vector<int32_t> result;

  std::queue<BinaryTreeNode*> q;

  std::function<void(const std::unique_ptr<algo::BinaryTreeNode>&)> in_order =
      [&](const std::unique_ptr<algo::BinaryTreeNode>& node) {
        if (!node) return;
        in_order(node->left);
        result.emplace_back(node->data);
        q.push(node.get());
        in_order(node->right);
      };

  std::function<void(const std::unique_ptr<algo::BinaryTreeNode>&)> pre_order =
      [&](const std::unique_ptr<algo::BinaryTreeNode>& node) {
        if (!node) return;
        result.emplace_back(node->data);
        pre_order(node->left);
        pre_order(node->right);
      };

  std::function<void(const std::unique_ptr<algo::BinaryTreeNode>&)> post_order =
      [&](const std::unique_ptr<algo::BinaryTreeNode>& node) {
        if (!node) return;
        post_order(node->left);
        post_order(node->right);
        result.emplace_back(node->data);
      };

  in_order(tree);
  EXPECT_THAT(result, ElementsAreArray(std::vector<int32_t>{1, 3, 2, 5, 4}));

  result.clear();

  pre_order(tree);
  EXPECT_THAT(result, ElementsAreArray(std::vector<int32_t>{5, 3, 1, 2, 4}));

  result.clear();

  post_order(tree);
  EXPECT_THAT(result, ElementsAreArray(std::vector<int32_t>{1, 2, 3, 4, 5}));
}

}  // namespace
}  // namespace algo