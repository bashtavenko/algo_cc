#include <gflags/gflags.h>
#include <glog/logging.h>
#include "absl/strings/str_format.h"
#include <random>

int16_t CountBits(uint32_t x) {
  int16_t num_bits = 0;
  while (x) {
    num_bits += x & 1;
    x >>= 1;
  }
  return num_bits;
}

int main(int argc, char **argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  LOG(INFO) << absl::StreamFormat("Counted %d bits from %x", CountBits(7), 7);
  LOG(INFO) << absl::StreamFormat("6 & 4 = %x", 6 & 4); // 4
  LOG(INFO) << absl::StreamFormat("1 | 2 = %x", 1 | 2); // 3
  LOG(INFO) << absl::StreamFormat("8 > 1 = %x", 8 >> 1); // 4
  LOG(INFO) << absl::StreamFormat("1 << 10 = 0x%x", 1 << 10);
  // ~ is bitwise NOT
  LOG(INFO) << absl::StreamFormat("~0 0x%x", ~0); // 0xffffffff
  LOG(INFO) << absl::StreamFormat("std::numeric_limits<int32_t>::min() %i", std::numeric_limits<int32_t>::min());
  LOG(INFO)
      << absl::StreamFormat("std::numeric_limits<float_t>::infinity() %f", std::numeric_limits<float_t>::infinity());
  LOG(INFO) << absl::StreamFormat("%v", std::rand());

  auto dist = std::uniform_int_distribution<>(1, 25);
  std::random_device rd;  // a seed source for the random number engine
  std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
  LOG(INFO) << absl::StreamFormat("std::uniform_int_distribution<> %v", dist(gen));
  LOG(INFO) << absl::StreamFormat("%f", std::generate_canonical<double, 10>(gen));

  // std::swap works by references, not by values.
  // This could work for any types such as containers or anything, mostly.
  int x = 1;
  int y = 2;
  LOG(INFO) << absl::StreamFormat("x = %v y = %v", x, y);
  std::swap(x, y);
  LOG(INFO) << absl::StreamFormat("x = %v y = %v", x, y);


  return EXIT_SUCCESS;
}
