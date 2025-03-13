#include "bst/k_largest.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "bst/bst_node.h"

namespace algo {
namespace {

TEST(FindKLargestBst, Works) {

  auto node_53 = std::make_unique<BSTNode>(53);
  auto node_47 = std::make_unique<BSTNode>(47, nullptr, node_53.get());
  auto node_23 = std::make_unique<BSTNode>(23);
  auto node_37 = std::make_unique<BSTNode>(37);
  auto node_29 = std::make_unique<BSTNode>(29, node_23.get(), node_37.get());
  auto tree = std::make_unique<BSTNode>(43, node_29.get(), node_47.get());

  const std::vector<int32_t> want{53, 47, 43};
  EXPECT_THAT(FindKLargestBst(tree.get(), 3), want);
}

}  // namespace
};  // namespace algo