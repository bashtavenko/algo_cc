#include "binary_trees/height_balanced.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <memory>

namespace algo {
namespace {

TEST(IsBalanced, Worked) {
  auto node_1 = std::make_unique<BinaryTreeNode>(1);
  auto node_2 = std::make_unique<BinaryTreeNode>(2);
  auto node_d = std::make_unique<BinaryTreeNode>(3, node_1.get(), node_2.get());
  auto node_4 = std::make_unique<BinaryTreeNode>(4);
  auto node_c = std::make_unique<BinaryTreeNode>(9, node_d.get(), node_4.get());

  EXPECT_FALSE(IsBalanced(node_c.get()));
}

}  // namespace
}  // namespace algo