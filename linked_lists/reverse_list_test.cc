#include "linked_lists/reverse_list.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include "linked_lists/test_util.h"

namespace algo {
namespace {
using ::testing::Eq;

TEST(ReverseSublist, Works) {
  auto l3 = std::make_unique<ListNode>(3);
  auto l2 = std::make_unique<ListNode>(2, l3.get());
  auto l1 = std::make_unique<ListNode>(1, l2.get());

  EXPECT_THAT(ConvertListToVector(ReverseSublist(l1.get(), 1, 3)),
              Eq(std::vector<int32_t>{3, 2, 1}));
}

}  // namespace
}  // namespace algo