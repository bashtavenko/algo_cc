#include "bst/first_greater.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "bst/bst_node.h"

namespace algo {
namespace {
TEST(FindFirstGreaterThanK, Works) {
  const std::unique_ptr<BSTNode> root = BSTNode::Create(
      2, BSTNode::Create(29, BSTNode::Create(23), BSTNode::Create(37)),
      BSTNode::Create(47, nullptr, BSTNode::Create(53)));

  auto result = FindFirstGreaterThanK(root, 23);
  EXPECT_THAT(result, testing::NotNull());
  EXPECT_THAT(result->data, 29);
}
}  // namespace
}  // namespace algo