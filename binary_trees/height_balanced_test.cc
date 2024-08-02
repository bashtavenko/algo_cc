#include "binary_trees/height_balanced.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <memory>

namespace algo {
namespace {

TEST(IsBalanced, Worked) {
  auto node_e = BinaryTreeNode::Create(1);
  auto node_f = BinaryTreeNode::Create(2);
  auto node_d = BinaryTreeNode::Create(3, std::move(node_e), std::move(node_f));
  auto node_g = BinaryTreeNode::Create(4);
  auto node_c = BinaryTreeNode::Create(9, std::move(node_d), std::move(node_g));

  EXPECT_TRUE(IsBalanced(node_c));
}

}  // namespace
}  // namespace algo