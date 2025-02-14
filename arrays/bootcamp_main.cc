#include <gflags/gflags.h>
#include <glog/logging.h>
#include <algorithm>
#include <random>
#include "absl/strings/str_format.h"

void EvenOdd(std::vector<int32_t>& data) {
  size_t lo = 0;                 // even
  int32_t hi = data.size() - 1;  // odd
  while (lo < hi) {
    if (data[lo] % 2 == 0) {
      ++lo;
    } else {
      std::swap(data[lo], data[hi]);
      --hi;
    }
  }
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  FLAGS_logtostderr = 1;

  std::vector<int32_t> data = {2, 1, 3, 7, 8, 5};
  EvenOdd(data);
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
  // With initialization
  auto matrix_fixed =
      std::vector<std::vector<int32_t>>(2, std::vector<int32_t>(3, -1));
  LOG(INFO) << absl::StreamFormat("%ix%i [1][2] = %i", matrix_fixed.size(),
                                  matrix_fixed[0].size(), matrix_fixed[1][2]);

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

  // std::fill. Makes sense to partially fill data
  auto b2 = std::vector<int32_t>(7, -1);
  std::fill(b2.begin(), b2.begin() + 4, -42);

  // std::min_element and std::max_element
  std::vector<int32_t> v{3, 1, -4, 1, 5, 9};
  LOG(INFO) << absl::StreamFormat(
      "std::min_element = %i  std::max_element = %i",
      *std::min_element(v.begin(), v.end()),
      *std::max_element(v.begin(), v.end()));

  // std::reverse
  std::reverse(v.begin(), v.end());
  std::reverse(v.begin(), v.end());

  // std::rotate
  // That is, swap two portions of an array
  auto v2 = std::vector<int32_t>{1, 2, 3, 4, 5, 6, 7, 8, 9};
  // [3, 4, 5, 6, 7, 8, 9, 1, 2]  => rotated by 2
  std::rotate(v2.begin(), v2.begin() + 2, v2.end());

  std::sort(v2.begin(), v2.end());  // Default is ASC which is std::les
  std::random_device rd;
  std::mt19937 gen{rd()};
  std::ranges::shuffle(v2, gen);
  // If you want descending, then use std::greater<>()
  // std::less_equal<>() is default and should NOT be used in std::sort
  std::sort(v2.begin(), v2.end(), std::greater<>());  // Now it is DSC

  // Removing value in vector
  // std::erase + std::remove()
  // [9, 8, 7, 6...] 8 is gone
  v2.erase(std::remove(v2.begin(), v2.end(), 8), v2.end());

  return EXIT_SUCCESS;
}
