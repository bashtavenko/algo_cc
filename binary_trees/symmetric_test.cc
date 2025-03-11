#include "binary_trees/symmetric.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "binary_trees/binary_tree_node.h"

namespace algo {
namespace {

TEST(CheckSymmetric, Works) {
  auto node_d = std::make_unique<BinaryTreeNode>(3);
  auto node_c = std::make_unique<BinaryTreeNode>(2, nullptr, node_d.get());
  auto node_3 = std::make_unique<BinaryTreeNode>(3);
  auto node_f = std::make_unique<BinaryTreeNode>(2, node_3.get(), nullptr);

  auto node_b = std::make_unique<BinaryTreeNode>(6, nullptr, node_c.get());
  auto node_e = std::make_unique<BinaryTreeNode>(6, node_f.get(), nullptr);
  auto root = std::make_unique<BinaryTreeNode>(314, node_b.get(), node_e.get());
  EXPECT_TRUE(IsSymmetric(root.get()));
}
}  // namespace
}  // namespace algo