#include <gflags/gflags.h>
#include <glog/logging.h>
#include <algorithm>
#include <cstdint>
#include <vector>
#include "absl/strings/str_format.h"

int32_t Search(int32_t target, const std::vector<int32_t>& data) {
  size_t lo = 0;
  size_t hi = data.size() - 1;
  while (lo <= hi) {
    size_t mid = lo + (hi - lo) / 2;
    if (target < data[mid]) {
      hi = mid - 1;  // the target must be something on the left
    } else if (target >
               data[mid]) {  // the target must be something on the right
      lo = mid + 1;
    } else {
      return mid;
    }
  }
  // No exact match.
  return lo;
}

struct Student {
  std::string name;
  double grade_point_average;
};

void RunBinarySearch() {
  const std::vector<Student> students{Student("a", 2.3), Student("b", 3.5),
                                      Student("c", 3.9)};
  const Student target{Student("b", 3.6)};
  auto comp = [](const Student& a, const Student& b) {
    if (a.grade_point_average != b.grade_point_average) {
      return a.grade_point_average > b.grade_point_average;
    }
    return a.name > b.name;
  };

  auto it = std::lower_bound(students.begin(), students.end(), target, comp);
  LOG(INFO) << absl::StreamFormat("Found: Student{%s, %f}", it->name,
                                  it->grade_point_average);

  LOG(INFO) << absl::StreamFormat(
      "Searching for %s. Found: %i", target.name,
      std::binary_search(students.begin(), students.end(), target, comp));
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);
  FLAGS_logtostderr = 1;

  const std::vector<int32_t> data{1, 3, 5, 7, 11, 13, 15, 17};
  LOG(INFO) << absl::StreamFormat("v = %i => %i", 5, Search(5, data));
  LOG(INFO) << absl::StreamFormat("v = %i => %i", 14, Search(14, data));

  RunBinarySearch();

  return EXIT_SUCCESS;
}