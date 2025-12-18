#include "graphs/enclosed_regions.h"
#include <queue>
#include <vector>

namespace algo {

// Sets this cell and its neighbor cells to T for W cells.
void ChangeWtoT(size_t x, size_t y, std::vector<std::vector<char>>& board) {
  // Start from the top left corner
  struct Coordinate {
    size_t x;  // columns
    size_t y;  // rows
  };

  std::queue<Coordinate> q;
  q.push(Coordinate(x, y));
  while (!q.empty()) {
    const Coordinate curr = q.front();
    q.pop();
    if (curr.x >= 0 && curr.x < board[0].size() && curr.y >= 0 &&
        curr.y < board.size() && board[curr.y][curr.x] == 'W') {
      board[curr.y][curr.x] = 'T';
      // Queue up all neighbours. Some of those can be out of bound;
      q.emplace(Coordinate(curr.x - 1, curr.y));
      q.emplace(Coordinate(curr.x + 1, curr.y));
      q.emplace(Coordinate(curr.x, curr.y - 1));
      q.emplace(Coordinate(curr.x, curr.y + 1));
    }
  }
}

void FillSurroundedRegions(std::vector<std::vector<char>>& board) {
  // Step 1. Change W to T on 4 edges.
  // First and last columns, rows 0 ... last
  for (size_t x = 0; x < board.front().size(); ++x) {
    if (board[0][x] == 'W') {  // First row
      ChangeWtoT(x, 0, board);
    }
    if (board[board.front().size() - 1][x] == 'W') {  // Last row
      ChangeWtoT(x, board.front().size() - 1, board);
    }
  }
  // First and last rows, columns 0 ... last
  for (size_t y = 0; y < board.size(); ++y) {
    if (board[y][0] == 'W') {  // First column
      ChangeWtoT(0, y, board);
    }
    if (board[y][board.size() - 1] == 'W') {  // last column
      ChangeWtoT(board.size() - 1, y, board);
    }
  }

  // Step 2 - change 'T' to 'W'. Cells that reach the boundary will be back out.
  // If there were no 'T' then change to 'B'. Meaning that those cells DID NOT
  // reach the boundary.
  for (std::vector<char>& row : board) {
    for (char& c : row) {
      c = c != 'T' ? 'B' : 'W';
    }
  }
}

}  // namespace algo
