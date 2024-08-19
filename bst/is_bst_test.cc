#include "bst/is_bst.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "bst/bst_node.h"

namespace algo {
namespace {

static inline std::unique_ptr<BSTNode> MakeValidTree() {
  return BSTNode::Create(
      15, BSTNode::Create(10, BSTNode::Create(5), BSTNode::Create(12)),
      BSTNode::Create(25, BSTNode::Create(20), BSTNode::Create(30)));
}

static inline std::unique_ptr<BSTNode> MakeInvalidTree() {
  return BSTNode::Create(
      15, BSTNode::Create(10, BSTNode::Create(5), BSTNode::Create(12)),
      BSTNode::Create(25, BSTNode::Create(13), BSTNode::Create(30)));
}

TEST(IsBinaryTreeBST, ValidWorks) {
  EXPECT_TRUE(IsBinaryTreeBST(MakeValidTree()));
}

TEST(IsBinaryTreeBST, InvalidWorks) {
  EXPECT_FALSE(IsBinaryTreeBST(MakeInvalidTree()));
}

TEST(IsBinaryTreeBFS, ValidWorks) {
  EXPECT_TRUE(IsBinaryTreeBFS(MakeValidTree()));
}

TEST(IsBinaryTreeBFS, InvalidWorks) {
  EXPECT_FALSE(IsBinaryTreeBFS(MakeInvalidTree()));
}

}  // namespace
}  // namespace algo
