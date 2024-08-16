#include "binary_trees/height_balanced.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <memory>

namespace algo {
namespace {

TEST(IsBalanced, Worked) {
  auto node_d = BinaryTreeNode::Create(3, BinaryTreeNode::Create(1),
                                       BinaryTreeNode::Create(2));
  auto node_c =
      BinaryTreeNode::Create(9, std::move(node_d), BinaryTreeNode::Create(4));

  EXPECT_TRUE(IsBalanced(node_c));
}

}  // namespace
}  // namespace algo