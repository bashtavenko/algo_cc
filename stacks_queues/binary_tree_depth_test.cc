#include "stacks_queues/binary_tree_depth.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <vector>
#include "binary_trees/binary_tree_node.h"

namespace algo {
namespace {
using ::testing::ElementsAreArray;

TEST(BinaryTreeDepthOrder, Works) {
  //                a(5)
  //          b(3)           e(4)
  //     c(1)      d(2)
  auto b = BinaryTreeNode::Create(3, BinaryTreeNode::Create(1),
                                  BinaryTreeNode::Create(2));
  auto tree =
      BinaryTreeNode::Create(5, std::move(b), BinaryTreeNode::Create(4));
  std::vector<std::vector<int32_t>> want{{5}, {3, 4}, {1, 2}};

  EXPECT_THAT(BinaryTreeDepthOrder(tree), ElementsAreArray(want));
}

}  // namespace
}  // namespace algo