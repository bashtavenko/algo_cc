#ifndef ALGO_CC_LINKED_LISTS_LIST_NODE_H_
#define ALGO_CC_LINKED_LISTS_LIST_NODE_H_
#include <memory>

namespace algo {

// List node must be owned by the caller in std::unique_ptr
struct ListNode {
  int32_t val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int32_t x) : val(x), next(nullptr) {}
  ListNode(int32_t x, ListNode* next) : val(x), next(next) {}
};

}  // namespace algo

namespace algo_alternative {

// This does not make much sense. For the simple problem, the linked list
//  can be owned by test.
// The only benefit is to have it const in function declaration.
//  ListNode l3(3);
//  ListNode l2(2, l3);
//  ListNode l1(1, l2);
//  auto head = std::make_shared<ListNode>(l1);
//  auto result = SearchList(head, 12);
struct ListNode {
  int32_t data;
  // Alternatives are std::unique_ptr or raw pointer.
  // For simplicity and correctness the std::shared_ptr is better.
  std::shared_ptr<ListNode> next;

  ListNode(int32_t value) : data(value), next(nullptr) {}
  ListNode(int32_t value, const std::shared_ptr<ListNode>& next)
      : data(value), next(next) {};

  static std::shared_ptr<ListNode> Create(const ListNode& node) {
    return std::make_shared<ListNode>(node);
  }

  static std::shared_ptr<ListNode> Create(
      const ListNode& node, const std::shared_ptr<ListNode>& next) {
    return std::make_shared<ListNode>(node.data, next);
  }
};

}  // namespace algo_alternative

#endif  // ALGO_CC_LINKED_LISTS_LIST_NODE_H_
