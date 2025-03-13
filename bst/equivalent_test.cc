#include "bst/equivalent.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(IsEquivalent, Example1) {
  //      1                3
  // 2        3          2
  //                   1
  auto node_1 = std::make_unique<BSTNode>(1);
  auto node_3 = std::make_unique<BSTNode>(3);
  auto first = std::make_unique<BSTNode>(2, node_1.get(), node_3.get());

  auto node_2 = std::make_unique<BSTNode>(2, node_3.get(), nullptr);
  auto second = std::make_unique<BSTNode>(3, node_2.get(), nullptr);
  EXPECT_FALSE(IsEquivalent(first.get(), second.get()));
}

TEST(IsEquivalent, Example2) {
  auto node_1 = std::make_unique<BSTNode>(1);
  auto node_3 = std::make_unique<BSTNode>(7);
  auto first = std::make_unique<BSTNode>(2, node_1.get(), node_3.get());

  auto node_2 = std::make_unique<BSTNode>(2, node_3.get(), nullptr);
  auto second = std::make_unique<BSTNode>(3, node_2.get(), nullptr);

  EXPECT_FALSE(IsEquivalent(first.get(), second.get()));
}

}  // namespace
}  // namespace algo