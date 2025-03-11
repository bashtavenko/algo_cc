//       10
//    8     20
//
//    In-order: 8, 10, 20
//    Pre-order: 10, 8, 20 (BEFORE / PRE)
//    Post-order: 8, 20, 10 (leaves then ROOT)
//    Reversed post-order: 20, 8, 10 (leaves right, left then ROOT)
#ifndef ALGO_CC_BINARY_TREES_BINARY_TREE_NODE_H_
#define ALGO_CC_BINARY_TREES_BINARY_TREE_NODE_H_

#include <cstdint>
#include <memory>

namespace algo {

// Requires a caller to own the actual nodes and outlive this struct.
// Raw points are fine in a sample, but require ownership in test code and
// each node must have std::unique_ptr and not temporary,
// otherwise they need std::move.
struct BinaryTreeNode {
  int32_t val;
  BinaryTreeNode* left;
  BinaryTreeNode* right;

  BinaryTreeNode(int32_t val) : val(val), left(nullptr), right(nullptr) {};
  BinaryTreeNode(int32_t val, BinaryTreeNode* left, BinaryTreeNode* right)
      : val(val), left(left), right(right) {};
};

}  // namespace algo

namespace algo_alternative {

// This is overblown for a simple illustration purpose.
struct BinaryTreeNode {
  int32_t data;

  // There could be std::shared_ptr instead.
  // Advantages:
  // 1. Simplified construction. No need for std::move
  // 2. Easy to share and access nodes outside
  // Disadvantages:
  // 1. Memory overhead
  // 2. Potential for circular references
  // 3. Reduced flexibility. No control over std_shared_ptr
  // 4. Performance implication
  std::unique_ptr<BinaryTreeNode> left;
  std::unique_ptr<BinaryTreeNode> right;

  static std::unique_ptr<BinaryTreeNode> Create(int32_t value) {
    return std::make_unique<BinaryTreeNode>(value);
  }

  static std::unique_ptr<BinaryTreeNode> Create(
      int32_t value, std::unique_ptr<BinaryTreeNode> left_child,
      std::unique_ptr<BinaryTreeNode> right_child) {
    return std::make_unique<BinaryTreeNode>(value, std::move(left_child),
                                            std::move(right_child));
  }
};

}  // namespace algo_alternative

#endif  // ALGO_CC_BINARY_TREES_BINARY_TREE_NODE_H_
