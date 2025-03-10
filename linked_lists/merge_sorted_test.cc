#include "linked_lists/merge_sorted.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "linked_lists/test_util.h"

namespace algo {
namespace {
using ::testing::Eq;

TEST(MergeTwoSorted, Works) {
  auto l7 = std::make_unique<ListNode>(7);
  auto l5 = std::make_unique<ListNode>(5, l7.get());
  auto l2 = std::make_unique<ListNode>(2, l5.get());
  auto first = l2.get();

  auto l11 = std::make_unique<ListNode>(11);
  auto l3 = std::make_unique<ListNode>(3, l11.get());
  auto second = l3.get();

  auto merged = MergeTwoSorted(first, second);
  EXPECT_THAT(ConvertListToVector(merged),
              Eq(std::vector<int32_t>{2, 3, 5, 7, 11}));
}

}  // namespace
}  // namespace algo