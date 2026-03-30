#include "bst/get_closest.h"
#include <cstdlib>
#include <cstdint>
#include <numeric>

namespace algo {

std::optional<int32_t> GetClosest(BSTNode* node, int32_t target) {
  if (!node) return {};
  std::optional closest = std::numeric_limits<int32_t>::max();

  while (node) {
    if (std::abs(node->data - target) < std::abs(closest.value() - target)) {
      closest = node->data;
    }
    if (target < node->data) {
      node = node->left;
    } else if (target > node->data) {
      node = node->right;
    } else {
      return node->data;
    }
  }

  return closest;
}

std::optional<int32_t> GetClosestLogN(BSTNode* node, int32_t target) {
  if (!node) return {};

  std::optional<int32_t> closest = node->data;

  while (node) {
    const int64_t node_distance =
        std::llabs(static_cast<int64_t>(node->data) - target);
    const int64_t best_distance =
        std::llabs(static_cast<int64_t>(closest.value()) - target);
    if (node_distance < best_distance ||
        (node_distance == best_distance && node->data < closest.value())) {
      closest = node->data;
    }

    if (target < node->data) {
      node = node->left;
    } else if (target > node->data) {
      node = node->right;
    } else {
      return node->data;
    }
  }

  return closest;
}

}  // namespace algo