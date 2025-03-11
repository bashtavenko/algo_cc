#include "binary_trees/path_sum.h"
#include "binary_trees/binary_tree_node.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(PathSum, Example1) {
  auto node11 = std::make_unique<BinaryTreeNode>(BinaryTreeNode(11));
  auto nodeMinus3 = std::make_unique<BinaryTreeNode>(
      BinaryTreeNode(-3, nullptr, node11.get()));

  auto node3 = std::make_unique<BinaryTreeNode>(3);
  auto node_2 = std::make_unique<BinaryTreeNode>(-2);
  auto node31 = std::make_unique<BinaryTreeNode>(3, node3.get(), node_2.get());

  auto node1 = std::make_unique<BinaryTreeNode>(1);
  auto node2 = std::make_unique<BinaryTreeNode>(2, nullptr, node1.get());

  auto node5 = std::make_unique<BinaryTreeNode>(5, node3.get(), node2.get());
  auto root =
      std::make_unique<BinaryTreeNode>(10, node5.get(), nodeMinus3.get());

  EXPECT_THAT(PathSum(root.get(), 8), 3);
}

}  // namespace
}  // namespace algo