#include "linked_lists/test_util.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {

TEST(ConvertListToVector, Works) {
  auto l3 = std::make_unique<ListNode>(3);
  auto l2 = std::make_unique<ListNode>(2, l3.get());
  auto l1 = std::make_unique<ListNode>(1, l2.get());

  EXPECT_THAT(ConvertListToVector(l1.get()),
              testing::Eq(std::vector<int>{1, 2, 3}));
}

}  // namespace
}  // namespace algo