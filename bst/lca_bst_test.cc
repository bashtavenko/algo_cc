#include "bst/lca_bst.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <memory>
#include "bst/bst_node.h"

namespace algo {
namespace {

static inline std::unique_ptr<BSTNode> CreateTree() {
  return BSTNode::Create(
      10, BSTNode::Create(5, BSTNode::Create(1), BSTNode::Create(7)),
      BSTNode::Create(12, nullptr, BSTNode::Create(17)));
}

TEST(FindLCA, Works) {
  // This must be in variable because the function returns pointer.
  std::unique_ptr<BSTNode> root = CreateTree();
  auto result = FindLCA(root, 1, 17);
  EXPECT_THAT(result, testing::NotNull());
  EXPECT_THAT(result->data, 10);

  result = FindLCA(root, 1, 7);
  EXPECT_THAT(result, testing::NotNull());
  EXPECT_THAT(result->data, 5);
}

}  // namespace
}  // namespace algo