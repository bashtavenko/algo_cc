// Given the price of ice cream and available money, return
// two 1-base indices to maximize money
// [2, 1, 3, 5, 6] money 5
//  Answer 2 + 3
// [1, 4, 5, 3, 2] money 5
// Answer: 1 + 4
// [2, 2, 4, 3] money = 4
// Answer: 2 + 2
#ifndef ALGO_CC_HACKER_RANK_SEARCH_ICE_CREAM_H_
#define ALGO_CC_HACKER_RANK_SEARCH_ICE_CREAM_H_
#include <ostream>
#include <vector>

struct Result {
  int first_index = 0;
  int second_index = 0;

  bool operator==(const Result& other) const {
    return first_index == other.first_index &&
           second_index == other.second_index;
  }

  friend std::ostream& operator<<(std::ostream& os, const Result& that) {
    os << "(" << that.first_index << ", " << that.second_index << ")";
    return os;
  }
};

Result WhatFlavors(const std::vector<int>& cost, int money);

#endif  // ALGO_CC_HACKER_RANK_SEARCH_ICE_CREAM_H_
