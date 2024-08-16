#include <gflags/gflags.h>
#include <glog/logging.h>
#include "bst/bst_node.h"

//           20
//      10        30
//    8    12   25    40
std::unique_ptr<algo::BSTNode> CreateTree() {
  using algo::BSTNode;
  auto node_10 = BSTNode::Create(10, BSTNode::Create(8), BSTNode::Create(12));
  auto node_30 = BSTNode::Create(30, BSTNode::Create(25), BSTNode::Create(40));
  return BSTNode::Create(20, std::move(node_10), std::move(node_30));
}

algo::BSTNode* SearchBST(const std::unique_ptr<algo::BSTNode>& tree,
                         int32_t key) {
  if (!tree) return nullptr;

  return tree->data == key  ? tree.get()
         : key < tree->data ? SearchBST(tree->left, key)
                            : SearchBST(tree->right, key);
}

void RunBST() { LOG(INFO) << SearchBST(CreateTree(), 10)->data; }

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);

  RunBST();

  return EXIT_SUCCESS;
}
