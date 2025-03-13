#include "bst/is_bst.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "bst/bst_node.h"

namespace algo {
namespace {

TEST(IsBinaryTreeBST, ValidWorks) {
  //            15
  //     10              25
  // 5        12      20     30
  auto node_5 = std::make_unique<BSTNode>(5);
  auto node_12 = std::make_unique<BSTNode>(12);
  auto node_10 = std::make_unique<BSTNode>(10, node_5.get(), node_12.get());
  auto node_20 = std::make_unique<BSTNode>(20);
  auto node_30 = std::make_unique<BSTNode>(30);
  auto node_25 = std::make_unique<BSTNode>(25, node_20.get(), node_30.get());
  auto tree = std::make_unique<BSTNode>(15, node_10.get(), node_25.get());
  EXPECT_TRUE(IsBinaryTreeBST(tree.get()));
}

TEST(IsBinaryTreeBST, InvalidWorks) {
  //  Invalid
  //            15
  //     10              25
  // 5        12      13     30
  auto node_5 = std::make_unique<BSTNode>(5);
  auto node_12 = std::make_unique<BSTNode>(12);
  auto node_10 = std::make_unique<BSTNode>(10, node_5.get(), node_12.get());
  auto node_13 = std::make_unique<BSTNode>(13);
  auto node_30 = std::make_unique<BSTNode>(30);
  auto node_25 = std::make_unique<BSTNode>(25, node_13.get(), node_30.get());
  auto tree = std::make_unique<BSTNode>(15, node_10.get(), node_25.get());
  EXPECT_FALSE(IsBinaryTreeBST(tree.get()));
}

TEST(IsBinaryTreeBFS, ValidWorks) {
  auto node_5 = std::make_unique<BSTNode>(5);
  auto node_12 = std::make_unique<BSTNode>(12);
  auto node_10 = std::make_unique<BSTNode>(10, node_5.get(), node_12.get());
  auto node_20 = std::make_unique<BSTNode>(20);
  auto node_30 = std::make_unique<BSTNode>(30);
  auto node_25 = std::make_unique<BSTNode>(25, node_20.get(), node_30.get());
  auto tree = std::make_unique<BSTNode>(15, node_10.get(), node_25.get());
  EXPECT_TRUE(IsBinaryTreeBFS(tree.get()));
}

TEST(IsBinaryTreeBFS, InvalidWorks) {
  auto node_5 = std::make_unique<BSTNode>(5);
  auto node_12 = std::make_unique<BSTNode>(12);
  auto node_10 = std::make_unique<BSTNode>(10, node_5.get(), node_12.get());
  auto node_13 = std::make_unique<BSTNode>(13);
  auto node_30 = std::make_unique<BSTNode>(30);
  auto node_25 = std::make_unique<BSTNode>(25, node_13.get(), node_30.get());
  auto tree = std::make_unique<BSTNode>(15, node_10.get(), node_25.get());
  EXPECT_FALSE(IsBinaryTreeBFS(tree.get()));
}

}  // namespace
}  // namespace algo
