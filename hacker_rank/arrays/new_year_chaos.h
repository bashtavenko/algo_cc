// It is New Year's Day and people are in line for the Wonderland roller coaster
// ride. Each person wears a sticker indicating their initial position in the
// queue from 1 to n.
//
// Any person can bribe the person directly in front of them to
// swap positions, but they still wear their original sticker. One person can
// bribe at most two others.
//
// Determine the minimum number of bribes that took place to get to a given
// queue order. Print the number of bribes, or, if anyone has bribed more than
// two people, print "Too chaotic".
//
// Examples:
// q = [1, 2, 3, 4, 5, 6, 7, 8]
// If 5 bribes 4 => [1, 2, 3, 5, 4, 6, 7, 8]. Bribes: 1
// q = [1, 2, 3, 4]
//     [2, 1, 3, 4] -> [1, 2, 4, 3] -> [1, 4, 2, 3] -> [4, 1, 2, 3] 3 swaps, too
//     chaotic
// q = [1, 2, 3, 4, 5]
// q = [1, 2, 3, 5, 4] 5 moved
// q = [1, 2, 5, 3, 4] 5 moved again
// q = [2, 1, 5, 3, 4] 2 moved
// Swaps = 3

#ifndef ALGO_CC_HACKER_RANK_ARRAYS_NEW_YEAR_CHAOS_H_
#define ALGO_CC_HACKER_RANK_ARRAYS_NEW_YEAR_CHAOS_H_

#include <vector>
struct Result {
  int bribes = 0;
  bool too_chaotic = false;
};
// Returns number of swaps or -1 for "Too chaotic"
Result MinimumSwaps(const std::vector<int>& q);

#endif  // ALGO_CC_HACKER_RANK_ARRAYS_NEW_YEAR_CHAOS_H_
