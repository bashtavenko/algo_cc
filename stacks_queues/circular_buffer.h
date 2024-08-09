// 8.7 Circular buffer
// Not very useful. Not a circular buffer, just doubles periodically
#include <cstdint>
#include <vector>
#include "absl/types/optional.h"
#ifndef ALGO_CC_STACKS_QUEUES_CIRCULAR_BUFFER_H_
#define ALGO_CC_STACKS_QUEUES_CIRCULAR_BUFFER_H_

namespace algo {

class CircularBuffer {
 public:
  explicit CircularBuffer(size_t capacity) : entries_(capacity){};
  void Enqueue(int32_t x);
  absl::optional<int32_t> Dequeue();

  // This is actual size of the data, not some internal vector sizes.
  size_t Size() const { return num_entries_; };

 private:
  static constexpr int32_t kScaleFactor = 2;
  int32_t head_ = 0;
  int32_t tail_ = 0;
  size_t num_entries_ = 0;
  std::vector<int32_t> entries_;
};

}  // namespace algo

#endif  // ALGO_CC_STACKS_QUEUES_CIRCULAR_BUFFER_H_
