#include <gflags/gflags.h>
#include <glog/logging.h>
#include <queue>
#include <vector>
#include "absl/strings/str_format.h"

// Find the longest strings that we have seen so far in a stream;
// This is the first version with lambda.
std::vector<std::string> TopK(
    size_t k, std::vector<std::string>::const_iterator stream_begin,
    const std::vector<std::string>::const_iterator& stream_end) {
  // * type of elements
  // * container
  // * compare
  std::priority_queue<std::string, std::vector<std::string>,
                      std::function<bool(std::string, std::string)>>
      min_heap([](const std::string& a, const std::string& b) {
        return a.size() >= b.size();
      });

  while (stream_begin != stream_end) {
    min_heap.emplace(*stream_begin);
    if (min_heap.size() > k) {
      // Remove the shortest string
      min_heap.pop();
    }
    ++stream_begin;
  }

  std::vector<std::string> result;
  while (!min_heap.empty()) {
    result.emplace_back(min_heap.top());
    min_heap.pop();
  }

  return result;
}

void Run() {
  std::vector<std::string> st{{"ab", "def", "bacccesddd", "a", "xyz"}};

  auto result = TopK(2, st.cbegin(), st.cend());
  for (const auto& s : result) {
    LOG(INFO) << s;
  }
  // results: {"def", "bacccesddd"}
}

// This is much more simpler. Define type with operator.
// std::greater<>> min_heap;
// or, I guess std::less<>> max_heap
struct LongestString {
  std::string value;

  bool operator>(const LongestString& that) const {
    return value.size() > that.value.size();
  }
};

std::vector<std::string> TopK2(
    size_t k, std::vector<std::string>::const_iterator stream_begin,
    const std::vector<std::string>::const_iterator& stream_end) {
  // * type of elements
  // * container
  // * compare
  std::priority_queue<LongestString, std::vector<LongestString>, std::greater<>>
      min_heap;

  while (stream_begin != stream_end) {
    min_heap.emplace(LongestString{*stream_begin++});
    if (min_heap.size() == k + 1) {
      // Remove the shortest string
      min_heap.pop();
    }
  }

  std::vector<std::string> result;
  while (!min_heap.empty()) {
    result.emplace_back(min_heap.top().value);
    min_heap.pop();
  }

  return result;
}

void Run2() {
  std::vector<std::string> st{{"ab", "def", "bacccesddd", "a", "xyz"}};

  auto result = TopK2(2, st.cbegin(), st.cend());
  for (const auto& s : result) {
    LOG(INFO) << s;
  }
  // results: {"def", "bacccesddd"}
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);
  Run2();

  return EXIT_SUCCESS;
}