// Basic thread pool
//
#ifndef ALGO_CC_CONCURRENCY_THREAD_POOL_H_
#define ALGO_CC_CONCURRENCY_THREAD_POOL_H_

#include <functional>
#include <queue>
#include <thread>
#include <vector>
#include "absl/synchronization/mutex.h"
#include "absl/time/time.h"

namespace algo {

class ThreadPool {
 public:
  explicit ThreadPool(size_t num_threads);
  ~ThreadPool();
  void Enqueue(std::function<void()> f);

 private:
  std::vector<std::thread> workers_;
  std::queue<std::function<void()>> tasks_;
  absl::Mutex mu_;
  absl::CondVar condition_;
  bool stop_  = false;
  void worker_thread_();
};

}  // namespace algo

#endif  // ALGO_CC_CONCURRENCY_THREAD_POOL_H_
