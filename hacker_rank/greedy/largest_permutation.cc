#include "hacker_rank/greedy/largest_permutation.h"
#include <cmath>
#include <limits>
#include <unordered_map>
#include <vector>

// This is horrible
std::vector<int> LargestPermutationTooVerbose(const std::vector<int>& a,
                                              int k) {
  std::vector<int> arr(a.begin(), a.end());
  std::vector<std::vector<int>> result;
  std::unordered_map<size_t, int> index_value;

  // Find permutations
  //  for (size_t i = 0; i < arr.size() - 1; ++i) {
  for (size_t i = 0; i < k; ++i) {
    size_t j = i + 1;
    while (j < arr.size()) {
      std::swap(arr[j], arr[i]);
      result.push_back(arr);
      std::swap(arr[j], arr[i]);
      ++j;
    }
  }

  // Convert vector to int
  // 3 * 10^2 + 1 * 10^1
  for (size_t index = 0; index < result.size(); ++index) {
    int value = 0;
    for (int i = 0; i < result[0].size(); ++i) {
      value += result[index][i] * std::pow(10, result[0].size() - i - 1);
    }
    index_value[index] = value;
  }
  // Get input vector to int
  int arr_value = 0;
  for (int i = 0; i < arr.size(); ++i) {
    arr_value += arr[i] * std::pow(10, arr.size() - i - 1);
  }

  // Find index of the largest permutation
  int largest = std::numeric_limits<int>::min();
  int largest_index = 0;
  for (const auto& [k, v] : index_value) {
    if (v > largest) {
      largest = v;
      largest_index = k;
    }
  }

  return largest > arr_value ? result[largest_index] : arr;
}

// No reason to compute permutations - swap the largest digits.
// No reasons to convert vectors to int.
std::vector<int> LargestPermutation(const std::vector<int>& a, int k) {
  std::vector<int> arr(a.begin(), a.end());
  int n = arr.size();
  std::unordered_map<int, int> pos;

  // Store the position of each element
  for (int i = 0; i < n; ++i) {
    pos[arr[i]] = i;
  }

  for (int i = 0; i < n && k > 0; ++i) {
    // If the current element is not the largest possible
    if (arr[i] != n - i) {
      // Find the position of the largest possible element
      int idx = pos[n - i];

      // Swap the current element with the largest possible
      std::swap(arr[i], arr[idx]);

      // Update the positions in the map
      pos[arr[i]] = i;
      pos[arr[idx]] = idx;

      --k;
    }
  }

  return arr;
}