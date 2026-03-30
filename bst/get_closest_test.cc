#include "bst/get_closest.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "bst/bst_node.h"

namespace algo {
namespace {

using testing::Optional;

TEST(FindFirstGreaterThanK, Works) {
  //             20
  //         10          30
  //      8      12  25      40
  auto node_8 = std::make_unique<BSTNode>(8);
  auto node_12 = std::make_unique<BSTNode>(12);
  auto node_25 = std::make_unique<BSTNode>(25);
  auto node_40 = std::make_unique<BSTNode>(400);
  auto node_10 = std::make_unique<BSTNode>(10, node_8.get(), node_12.get());
  auto node_30 = std::make_unique<BSTNode>(30, node_25.get(), node_40.get());
  auto root = std::make_unique<BSTNode>(20, node_10.get(), node_30.get());
  EXPECT_THAT(GetClosest(root.get(), 9), Optional(10));
  EXPECT_THAT(GetClosest(root.get(), 11), Optional(10));
  EXPECT_THAT(GetClosest(root.get(), 26), Optional(25));
  EXPECT_THAT(GetClosest(root.get(), 20), Optional(20));
  EXPECT_THAT(GetClosest(root.get(), 21), Optional(20));
}

TEST(GetClosestLogN, Works) {
  //             20
  //         10          30
  //      8      12  25      40
  auto node_8 = std::make_unique<BSTNode>(8);
  auto node_12 = std::make_unique<BSTNode>(12);
  auto node_25 = std::make_unique<BSTNode>(25);
  auto node_40 = std::make_unique<BSTNode>(400);
  auto node_10 = std::make_unique<BSTNode>(10, node_8.get(), node_12.get());
  auto node_30 = std::make_unique<BSTNode>(30, node_25.get(), node_40.get());
  auto root = std::make_unique<BSTNode>(20, node_10.get(), node_30.get());

  EXPECT_THAT(GetClosestLogN(root.get(), 11), Optional(10));
  EXPECT_THAT(GetClosestLogN(root.get(), 26), Optional(25));
  EXPECT_THAT(GetClosestLogN(root.get(), 20), Optional(20));
  EXPECT_THAT(GetClosestLogN(root.get(), 21), Optional(20));
}

TEST(GetClosestLogN, ReturnsEmptyForNullRoot) {
  EXPECT_THAT(GetClosestLogN(nullptr, 42), testing::Eq(std::nullopt));
}

TEST(GetClosestLogN, TieBreakPrefersSmallerValue) {
  //       10
  //    8      12
  auto node_8 = std::make_unique<BSTNode>(8);
  auto node_12 = std::make_unique<BSTNode>(12);
  auto root = std::make_unique<BSTNode>(10, node_8.get(), node_12.get());

  // Target 9 is equally close to 8 and 10; smaller should be chosen.
  EXPECT_THAT(GetClosestLogN(root.get(), 9), Optional(8));
}
}  // namespace
}  // namespace algo