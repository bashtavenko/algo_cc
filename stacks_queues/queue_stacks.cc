#include "stacks_queues/queue_stacks.h"

namespace algo {

void Queue::Enqueue(int32_t x) { enqueue_.emplace(x); }

absl::optional<int32_t> Queue::Dequeue() {
  if (dequeue_.empty()) {
    while (!enqueue_.empty()) {
      dequeue_.emplace(enqueue_.top());
      enqueue_.pop();
    }
  }

  // Still empty
  if (dequeue_.empty()) return std::nullopt;

  int32_t ret = dequeue_.top();
  dequeue_.pop();
  return ret;
}

}  // namespace algo