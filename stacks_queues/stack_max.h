// 8.1 Stack with max API
#ifndef ALGO_CC_STACKS_QUEUES_STACK_MAX_H_
#define ALGO_CC_STACKS_QUEUES_STACK_MAX_H_
#include <cstdint>
#include <stack>
#include "absl/types/optional.h"

namespace algo {
class Stack {
 public:
  bool Empty() const;
  absl::optional<int32_t> Max() const;
  absl::optional<int32_t> Pop();
  void Push(int32_t x);

 private:
  // The idea is to store element and their max
  // 1, 2, 7, 4

  // 4, 7
  // 7, 7
  // 2, 2
  // 1, 1
  struct ElementWithCacheMax {
    int32_t element;
    int32_t max;
  };
  std::stack<ElementWithCacheMax> element_with_cache_max_;
};

}  // namespace algo

#endif  // ALGO_CC_STACKS_QUEUES_STACK_MAX_H_
