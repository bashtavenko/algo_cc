#include "gflags/gflags.h"
#include "glog/logging.h"
#include <unordered_set>

void Run() {
  // abciiidef
  std::string s = "abciiidef";
  int32_t k = 2;
  static const std::unordered_set<char8_t> kVowels = {'a', 'e', 'i', 'o', 'u'};
  int32_t result = 0;
  for (int32_t i = 0; i < s.size() - k; ++i) {
    int32_t current_max = 0;
    for (int32_t j = 0; j < k; ++j) {
      current_max += kVowels.contains(s[i + j]);
    }
    result = std::max(result, current_max);
  }
  LOG(INFO) << result;
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  FLAGS_alsologtostderr = 1;
  Run();
  return EXIT_SUCCESS;
}
