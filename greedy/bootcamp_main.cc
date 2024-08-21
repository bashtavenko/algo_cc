#include <gflags/gflags.h>
#include <glog/logging.h>
#include <cstdint>
#include "absl/strings/str_format.h"

int32_t MakeChange(int32_t cents) {
  static constexpr int32_t kCoins[6] = {100, 50, 25, 10, 5, 1};
  int32_t num_coins = 0;
  for (int32_t coin : kCoins) {
    num_coins += cents / coin;
    cents %= coin;
  }
  return num_coins;
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);
  LOG(INFO) << MakeChange(75);
  EXIT_SUCCESS;
}
