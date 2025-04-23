#include "glog/logging.h"
#include "gflags/gflags.h"

void Run() {
  std::vector<int32_t> input{1, 2, 3, 105, 106, 107, 108, 300, 301};
  int32_t start_window_index = 0;
  int32_t end_window_index = 1;
  constexpr int32_t kWindowSize = 100;
  int32_t max_count = 0;

  while (end_window_index < input.size()) {
    if (input[end_window_index] - input[start_window_index] < kWindowSize) {
      // Window is valid, expand it
      ++end_window_index;
    } else {
      // Window too big, move start forward
      ++start_window_index;
    }
    max_count = std::max(max_count, end_window_index - start_window_index);
  }

  LOG(INFO) << max_count;
}


int main(int argc, char **argv) {
  google::InitGoogleLogging(argv[0]);
  FLAGS_alsologtostderr = 1;
  Run();
  return EXIT_SUCCESS;
}
