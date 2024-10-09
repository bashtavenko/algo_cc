#include <gflags/gflags.h>
#include <glog/logging.h>
#include <iostream>
#include <vector>
#include "absl/synchronization/mutex.h"
#include "absl/synchronization/notification.h"

absl::Mutex mu_;
int shared_counter_ ABSL_GUARDED_BY(mu_) = 0;
absl::Notification work_done_;

void Worker(int id, int iterations) {
  for (int i = 0; i < iterations; ++i) {
    // RAII
    absl::MutexLock lock(&mu_);
    ++shared_counter_;
    LOG(INFO) << "Thread " << id << " incremented counter to "
              << shared_counter_;
  }

  if (id == 0) {
    work_done_.Notify();
  }
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);

  constexpr int kNumThreads = 5;
  constexpr int kIterationsPerThread = 10;
  std::vector<std::thread> threads;

  for (int i = 0; i < kNumThreads; ++i) {
    threads.emplace_back(Worker, i, kIterationsPerThread);
  }

  work_done_.WaitForNotification();
  LOG(INFO) << "Work done notification received.";

  for (auto& t : threads) {
    t.join();
  }

  {
    absl::MutexLock lock(&mu_);
    LOG(INFO) << "Final counter value: " << shared_counter_;
  }
  return EXIT_SUCCESS;
}