#ifndef ALGO_CC_HACKER_RANK_SORTING_COMPARATOR_H_
#define ALGO_CC_HACKER_RANK_SORTING_COMPARATOR_H_

#include <ostream>
#include <string>

struct Player {
  std::string name;
  int score;

  bool operator==(const Player& other) const {
    return name == other.name && score == other.score;
  }

  friend std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "(" << player.name << ", " << player.score << ")";
    return os;
  }
};

class Checker {
 public:
  static int Comparator(Player a, Player b) {
    if (a.score != b.score) return a.score > b.score;
    return a.name < b.name;
  }
};

#endif  // ALGO_CC_HACKER_RANK_SORTING_COMPARATOR_H_
