#include <gflags/gflags.h>
#include <glog/logging.h>
#include "concurrency/thread_pool.h"
#include <mutex>
#include <atomic>
#include <condition_variable>

struct Position {
  int32_t x;
  int32_t y;
};

class Facade {
public:
  void Enqueue(Position position) {
    {
      std::lock_guard<std::mutex> lock(mutex_);
      position_.emplace_back(position);
    }
    cv_.notify_all();
  }

  Position GetLatest() {
    std::unique_lock<std::mutex> lock(mutex_);
    cv_.wait(lock, [&]{ return !position_.empty(); });
    return position_.back();
  }

  std::vector<Position> SnapshotAll() {
    std::lock_guard<std::mutex> lock(mutex_);
    return position_;  // Copy out
  }

private:
  mutable std::mutex mutex_;
  std::condition_variable cv_;
  std::vector<Position> position_;
};


class FacadeAtomic {
public:
  FacadeAtomic() : has_value_(false) {}

  // Enqueue should not be blocked by GetLatest
  void Enqueue(Position position) {
    latest_.store(position, std::memory_order_release);
    has_value_.store(true, std::memory_order_release);
  }


  // GetLatest can be blocked by should not block the Enqueue()
  // After wait it should return the latest.
  Position GetLatest() const {
    // Busy-wait until we have at least one value
    while (!has_value_.load(std::memory_order_acquire)) {
      // optional: std::this_thread::yield(); or sleep/backoff
    }
    return latest_.load(std::memory_order_acquire);
  }

private:
  std::atomic<Position> latest_;
  std::atomic<bool> has_value_;
};


int main(int argc, char** argv) {
  using algo::ThreadPool;

  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);


  return EXIT_SUCCESS;
}