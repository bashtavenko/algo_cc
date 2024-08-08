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

  auto node_c = BinaryTreeNode::Create(1);
  auto node_d = BinaryTreeNode::Create(2);
  auto node_b = BinaryTreeNode::Create(3, node_c, node_d);
  ASSERT_THAT(node_b->left->parent.lock(), node_b);
  ASSERT_THAT(node_b->right->parent.lock(), node_b);

  auto node_e = BinaryTreeNode::Create(4);
  auto node_a = BinaryTreeNode::Create(5, node_b, node_e);
  ASSERT_THAT(node_a->left->parent.lock(), node_a);
  ASSERT_THAT(node_a->right->parent.lock(), node_a);

  auto result = ComputeLca(node_c, node_e);
  EXPECT_THAT(result, testing::NotNull());
  EXPECT_THAT(result->data, 5);
}

}  // namespace
}  // namespace algo
