#include <gflags/gflags.h>
#include <glog/logging.h>

// Greatest common divisor (GCD). [50, 6] => 2
int64_t RunGCD(int64_t x, int64_t y) { return y == 0 ? x : RunGCD(y, x % y); }

// Least common multiplier. Opposite of GCD
// Multiples of 4 is 4, 8, 12, 16...
// Multiples of 6 are 6, 12, 18, 24...
// LCM (4, 6) are 12, 24, 36
int64_t RunLCM(int64_t x, int64_t y) { return (x * y) / RunGCD(x, y); }

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);
  FLAGS_logtostderr = 1;

  LOG(INFO) << "GCD: " << RunGCD(156, 36);  // 12
  LOG(INFO) << "GCD: " << RunGCD(50, 6);    // 2
  LOG(INFO) << "GCD: " << RunGCD(13, 3);    // 1
  LOG(INFO) << "LCM: " << RunLCM(4, 6);     // 12

  return EXIT_SUCCESS;
}