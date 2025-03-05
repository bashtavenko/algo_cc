#include "bst/equivalent.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(IsEquivalent, Example1) {
  const std::unique_ptr<BSTNode> first =
      BSTNode::Create(2, BSTNode::Create(1), BSTNode::Create(3));
  const std::unique_ptr<BSTNode> second = BSTNode::Create(
      3, BSTNode::Create(2, BSTNode::Create(1), nullptr), nullptr);
  EXPECT_TRUE(IsEquivalent(first.get(), second.get()));
}

TEST(IsEquivalent, Example2) {
  const std::unique_ptr<BSTNode> first =
      BSTNode::Create(2, BSTNode::Create(1), BSTNode::Create(7));
  const std::unique_ptr<BSTNode> second = BSTNode::Create(
      3, BSTNode::Create(2, BSTNode::Create(1), nullptr), nullptr);
  EXPECT_FALSE(IsEquivalent(first.get(), second.get()));
}

//         4
//    2       5
//      3        6
TEST(IsEquivalent, Example3) {
  const std::unique_ptr<BSTNode> first =
      BSTNode::Create(4, BSTNode::Create(2, nullptr, BSTNode::Create(3)),
                      BSTNode::Create(5, nullptr, BSTNode::Create(6)));
  const std::unique_ptr<BSTNode> second =
      BSTNode::Create(4, BSTNode::Create(2, nullptr, BSTNode::Create(3)),
                      BSTNode::Create(5, nullptr, BSTNode::Create(20)));

  EXPECT_FALSE(IsEquivalent(first.get(), second.get()));
}

}  // namespace
}  // namespace algo