#include "graphs/visit_rooms.h"
#include <functional>
#include <unordered_set>

namespace algo {

bool CanVisitAllRooms(const std::vector<std::vector<int32_t>>& rooms) {
  const int n = rooms.size();
  std::vector<bool> visited(n, false);

  std::function<void(int)> dfs = [&](int room) {
    if (visited[room]) return;
    visited[room] = true;
    for (int key : rooms[room]) {
      dfs(key);
    }
  };

  dfs(0);

  // Check if every room has been visited.
  for (bool v : visited) {
    if (!v) return false;
  }
  return true;
}

}  // namespace algo
