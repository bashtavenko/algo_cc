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

void TraversePreorder(const algo::BinaryTreeNode* root) {
  if (!root) return;
  LOG(INFO) << root->val;
  TraversePreorder(root->left);
  TraversePreorder(root->right);
}

void Traverse() {
  using algo::BinaryTreeNode;

  auto node_2 = std::make_unique<BinaryTreeNode>(2);
  auto node_271 = std::make_unique<BinaryTreeNode>(271);
  auto node_i =
      std::make_unique<BinaryTreeNode>(6, node_2.get(), node_271.get());

  auto node_b = std::make_unique<BinaryTreeNode>(6);
  auto root = std::make_unique<BinaryTreeNode>(314, node_b.get(), node_i.get());
  LOG(INFO) << "Preorder";
  TraversePreorder(root.get());
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);
  FLAGS_logtostderr = 1;
  Traverse();
}