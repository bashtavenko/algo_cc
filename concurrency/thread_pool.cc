#include "concurrency/thread_pool.h"

namespace algo {

ThreadPool::ThreadPool(size_t num_threads) : stop_(false) {
  workers_.reserve(num_threads);
  for (size_t i = 0; i < num_threads; ++i) {
    workers_.emplace_back([this] { this->worker_thread_(); });
  }
}
ThreadPool::~ThreadPool() {
  {
    absl::MutexLock lock(queue_mutex_);
    stop_ = true;
  }
  condition_.SignalAll();
  for (std::thread& worker : workers_) {
    worker.join();
  }
}

void ThreadPool::Enqueue(std::function<void()> f) {
  {
    absl::MutexLock lock(queue_mutex_);
    tasks_.emplace(std::move(f));
  }
  condition_.Signal();
}

void ThreadPool::worker_thread_() {
  while (true) {
    std::function<void()> task;
    {
      // Mutex lock scope
      absl::MutexLock lock(queue_mutex_);
      while (!stop_ && tasks_.empty()) {
        condition_.Wait(&queue_mutex_);  // Sleep when there's no work
      }
      if (stop_ && tasks_.empty()) {
        return;
      }
      // There's a task in the queue.
      task = std::move(tasks_.front());
      tasks_.pop();
    }
    task();  // Execute the task
  }
}

}  // namespace algo