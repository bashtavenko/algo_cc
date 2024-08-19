#include "bst/min_height_from_sorted.h"
#include <vector>
#include "bst/bst_node.h"

namespace algo {

std::unique_ptr<BSTNode> BuildHelper(const std::vector<int32_t>& data,
                                     size_t lo, size_t hi) {
  if (lo >= hi) return nullptr;
  size_t mid = lo + ((hi - lo) / 2);
  return BSTNode::Create(data[mid], BuildHelper(data, lo, mid),
                         BuildHelper(data, mid + 1, hi));
}

std::unique_ptr<BSTNode> BuildMinHeight(const std::vector<int32_t>& data) {
  return BuildHelper(data, 0, data.size());
}

}  // namespace algo