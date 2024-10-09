#include <gflags/gflags.h>
#include <glog/logging.h>
#include "concurrency/thread_pool.h"

int main(int argc, char** argv) {
  using algo::ThreadPool;

  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);

  ThreadPool pool(4);  // Create a thread pool with 4 worker threads

  // Enqueue some tasks
  for (int i = 0; i < 8; ++i) {
    pool.Enqueue([i] {
      LOG(INFO) << "Task " << i << " executed by thread "
                << std::this_thread::get_id();
      absl::SleepFor(absl::Milliseconds(100));  // Simulate some work
    });
  }

  // The destructor of ThreadPool will wait for all tasks to complete
  LOG(INFO) << "All tasks enqueued. Waiting for completion...";

  // Sleep to allow time for tasks to complete before pool is destroyed
  absl::SleepFor(absl::Seconds(2));

  return EXIT_SUCCESS;
}