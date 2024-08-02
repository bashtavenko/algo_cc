#include "binary_trees/reconstruct.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <memory>
#include "binary_trees/binary_tree_node.h"
#include "binary_trees/reconstruct.h"

//   1
// 2   3
// PRE: 1, 2, 3
// I:    2, 1, 3
//
//       1
//   2        3
// 4    5   6   7
//   8
//
// PRE: 1, 2, 4, 8, 5, 3, 6, 7
// I:   4, 8, 2, 5, 1, 6, 3, 7

namespace algo {
namespace {

TEST(ReconstructBasics, Works) {
  auto node_2 = BinaryTreeNode::Create(2);
  auto node_3 = BinaryTreeNode::Create(3);
  auto root = BinaryTreeNode::Create(1, std::move(node_2), std::move(node_3));

  auto result =
      Reconstruct(std::vector<int32_t>{1, 2, 3}, std::vector<int32_t>{2, 1, 3});
  EXPECT_THAT(result->data, 1);
}

}  // namespace
}  // namespace algo