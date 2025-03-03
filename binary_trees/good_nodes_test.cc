#include "binary_trees/good_nodes.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace leet_code {
namespace {

TEST(GoogNodes, Example1) {
  auto node5 = std::make_unique<TreeNode>(5);
  auto node1 = std::make_unique<TreeNode>(1);
  auto node4 = std::make_unique<TreeNode>(4, node1.get(), node5.get());
  auto node3 = std::make_unique<TreeNode>(3);
  auto node11 = std::make_unique<TreeNode>(1, node3.get(), nullptr);
  auto root = std::make_unique<TreeNode>(3, node11.get(), node4.get());

  EXPECT_THAT(GoogNodes(root.get()), 4);
}

}  // namespace
}  // namespace leet_code