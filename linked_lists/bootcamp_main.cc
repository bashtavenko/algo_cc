#include <gflags/gflags.h>
#include <glog/logging.h>
#include <forward_list>
#include <functional>
#include <list>
#include "linked_lists/list_node.h"

// Singly-linked
void RunForwardList() {
  std::forward_list<int32_t> head{1, 2, 3, 4};
  for (const auto& node : head) {
    LOG(INFO) << node;
  }
}

// Double-linked
void RunList() {
  std::list<int32_t> head{1, 2, 3, 4};
  head.push_front(-1);
  head.push_back(5);
  head.push_back(42);
  head.pop_back();
  for (const auto& node : head) {
    LOG(INFO) << node;
  }
}

void RunListIterative(const algo::ListNode* head) {
  auto node = head;
  while (node) {
    LOG(INFO) << "Node iterative: " << node->val;
    node = node->next;
  }
}

void RunListRecursive(const algo::ListNode* head) {
  std::function<void(const algo::ListNode*)> run =
      [&](const algo::ListNode* node) {
        if (!node) return;
        LOG(INFO) << "Node recursive: " << node->val;
        run(node->next);
        LOG(INFO) << "At the bottom, node: " << node->val;
      };
  run(head);
}

algo::ListNode* SearchList(algo::ListNode* head, int32_t key) {
  auto node = head;
  while (node && node->val != key) {
    node = node->next;
  }
  return node;
}

// Inserts after specific node (in between)
// node: L1 -> L2 -> L3
// new_node: L6 -> L5
// Result for L1: L1->L6->L2->L3.
// L5 becomes orphan
// The function mutates the list structure.
// It's able to do this even with const shared_ptr& parameters because the const
// applies to the shared_ptr, not to the ListNode it points to.
void InsertAfter(algo::ListNode* node, algo::ListNode* new_node) {
  // Modifies the next pointer of ListNode.
  new_node->next = node->next;  // Points to where existing was pointed to
  // Also modifies the next outside
  node->next = new_node;  // Link it
}

// Deletes node past this one. Assume the node is not a tail.
void DeleteAfter(algo::ListNode* node) { node->next = node->next->next; }

int main(int argc, char** argv) {
  using algo::ListNode;

  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);
  FLAGS_logtostderr = 1;

  auto l3 = std::make_unique<ListNode>((3));
  auto l2 = std::make_unique<ListNode>(2, l3.get());
  auto head = std::make_unique<ListNode>(1, l2.get());

  // Basics
  RunListIterative(head.get());
  RunListRecursive(head.get());

  // Search
  auto result = SearchList(head.get(), 12);
  LOG(INFO) << "Found? " << (result ? "Yes" : "No");
  result = SearchList(head.get(), 3);
  if (result) {
    LOG(INFO) << "Found: " << result->val;
  } else {
    LOG(INFO) << "Not found";
  }

  // Insert after
  auto l5 = std::make_unique<ListNode>(5);
  auto new_node = std::make_unique<ListNode>(6, l5.get());
  InsertAfter(head.get(), new_node.get());
  result = SearchList(head.get(), 5);                 // L6 -> L5, L5 is gone.
  LOG(INFO) << "Found? " << (result ? "Yes" : "No");  // No

  // Delete after
  // L1->L6->L2->L3  =>  L1->L2->L3
  DeleteAfter(new_node.get());  // It was L6
  result = SearchList(head.get(), 2);
  LOG(INFO) << "Found? " << (result ? "Yes" : "No");  // No

  RunForwardList();
  RunList();
}