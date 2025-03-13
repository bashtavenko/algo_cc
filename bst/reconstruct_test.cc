#include "bst/reconstruct.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <vector>
#include "bst/bst_node.h"

namespace algo_alternative {
namespace {

TEST(Reconstruct, Works) {
  const std::vector<int32_t> data{20, 10, 8, 12, 30, 25, 40};
  std::unique_ptr<BSTNode> result = Reconstruct(data);
  EXPECT_THAT(result, testing::NotNull());
  EXPECT_THAT(result->data, 20);
  EXPECT_THAT(result->left->data, 10);
  EXPECT_THAT(result->right->data, 30);
}

}  // namespace
}  // namespace algo_alternative