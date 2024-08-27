// 16.1 Score combinations.
//
// Given 2, 3 and 7 points,
//
// 1 way to get to 4:
// 2 + 2
//
// 2 ways to get to 7:
// 7
// 2 + 2 + 3
//
// 4 ways to get 12:
// 2 x 6
// 2 x 3 + 3 x 2
// 2 x 1 + 3 x 1 + 7 x 1
// 3 x 4
//
// 2D array to store the number of score combinations that result in
// a total of j:
// scores    0 1   2   3   4   5   6   7   ... 12
// 2         1 0   1   0   1 0   1   0       1  ( 2 x 6)
// 2,3       1 0   1   1   1   1   2   1       3
// 2,3,7     1 0   1   1   1   1   2   2       4
//
#ifndef ALGO_CC_DP_SCORE_COMBINATIONS_H_
#define ALGO_CC_DP_SCORE_COMBINATIONS_H_

#include <cstdint>
#include <vector>

namespace algo {

int32_t NumCombinationsForFinalScore(
    int32_t final_score, const std::vector<int32_t>& individual_play_scores);

}  // namespace algo

#endif  // ALGO_CC_DP_SCORE_COMBINATIONS_H_
