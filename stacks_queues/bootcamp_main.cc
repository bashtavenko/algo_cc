#include <memory>
#include <stack>
#include "gflags/gflags.h"
#include "glog/logging.h"
#include "linked_lists/list_node.h"

void PrintLinkedListInReverse(const std::shared_ptr<algo::ListNode>& head) {
  std::stack<int32_t> nodes;
  auto node = head;
  while (node) {
    nodes.push(node->data);
    node = node->next;
  }

  while (!nodes.empty()) {
    LOG(INFO) << nodes.top();
    nodes.pop();
  }
}

int main(int argc, char** argv) {
  using algo::ListNode;
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);
  FLAGS_logtostderr = 1;

  auto l3 = ListNode::Create(3);
  auto l2 = ListNode::Create(2, l3);
  auto head = ListNode::Create(1, l2);
  PrintLinkedListInReverse(head);
}