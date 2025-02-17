#include <gflags/gflags.h>
#include <glog/logging.h>
#include <algorithm>
#include <string>
#include <vector>
#include "absl/strings/str_format.h"

struct Student {
  std::string name;
  double grade_point_average;

  bool operator>(const Student& that) const { return name < that.name; }
};

void Run() {
  std::vector<Student> data{Student("a", 2.3), Student("b", 3.5),
                            Student("c", 3.9)};

  // 1. Lambda comparator
  std::sort(data.begin(), data.end(), [](const Student& a, const Student& b) {
    return a.grade_point_average > b.grade_point_average;
  });

  LOG(INFO) << "Lambda comparator";
  for (const auto& student : data) {
    LOG(INFO) << absl::StreamFormat("%s - %f", student.name,
                                    student.grade_point_average);
  }

  // 2. Operator overload with standard comparators to sort DESC
  std::sort(data.begin(), data.end(), std::greater<>());

  LOG(INFO) << "Operator comparator";
  for (const auto& student : data) {
    LOG(INFO) << absl::StreamFormat("%s - %f", student.name,
                                    student.grade_point_average);
  }
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);
  FLAGS_logtostderr = 1;
  Run();

  return EXIT_SUCCESS;
}