#include <gflags/gflags.h>
#include <glog/logging.h>

int64_t RunGCD(int64_t x, int64_t y) { return y == 0 ? x : RunGCD(y, x % y); }

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);

  LOG(INFO) << "GCD: " << RunGCD(156, 36);  // 12
  LOG(INFO) << "GCD: " << RunGCD(50, 6);    // 2
  LOG(INFO) << "GCD: " << RunGCD(13, 3);    // 1

  return EXIT_SUCCESS;
}