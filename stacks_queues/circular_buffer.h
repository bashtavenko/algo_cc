// 8.7 Circular buffer
// There are two implementations - dynamic sizing and fixed sizing.
#include <cstdint>
#include <vector>
#include "absl/synchronization/mutex.h"
#include "absl/types/optional.h"

#ifndef ALGO_CC_STACKS_QUEUES_CIRCULAR_BUFFER_H_
#define ALGO_CC_STACKS_QUEUES_CIRCULAR_BUFFER_H_

namespace algo {

// Dynamic sizing. It never shrinks. When it doubles, it copes data.
class CircularBuffer {
 public:
  explicit CircularBuffer(size_t capacity) : entries_(capacity) {};
  void Enqueue(int32_t x);
  absl::optional<int32_t> Dequeue();

  // This is the actual size of the data, not some internal vector sizes.
  size_t Size() const { return num_entries_; };

 private:
  static constexpr int32_t kScaleFactor = 2;
  int32_t head_ = 0;
  int32_t tail_ = 0;
  size_t num_entries_ = 0;
  std::vector<int32_t> entries_;
};

// This is a basic CircularBuffer with int.
// It is essentially a queue with two pointers
// head points to the oldest items and tail with
// the newest one.
// Overwrite the oldest.
class CircularBufferBasic {
 public:
  explicit CircularBufferBasic(size_t size);
  void Push(int32_t item);
  absl::optional<int32_t> Pop();
  bool Empty() const;
  bool Full() const;
  size_t Size() const;

 private:
  //  Oldest
  // [1, 2, 3]
  //  H     T
  std::vector<int32_t> buffer_;
  size_t head_;  // Head of the queue; the oldest
  size_t tail_;  // Tail of the queue; the newest
  size_t max_size_;
  bool full_ = false;
};

// Thread safe basic circular buffer
class CircularBufferThreadSafe {
 public:
  explicit CircularBufferThreadSafe(size_t size);

  void Push(int32_t item);        // Blocking or drop-oldest
  absl::optional<int32_t> Pop();  // Return empty if no data
  bool Empty() const;
  bool Full() const;
  size_t Size() const;

 private:
  mutable absl::Mutex mu_;  // Protects all shared state

  std::vector<int32_t> buffer_ ABSL_GUARDED_BY(mu_);
  size_t head_ ABSL_GUARDED_BY(mu_);  // the oldest
  size_t tail_ ABSL_GUARDED_BY(mu_);  // the newest
  size_t max_size_ ABSL_GUARDED_BY(mu_);
  bool full_ ABSL_GUARDED_BY(mu_);
};

}  // namespace algo
#endif  // ALGO_CC_STACKS_QUEUES_CIRCULAR_BUFFER_H_
