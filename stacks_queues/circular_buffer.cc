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

CircularBufferBasic::CircularBufferBasic(size_t size)
    : buffer_(size), head_(0), tail_(0), max_size_(size), full_(false) {};

void CircularBufferBasic::Push(int32_t item) {
  // Add the newest and adjust tail and correct head if needed
  if (full_) {
    head_ = (head_ + 1) % max_size_;
  }
  buffer_[tail_] = item;
  tail_ = (tail_ + 1) % max_size_;
  full_ = head_ == tail_;
}

absl::optional<int32_t> CircularBufferBasic::Pop() {
  // Get the oldest and increment head
  if (Empty()) return {};
  int32_t item = buffer_[head_];
  full_ = false;
  head_ = (head_ + 1) % max_size_;
  return item;
}

bool CircularBufferBasic::Empty() const { return (!full_ && (head_ == tail_)); }

size_t CircularBufferBasic::Size() const {
  if (full_) {
    return max_size_;
  }
  if (tail_ >= head_) {
    return tail_ - head_;
  }
  return max_size_ + tail_ - head_;
}

bool CircularBufferBasic::Full() const { return full_; }

}  // namespace algo
