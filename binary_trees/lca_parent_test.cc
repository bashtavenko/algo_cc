#include "binary_trees/lca_parent.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <memory>

namespace algo {
namespace {

TEST(ComputeLca, Works) {
  //                a(5)
  //          b(3)           e(4)
  //     c(1)      d(2)

  auto node_c = std::make_unique<BinaryTreeNode>(1);
  auto node_d = std::make_unique<BinaryTreeNode>(2);
  auto node_b = std::make_unique<BinaryTreeNode>(3, node_c.get(), node_d.get());
  node_b->left->parent = node_b.get();
  node_b->right->parent = node_b.get();

  auto node_e = std::make_unique<BinaryTreeNode>(4);
  auto node_a = std::make_unique<BinaryTreeNode>(5, node_b.get(), node_e.get());
  node_a->left->parent = node_a.get();
  node_a->right->parent = node_a.get();

  auto result = ComputeLca(node_c.get(), node_e.get());
  EXPECT_THAT(result, testing::NotNull());
  EXPECT_THAT(result->val, 5);
}

}  // namespace
}  // namespace algo
