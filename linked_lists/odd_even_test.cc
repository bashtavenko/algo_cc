#include "linked_lists/odd_even.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"
#include "linked_lists/test_util.h"

namespace algo {
namespace {

using ::testing::ElementsAreArray;

TEST(OddEvenList, Example1) {
  auto node5 = std::make_unique<ListNode>(5);
  auto node4 = std::make_unique<ListNode>(4, node5.get());
  auto node3 = std::make_unique<ListNode>(3, node4.get());
  auto node2 = std::make_unique<ListNode>(2, node3.get());
  auto head = std::make_unique<ListNode>(1, node2.get());

  EXPECT_THAT(ConvertListToVector(OddEvenList(head.get())),
              ElementsAreArray(std::vector<int32_t>{1, 3, 5, 2, 4}));
}

}  // namespace
}  // namespace algo
