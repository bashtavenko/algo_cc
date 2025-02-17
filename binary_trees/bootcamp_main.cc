#include <gflags/gflags.h>
#include <glog/logging.h>
#include <memory>
#include "binary_trees/binary_tree_node.h"

//     10
//  8     20
//
// In-order: 8, 10, 20  (in BST that would be increasing)
// Pre-order: 10, 8, 20 (BEFORE / PRE)
// Post-order: 8, 20, 10 (leaves then ROOT)
// Reversed post-order: 20, 8, 10 (leaves right, left then ROOT)

void TraversePreorder(const std::unique_ptr<algo::BinaryTreeNode>& root) {
  if (!root) return;
  LOG(INFO) << root->data;
  TraversePreorder(root->left);
  TraversePreorder(root->right);
}

void Traverse() {
  using algo::BinaryTreeNode;

  auto node_i = BinaryTreeNode::Create(6, BinaryTreeNode::Create(2),
                                       BinaryTreeNode::Create(271));

  auto node_b = BinaryTreeNode::Create(6);
  auto root = BinaryTreeNode::Create(314, std::move(node_b), std::move(node_i));
  LOG(INFO) << "Preorder";
  TraversePreorder(root);
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);
  FLAGS_logtostderr = 1;
  Traverse();
}