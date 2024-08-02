#include "stacks_queues/circular_buffer.h"
#include <cstdint>
#include "absl/types/optional.h"

namespace algo {

void CircularBuffer::Enqueue(int32_t x) {
  if (num_entries_ == entries_.size()) {
    // Resize

    // Performs a left rotation on a range of elements.
    // To make sure elements should appear consequently.
    // I have no idea why this is needed.
    std::rotate(entries_.begin(), entries_.begin() + head_, entries_.end());

    head_ = 0;
    tail_ = num_entries_;
    entries_.resize(entries_.size() * kScaleFactor);
  }
  entries_[tail_] = x;
  tail_ = (tail_ + 1) % entries_.size();  // Should be in range
  ++num_entries_;
}
absl::optional<int32_t> CircularBuffer::Dequeue() {
  if (!num_entries_) return {};

  --num_entries_;
  int32_t value = entries_[head_];
  // Mod size - just to make sure the head is in between 0...size - 1
  head_ = (head_ + 1) % entries_.size();
  return value;
}

}  // namespace algo
