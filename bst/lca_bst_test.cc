#include "bst/lca_bst.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <memory>
#include "bst/bst_node.h"

namespace algo {
namespace {

TEST(FindLCA, Works) {
  auto node_17 = std::make_unique<BSTNode>(17);
  auto node_12 = std::make_unique<BSTNode>(12, nullptr, node_17.get());
  auto node_7 = std::make_unique<BSTNode>(7);
  auto node_1 = std::make_unique<BSTNode>(1);
  auto node_5 = std::make_unique<BSTNode>(5, node_1.get(), node_7.get());
  auto root = std::make_unique<BSTNode>(10, node_5.get(), node_12.get());
  auto result = FindLCA(root.get(), 1, 17);
  EXPECT_THAT(result, testing::NotNull());
  EXPECT_THAT(result->data, 10);

  result = FindLCA(root.get(), 1, 7);
  EXPECT_THAT(result, testing::NotNull());
  EXPECT_THAT(result->data, 5);
}

}  // namespace
}  // namespace algo