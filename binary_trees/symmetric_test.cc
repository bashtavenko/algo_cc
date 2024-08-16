#include "binary_trees/symmetric.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "binary_trees/binary_tree_node.h"

namespace algo {
namespace {

TEST(CheckSymmetric, Works) {
  auto node_d = BinaryTreeNode::Create(3);
  auto node_c = BinaryTreeNode::Create(2, nullptr, std::move(node_d));
  auto node_f = BinaryTreeNode::Create(2, BinaryTreeNode::Create(3), nullptr);
  auto node_b = BinaryTreeNode::Create(6, nullptr, std::move(node_c));
  auto node_e = BinaryTreeNode::Create(6, std::move(node_f), nullptr);
  auto root = BinaryTreeNode::Create(314, std::move(node_b), std::move(node_e));
  EXPECT_TRUE(IsSymmetric(root));
}
}  // namespace
}  // namespace algo