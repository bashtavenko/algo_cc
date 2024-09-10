#include "hacker_rank/strings/string_child.h"
#include <string>
#include <vector>

void GenerateCombinations(const std::string& s, int start, int k,
                          std::string& current,
                          std::vector<std::string>& result) {
  if (k == 0) {
    result.push_back(current);
    return;
  }

  for (int i = start; i <= s.length() - k; ++i) {
    current.push_back(s[i]);
    GenerateCombinations(s, i + 1, k - 1, current, result);
    current.pop_back();
  }
}

std::vector<std::string> NChooseK(const std::string& s, int k) {
  std::vector<std::string> result;
  std::string current;

  if (k == 0 || k > s.length()) {
    return result;
  }

  GenerateCombinations(s, 0, k, current, result);
  return result;
}

// "ABCD", "ABDC" => {"ABC", "ABD"} 3
// "HARRY", "SALLY" => {"AY", "AY"} 2
int CommonChild(const std::string& s1, const std::string& s2) {
  size_t the_longest = 0;
  for (size_t length = 2; length < s1.size(); ++length) {
    auto first_children = NChooseK(s1, length);
    auto second_children = NChooseK(s2, length);

    for (const std::string& first : first_children) {
      for (const std::string& second : second_children) {
        if (first.size() == second.size() && first == second) {
          the_longest = std::max(the_longest, first.length());
        }
      }
    }
  }
  return the_longest;
}

// Twe way it works is that this reduces to the longest common
// subsequence
// For example, for "ABCD" and "ABDC" the dp table is this:
//  0 0 0 0 0
//  0 1 1 1 1
//  0 1 2 2 2
//  0 1 2 2 3
//  0 1 2 3 3
int CommonChildDP(const std::string& s1, const std::string& s2) {
  int n = s1.length();

  // Create a 2D DP table
  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

  // Fill the DP table
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  // The bottom-right cell contains the length of the longest common
  // subsequence
  return dp[n][n];
}