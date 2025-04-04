#include "binary_trees/max_level_sum.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(MaxLevelSum, Example1) {
  auto node_8 = std::make_unique<BinaryTreeNode>(-8);
  auto node_7 = std::make_unique<BinaryTreeNode>(7);
  auto node_71 =
      std::make_unique<BinaryTreeNode>(7, node_7.get(), node_8.get());
  auto node0 = std::make_unique<BinaryTreeNode>(0);
  auto root = std::make_unique<BinaryTreeNode>(1, node_71.get(), node0.get());

  EXPECT_THAT(MaxLevelSum(root.get()), 2);
}

}  // namespace
}  // namespace algo
