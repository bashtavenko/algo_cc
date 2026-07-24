#include <gflags/gflags.h>
#include <glog/logging.h>
#include <execution>
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
    absl::MutexLock lock(mu_);
    ++shared_counter_;
    LOG(INFO) << "Thread " << id << " incremented counter to "
              << shared_counter_;
  }

  if (id == 0) {
    work_done_.Notify();
  }
}

void ProcessDataParallel(std::vector<double>& data) {
  // std::execution::seq - standard sequential execution
  // std::execution::par - parallel execution across multiple threads
  // std::execution::par_unseq - paralllel and unsequential execution SIMD
  std::for_each(std::execution::par_unseq, data.begin(), data.end(),
                [](double& val) { val = val * val + 3.14159; });
  LOG(INFO) << "Parallel total:"
            << std::reduce(std::execution::par, data.begin(), data.end(), 0.0);
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);
  FLAGS_logtostderr = true;

  constexpr int kNumThreads = 5;
  constexpr int kIterationsPerThread = 10;
  std::vector<std::thread> threads;

  for (int i = 0; i < kNumThreads; ++i) {
    threads.emplace_back(Worker, i, kIterationsPerThread);
  }

  work_done_.WaitForNotification();
  LOG(INFO) << "Work done notification received.";

  for (auto& t : threads) {
    t.join();  // Blocks the current thread `t` until `Worker` is done
  }

  {
    absl::MutexLock lock(mu_);
    LOG(INFO) << "Final counter value: " << shared_counter_;
  }

  std::vector<double> data = {1., 2., 3};
  ProcessDataParallel(data);
  return EXIT_SUCCESS;
}