#include <gflags/gflags.h>
#include <glog/logging.h>
#include <cstdlib>
#include <stack>
#include "bst/bst_node.h"

//           20
//      10        30
//    8    12   25    40
algo::BSTNode* SearchBST(algo::BSTNode* tree, int32_t key) {
  if (!tree) return nullptr;

  return tree->data == key  ? tree
         : key < tree->data ? SearchBST(tree->left, key)
                            : SearchBST(tree->right, key);
}

int32_t GetMinIteratively(algo::BSTNode* node) {
  while (node->left) {
    node = node->left;
  }
  return node->data;
}

int32_t GetMin(algo::BSTNode* node) {
  if (!node->left) return node->data;
  return GetMin(node->left);
}

void IterativeInOrder(algo::BSTNode* node) {
  std::stack<algo::BSTNode*> node_stack;
  while (node || !node_stack.empty()) {
    while (node) {
      node_stack.push(node);
      node = node->left;
    }
    node = node_stack.top();
    node_stack.pop();
    LOG(INFO) << node->data;
    node = node->right;
  }
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);
  FLAGS_logtostderr = true;

  using algo::BSTNode;
  auto node_8 = std::make_unique<BSTNode>(8);
  auto node_12 = std::make_unique<BSTNode>(12);
  auto node_10 = std::make_unique<BSTNode>(10, node_8.get(), node_12.get());
  auto node_25 = std::make_unique<BSTNode>(25);
  auto node_40 = std::make_unique<BSTNode>(40);
  auto node_30 = std::make_unique<BSTNode>(30, node_25.get(), node_40.get());
  auto bst = std::make_unique<BSTNode>(20, node_10.get(), node_30.get());

  LOG(INFO) << "GetMinIteratively: " << GetMinIteratively(bst.get());
  LOG(INFO) << "GetMin: " << GetMin(bst.get());
  IterativeInOrder(bst.get());

  return EXIT_SUCCESS;
}
