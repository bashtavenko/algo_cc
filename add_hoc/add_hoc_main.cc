#include <unordered_set>
#include "gflags/gflags.h"
#include "glog/logging.h"

void Run() {
  // abciiidef
  std::string_view jewels = "Abfe";
  std::string_view stones = "bAtz";

  std::unordered_set<char> dictionary;
  for (const auto& entry : jewels) dictionary.insert(entry);
  size_t result = 0;
  for (const auto& stone : stones) {
    result += dictionary.contains(stone);
  }
  LOG(INFO) << result;
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  FLAGS_alsologtostderr = 1;
  Run();
  return EXIT_SUCCESS;
}
