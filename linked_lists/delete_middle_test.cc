#include "linked_lists/delete_middle.h"
#include <vector>
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace leet_code {
namespace {

using ::testing::ElementsAreArray;

std::vector<int32_t> ConvertListToVector(ListNode* root) {
  std::vector<int32_t> result;
  auto node = root;
  while (node) {
    result.emplace_back(node->val);
    node = node->next;
  }

  return result;
}

TEST(DeleteMiddle, Example1) {
  auto node6 = std::make_unique<ListNode>(6, nullptr);
  auto node2 = std::make_unique<ListNode>(2, node6.get());
  auto node1 = std::make_unique<ListNode>(1, node2.get());
  auto node7 = std::make_unique<ListNode>(7, node1.get());
  auto node4 = std::make_unique<ListNode>(4, node7.get());
  auto node3 = std::make_unique<ListNode>(3, node4.get());
  auto node0 = std::make_unique<ListNode>(1, node3.get());
  EXPECT_THAT(ConvertListToVector(DeleteMiddle(node0.get())),
              ElementsAreArray(std::vector<int32_t>{1, 3, 4, 1, 2, 6}));
}

TEST(DeleteMiddle, Example2) {
  auto node4 = std::make_unique<ListNode>(4, nullptr);
  auto node3 = std::make_unique<ListNode>(3, node4.get());
  auto node2 = std::make_unique<ListNode>(2, node3.get());
  auto node1 = std::make_unique<ListNode>(1, node2.get());
  EXPECT_THAT(ConvertListToVector(DeleteMiddle(node1.get())),
              ElementsAreArray(std::vector<int32_t>{1, 2, 4}));
}

TEST(DeleteMiddle, Example3) {
  auto node1 = std::make_unique<ListNode>(4, nullptr);
  auto node2 = std::make_unique<ListNode>(2, node1.get());
  EXPECT_THAT(ConvertListToVector(DeleteMiddle(node2.get())),
              ElementsAreArray(std::vector<int32_t>{2}));
}

TEST(DeleteMiddle, Example4) {
  auto node1 = std::make_unique<ListNode>(1, nullptr);
  EXPECT_THAT(ConvertListToVector(DeleteMiddle(node1.get())),
              ElementsAreArray(std::vector<int32_t>{}));
}

}  // namespace
}  // namespace leet_code
