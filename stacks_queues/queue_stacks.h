// 8.8 Queue using stacks
//
#ifndef ALGO_CC_STACKS_QUEUES_QUEUE_STACKS_H_
#define ALGO_CC_STACKS_QUEUES_QUEUE_STACKS_H_
#include <cstdint>
#include <stack>
#include "absl/types/optional.h"

namespace algo {
class Queue {
 public:
  void Enqueue(int32_t x);
  absl::optional<int32_t> Dequeue();

 private:
  std::stack<int32_t> enqueue_;
  std::stack<int32_t> dequeue_;
};

}  // namespace algo
#endif  // ALGO_CC_STACKS_QUEUES_QUEUE_STACKS_H_
