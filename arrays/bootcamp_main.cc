#include <gflags/gflags.h>
#include <glog/logging.h>
#include <algorithm>
#include "absl/strings/str_format.h"

void EvenOdd(std::vector<int32_t>* x) {
  std::vector<int32_t>& data = *x;
  int32_t next_even = 0;
  int32_t next_odd = data.size() - 1;
  while (next_even < next_odd) {
    if (data[next_even] % 2 == 0) {
      ++next_even;
    } else {
      std::swap(data[next_even], data[next_odd]);
      --next_odd;
    }
  }
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  std::vector<int32_t> data = {2, 1, 3, 7, 8, 5};
  EvenOdd(&data);
  LOG(INFO) << absl::StreamFormat("Partitioned: %v ", data.size());

  //  std::array<int32_t, 3> a = {1, 2, 3};
  std::vector<int32_t> b = {1, 2, 3, 4, 5, 6, 12};
  LOG(INFO) << "Back: " << b.back();

  // Python "slicing". It is a copy, of course.
  std::vector<int32_t> slice(b.begin() + 1, b.begin() + 4);
  b[1] = -1;
  LOG(INFO) << absl::StreamFormat("b[1] = %i, slice[0] = %i", b[1], slice[0]);

  // 2D array
  std::vector<std::vector<int32_t>> matrix = {{1, 2, 3}, {4, 5, 6}};
  LOG(INFO) << absl::StreamFormat("It is %ix%i matrix.", matrix.size(),
                                  matrix[0].size());

  // std::binary_search
  std::vector<int32_t> sorted_data = {1, 3, 4, 5, 8, 11, 13};
  LOG(INFO) << (std::binary_search(sorted_data.begin(), sorted_data.end(), 5)
                    ? "Found"
                    : "Not");

  // std::lower_bound
  auto lo = std::lower_bound(sorted_data.begin(), sorted_data.end(), 5);
  LOG(INFO) << absl::StreamFormat(
      "std::lower_bound = %i, std::distance = %i", *lo,
      std::distance(sorted_data.begin(), lo));  // 5, 3

  // std::fill
  //  std::fill(b.begin(), b.begin() + 4, -42);

  // std::min_element
  std::vector<int32_t> v{3, 1, -4, 1, 5, 9};
  LOG(INFO) << absl::StreamFormat(
      "std::min_element = %i  std::max_element = %i",
      *std::min_element(v.begin(), v.end()),
      *std::max_element(v.begin(), v.end()));

  // std::reverse
  std::reverse(v.begin(), v.end());
  std::reverse(v.begin(), v.end());

  // std::rotate
  // 3, 1, -4, 1, 5, 9}
  // [-4, 1, 5, 9, 3, 1]  => rotated by 2
  std::rotate(v.begin(), v.begin() + 2, v.end());

  std::sort(v.begin(), v.end());

  // Removing value in vector
  // erase + std::remove()
  // data.erase(std::remove(data.begin(), data.end(), value), data.end());

  return EXIT_SUCCESS;
}
