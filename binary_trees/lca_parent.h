// 9.4 Compute LCA when nodes have parent nodes
// A brute force is to store nodes from the first tree in a hashtable
// {node:parent}. Then walk through the second tree to until the parent is
// in a hashtable.
// Alternatively, walk both trees if they are at the same depth which would
// require: 1) Find depth; 2) Align both and finally walk up.

#ifndef ALGO_CC_BINARY_TREES_LCA_PARENT_H_
#define ALGO_CC_BINARY_TREES_LCA_PARENT_H_

#include <memory>

namespace algo {

struct BinaryTreeNode {
  int32_t data;
  std::shared_ptr<BinaryTreeNode> left;
  std::shared_ptr<BinaryTreeNode> right;
  // The reason for std::weak_ptr is to avoid dependencies.
  // This circular chain of strong references would prevent the reference count
  // from ever reaching zero, even when the tree is no longer accessible from
  // outside.
  // When we need to access the parent, we can use the weak_ptr's lock() method
  // to get a temporary shared_ptr. If the parent still exists, we can use it;
  // if not, the lock() will return an empty shared_ptr.
  //  if (auto parent = child->parent.lock()) {
  //        std::cout << "Child's parent value: " << parent->data << std::endl;
  //  }
  // In this way, root and child will be deleted.
  std::weak_ptr<BinaryTreeNode> parent;

  explicit BinaryTreeNode(int32_t value) : data(value) {}

  BinaryTreeNode(int32_t value, std::shared_ptr<BinaryTreeNode> left_child,
                 std::shared_ptr<BinaryTreeNode> right_child)
      : data(value), left(left_child), right(right_child) {
    // Set parent after the object has been fully constructed
    // to
  }

  static std::shared_ptr<BinaryTreeNode> Create(int32_t value) {
    return std::make_shared<BinaryTreeNode>(value);
  }

  static std::shared_ptr<BinaryTreeNode> Create(
      int32_t value, std::shared_ptr<BinaryTreeNode> left_child,
      std::shared_ptr<BinaryTreeNode> right_child) {
    auto node =
        std::make_shared<BinaryTreeNode>(value, left_child, right_child);
    // Now set both left and right to "*this".
    // std::weak_ptr will be directly constructed from std::shared_ptr
    if (node->left) {
      node->left->parent = node;
    }
    if (node->right) {
      node->right->parent = node;
    }
    return node;
  }
};

BinaryTreeNode* ComputeLca(const std::shared_ptr<BinaryTreeNode>& node_0,
                           const std::shared_ptr<BinaryTreeNode>& node_1);
}  // namespace algo

#endif  // ALGO_CC_BINARY_TREES_LCA_PARENT_H_
