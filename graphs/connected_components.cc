#include "graphs/connected_components.h"
#include <functional>
#include <unordered_map>
#include <unordered_set>

namespace algo {

//   0 1 2
// 0  1 1 0
// 1  1 1 0
// 2  0 0 1
int32_t FindConnectedComponentsTooComplicated(
    const std::vector<std::vector<int32_t>>& matrix) {
  const int32_t n = matrix.size();
  struct PairHash {
    size_t operator()(const std::pair<int32_t, int32_t>& p) const {
      return std::hash<int32_t>{}(p.first) ^
             (std::hash<int32_t>{}(p.second) << 1);
    }
  };
  std::unordered_set<std::pair<int32_t, int32_t>, PairHash> visited;
  std::unordered_map<int32_t, int32_t> connected;  // from - to

  std::function<void(const std::pair<int32_t, int32_t>&)> dfs =
      [&](const std::pair<int32_t, int32_t>& p) {
        static constexpr int32_t kOffset[4][2] = {
            {0, 1}, {0, -1}, {1, 0}, {1, -1}};  // {x, y}
        visited.insert(p);

        for (const auto& [dx, dy] : kOffset) {
          int32_t next_x = p.first + dx;
          int32_t next_y = p.second + dy;

          // Bound checks
          if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n &&
              !visited.contains({next_x, next_y})) {
          }
        }
      };

  auto start = std::make_pair(0, 0);
  dfs(start);

  return connected.size();
}

// This is adjacency matrix
int32_t FindConnectedComponents(
    const std::vector<std::vector<int32_t>>& matrix) {
  const int32_t n = matrix.size();
  std::vector<bool> visited(n, false);
  int32_t provinces = 0;

  // DFS helper: for a given city, mark all cities in its connected component.
  std::function<void(int32_t)> dfs = [&](int32_t city) {
    for (int32_t j = 0; j < n; ++j) {
      if (matrix[city][j] == 1 && !visited[j]) {
        visited[j] = true;
        dfs(j);
      }
    }
  };

  // For each city, if it's not visited, then it's a new province.
  for (int32_t i = 0; i < n; ++i) {
    if (!visited[i]) {
      ++provinces;
      visited[i] = true;
      dfs(i);
    }
  }

  return provinces;
}

}  // namespace algo
