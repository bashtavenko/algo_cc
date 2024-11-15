#include "hacker_rank/arrays/left_rotation.h"
#include <algorithm>
#include <vector>

// [1, 2, 3, 4, 5]
// [2, 3, 4, 5, 1]  1 - 5

void RotateOne(std::vector<int>* a) {
  std::vector<int>& data = *a;
  int lsd = data.front();
  for (size_t i = 1; i < data.size(); ++i) {
    data[i - 1] = data[i];
  }
  data.back() = lsd;
}

// O (n*k)
std::vector<int> RotateLeftFirstTry(const std::vector<int>& a, int k) {
  std::vector<int> result(a);

  for (int i = 1; i <= k; ++i) {
    RotateOne(&result);
  }
  return result;
}

// O (n)
// Reverse up to k, reverse everything after k, then reverse everything
// [1, 2, 3, 4, 5] k = 2
// [2, 1, 3, 4, 5] Reverse up to k
// [2, 1, 5, 4, 3] Reverse from k to the end
// [3, 4, 5, 1, 2] Final reverse
std::vector<int> RotateLeft(const std::vector<int>& a, int k) {
  std::vector<int> result(a);
  std::reverse(result.begin(), result.begin() + k);
  std::reverse(result.begin() + k, result.end());
  std::reverse(result.begin(), result.end());

  return result;
}

std::vector<int> RotateLeftSTD(const std::vector<int>& a, int k) {
  std::vector<int> result(a);
  std::rotate(result.begin(), result.begin() + k, result.end());
  return result;
}