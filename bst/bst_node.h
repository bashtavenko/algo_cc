#ifndef ALGO_CC_BST_BST_NODE_H_
#define ALGO_CC_BST_BST_NODE_H_

#include <cstdint>
#include <memory>

namespace algo {

struct BSTNode {
  int32_t data;
  BSTNode* left;
  BSTNode* right;

  BSTNode(int32_t data) : data(data), left(nullptr), right(nullptr) {};
  BSTNode(int32_t data, BSTNode* left, BSTNode* right)
      : data(data), left(left), right(right) {};
};

}  // namespace algo

namespace algo_alternative {

struct BSTNode {
  int32_t data;
  std::unique_ptr<BSTNode> left;
  std::unique_ptr<BSTNode> right;

  static std::unique_ptr<BSTNode> Create(int32_t value) {
    return std::make_unique<BSTNode>(value);
  }

  static std::unique_ptr<BSTNode> Create(int32_t value,
                                         std::unique_ptr<BSTNode> left,
                                         std::unique_ptr<BSTNode> right) {
    return std::make_unique<BSTNode>(value, std::move(left), std::move(right));
  }
};

}  // namespace algo_alternative

#endif  // ALGO_CC_BST_BST_NODE_H_
