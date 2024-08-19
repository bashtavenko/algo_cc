#include "bst/k_largest.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "bst/bst_node.h"

namespace algo {
namespace {

TEST(FindKLargestBst, Works) {
  const std::unique_ptr<BSTNode> root = BSTNode::Create(
      43, BSTNode::Create(29, BSTNode::Create(23), BSTNode::Create(37)),
      BSTNode::Create(47, nullptr, BSTNode::Create(53)));
  const std::vector<int32_t> want{53, 47, 43};
  EXPECT_THAT(FindKLargestBst(root, 3), want);
}

}  // namespace
};  // namespace algo