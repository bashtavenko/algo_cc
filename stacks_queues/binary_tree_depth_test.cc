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
  auto node_1 = std::make_unique<BinaryTreeNode>(1);
  auto node_2 = std::make_unique<BinaryTreeNode>(2);
  auto node_b = std::make_unique<BinaryTreeNode>(3, node_1.get(), node_2.get());

  auto node_4 = std::make_unique<BinaryTreeNode>(4);
  auto tree = std::make_unique<BinaryTreeNode>(5, node_b.get(), node_4.get());
  std::vector<std::vector<int32_t>> want{{5}, {3, 4}, {1, 2}};

  EXPECT_THAT(BinaryTreeDepthOrder(tree.get()), ElementsAreArray(want));
}

}  // namespace
}  // namespace algo