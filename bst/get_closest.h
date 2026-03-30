#ifndef ALGO_CC_GET_CLOSEST_H
#define ALGO_CC_GET_CLOSEST_H
#include "bst/get_closest.h"
#include <memory>
#include "bst/bst_node.h"
#include <optional>

namespace algo {
//      20
//   10        30
// 8    12  25    40
// 9 => 8 or 10
// 11 => 10
// 26 => 25
// 21 => 20
std::optional<int32_t> GetClosest(BSTNode* node, int32_t target);
std::optional<int32_t> GetClosestLogN(BSTNode* node, int32_t target);
} // namespace algo




#endif  // ALGO_CC_GET_CLOSEST_H
