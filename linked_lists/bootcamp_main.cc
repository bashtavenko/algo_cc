#include <gflags/gflags.h>
#include <glog/logging.h>
#include <forward_list>
#include <list>
#include "absl/strings/str_format.h"
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

std::shared_ptr<algo::ListNode> SearchList(
    const std::shared_ptr<algo::ListNode>& head, int32_t key) {
  auto node = head;
  while (node && node->data != key) {
    // Creates a new local shared_ptr
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
void InsertAfter(const std::shared_ptr<algo::ListNode>& node,
                 const std::shared_ptr<algo::ListNode>& new_node) {
  // Modifies the next pointer of ListNode.
  new_node->next = node->next;  // Points to where existing was pointed to
  // Also modifies the next outside
  node->next = new_node;  // Link it
}

// Deletes node past this one. Assume the node is not a tail.
void DeleteAfter(const std::shared_ptr<algo::ListNode>& node) {
  node->next = node->next->next;
}

int main(int argc, char** argv) {
  using algo::ListNode;

  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);

  ListNode l3(3);
  ListNode l2(2, l3);
  ListNode l1(1, l2);
  auto head = std::make_shared<ListNode>(l1);

  // Search
  auto result = SearchList(head, 12);
  LOG(INFO) << "Found? " << (result ? "Yes" : "No");
  result = SearchList(head, 3);
  if (result) {
    LOG(INFO) << "Found: " << result->data;
  } else {
    LOG(INFO) << "Not found";
  }

  // Insert after
  ListNode l5(5);
  ListNode l6(6, l5);
  auto new_node = std::make_shared<ListNode>(l6);
  InsertAfter(head, new_node);
  result = SearchList(head, 5);                       // L6 -> L5, L5 is gone.
  LOG(INFO) << "Found? " << (result ? "Yes" : "No");  // No

  // Delete after
  // L1->L6->L2->L3  =>  L1->L2->L3
  DeleteAfter(new_node);  // It was L6
  result = SearchList(head, 2);
  LOG(INFO) << "Found? " << (result ? "Yes" : "No");  // No

  RunForwardList();
  RunList();
}