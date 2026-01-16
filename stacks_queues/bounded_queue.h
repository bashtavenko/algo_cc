// Thread-safe, fixed-sze, in-memory bounded queue.
// A bounded queue is a FIFO queue with a fixed maximum capacity that
// enforces backpressure.
#ifndef ALGO_CC_BOUNDED_QUEUE_H
#define ALGO_CC_BOUNDED_QUEUE_H
#include <cstdint>
#include <mutex>
#include <vector>

namespace algo {

template <typename T>
class BoundedQueue {
 public:
  explicit BoundedQueue(size_t capacity)
      : buffer_(capacity), head_(0), tail_(0), size_(0), capacity_(capacity) {}

  // Blocks if full. Guarantees that Push never writes when the queue is full.
  void Push(T item) {
    // Acquires the mutex to protect the queue state
    std::unique_lock<std::mutex> lock(mutex_);
    // Unlocks automatically - wait until space is available.
    not_full_.wait(lock, [this] { return size_ < capacity_; });

    buffer_[tail_] = std::move(item);
    tail_ = (tail_ + 1) % capacity_;
    ++size_;
    not_empty_.notify_one();  // wake a waiting consumer
  }
  // Blocks if empty
  T Pop() {
    std::unique_lock<std::mutex> lock(mutex_);
    not_empty_.wait(lock, [this] { return size_ > 0; });

    T item = std::move(buffer_[head_]);
    head_ = (head_ + 1) % capacity_;
    --size_;

    not_full_.notify_one();  // wake a waiting producer
    return item;
  }

 private:
  std::mutex mutex_;
  std::condition_variable not_empty_;
  std::condition_variable not_full_;

  std::vector<T> buffer_;
  size_t head_;
  size_t tail_;
  size_t size_;
  const size_t capacity_;
};

}  // namespace algo

#endif  // ALGO_CC_BOUNDED_QUEUE_H
