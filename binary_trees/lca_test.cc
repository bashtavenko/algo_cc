#include "binary_trees/lca.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {
using ::testing::NotNull;

TEST(Lca, Example1) {
  auto node_7 = std::make_unique<BinaryTreeNode>(7);
  auto node_4 = std::make_unique<BinaryTreeNode>(4);
  auto node_2 = std::make_unique<BinaryTreeNode>(2, node_7.get(), node_4.get());
  auto node_6 = std::make_unique<BinaryTreeNode>(6);
  auto node_5 = std::make_unique<BinaryTreeNode>(5, node_6.get(), node_2.get());
  auto node_0 = std::make_unique<BinaryTreeNode>(0);
  auto node_8 = std::make_unique<BinaryTreeNode>(8);
  auto node_1 = std::make_unique<BinaryTreeNode>(1, node_0.get(), node_8.get());
  auto root = std::make_unique<BinaryTreeNode>(3, node_5.get(), node_1.get());
  BinaryTreeNode* result = ComputeLca(root.get(), node_5.get(), node_1.get());
  EXPECT_THAT(result, NotNull());
  EXPECT_THAT(result->val, 3);
}

TEST(Lca, Example2) {
  auto node_7 = std::make_unique<BinaryTreeNode>(7);
  auto node_4 = std::make_unique<BinaryTreeNode>(4);
  auto node_2 = std::make_unique<BinaryTreeNode>(2, node_7.get(), node_4.get());
  auto node_6 = std::make_unique<BinaryTreeNode>(6);
  auto node_5 = std::make_unique<BinaryTreeNode>(5, node_6.get(), node_2.get());
  auto node_0 = std::make_unique<BinaryTreeNode>(0);
  auto node_8 = std::make_unique<BinaryTreeNode>(8);
  auto node_1 = std::make_unique<BinaryTreeNode>(1, node_0.get(), node_8.get());
  auto root = std::make_unique<BinaryTreeNode>(3, node_5.get(), node_1.get());
  BinaryTreeNode* result = ComputeLca(root.get(), node_5.get(), node_4.get());
  EXPECT_THAT(result, NotNull());
  EXPECT_THAT(result->val, 5);
}

TEST(Lca, Example3) {
  auto node_1 = std::make_unique<BinaryTreeNode>(1);
  auto root = std::make_unique<BinaryTreeNode>(2, node_1.get(), nullptr);
  BinaryTreeNode* result = ComputeLca(root.get(), node_1.get(), root.get());
  EXPECT_THAT(result, NotNull());
  EXPECT_THAT(result->val, 2);
}

}  // namespace
}  // namespace algo