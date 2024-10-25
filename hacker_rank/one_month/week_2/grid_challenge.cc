#include <algorithm>
#include <string>
#include <vector>

bool GridChallenge(std::vector<std::string>& grid) {
  const int m = grid.size();
  const int n = grid[0].size();

  // Sort each row ascending
  for (int i = 0; i < m; ++i) {
    std::sort(grid[i].begin(), grid[i].end());
  }

  // Check if columns are ascending as well
  for (int col = 0; col < n; ++col) {
    for (int row = 1; row < m; ++row) {
      if (grid[row][col] < grid[row - 1][col]) {
        return false;
      }
    }
  }
  return true;
}
