#include "bst/min_height_from_sorted.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <vector>
#include "bst_node.h"

namespace algo_alternative {
namespace {

TEST(BuildMinHeight, Works) {
  const std::vector<int32_t> data{2, 3, 5, 7, 11, 13, 17, 19, 23};
  std::unique_ptr<BSTNode> tree = BuildMinHeight(data);
  EXPECT_THAT(tree, testing::NotNull());
  EXPECT_THAT(tree->data, 11);
  EXPECT_THAT(tree->left->data, 5);
  EXPECT_THAT(tree->right->data, 19);
}

}  // namespace
}  // namespace algo_alternative