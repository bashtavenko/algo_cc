#include "bst/first_greater.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "bst/bst_node.h"

namespace algo {
namespace {
TEST(FindFirstGreaterThanK, Works) {
  //                 43
  //          29           47
  //      23       37         53
  auto node_53 = std::make_unique<BSTNode>(53);
  auto node_37 = std::make_unique<BSTNode>(37);
  auto node_23 = std::make_unique<BSTNode>(23);
  auto node_47 = std::make_unique<BSTNode>(47, node_37.get(), node_53.get());
  auto node_29 = std::make_unique<BSTNode>(29, node_23.get(), node_47.get());
  auto root = std::make_unique<BSTNode>(43, node_29.get(), node_47.get());
  auto result = FindFirstGreaterThanK(root.get(), 23);
  EXPECT_THAT(result, testing::NotNull());
  EXPECT_THAT(result->data, 29);
}
}  // namespace
}  // namespace algo