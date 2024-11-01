#include "hacker_rank/one_month/week_3/bomberman.h"
#include <string>
#include <vector>

std::vector<std::string> BomberMan(int n,
                                   const std::vector<std::string>& grid) {
  const int rows = grid.size();
  const int cols = grid[0].size();
  constexpr char kBomb = 'O';
  constexpr char kClear = '.';

  // If n == 1, just return the initial grid
  if (n == 1) return grid;

  // Full bomb grid for any even n (2, 4, ...)
  std::vector<std::string> full_bombs(rows, std::string(cols, kBomb));

  // Helper function for the detonation step
  auto detonate_bombs = [&](const std::vector<std::string>& input) {
    std::vector<std::string> output(rows, std::string(cols, kBomb));
    constexpr int kShift[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (int row = 0; row < rows; ++row) {
      for (int col = 0; col < cols; ++col) {
        if (input[row][col] == kBomb) {
          output[row][col] = kClear;
          for (auto& [dy, dx] : kShift) {
            int new_y = row + dy;
            int new_x = col + dx;
            if (new_y >= 0 && new_y < rows && new_x >= 0 && new_x < cols)
              output[new_y][new_x] = kClear;
          }
        }
      }
    }
    return output;
  };

  // After full bomb plant, simulate the two alternating states
  std::vector<std::string> state1 = detonate_bombs(grid);
  std::vector<std::string> state2 = detonate_bombs(state1);

  // Determine the result based on (n % 4)
  if (n % 4 == 1) return state2;
  if (n % 4 == 3) return state1;
  return full_bombs;  // For any even n
}