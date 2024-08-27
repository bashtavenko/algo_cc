#include "dp/score_combinations.h"
#include <cstdint>
#include <vector>

namespace algo {

int32_t NumCombinationsForFinalScore(
    int32_t final_score, const std::vector<int32_t>& individual_play_scores) {
  //    final_score count (0, 1, 2, 3...)
  //  2  0 0 0 0
  //  3  . . . .
  //  7  . . . .
  std::vector<std::vector<int32_t>> num_combinations_for_score(
      individual_play_scores.size(), std::vector<int32_t>(final_score + 1, 0));

  for (size_t row = 0; row < individual_play_scores.size();
       ++row) {  // for each row
    // First column is 1
    num_combinations_for_score[row][0] = 1;
    // Now fill the rest with remaining columns
    for (int32_t col = 1; col <= final_score; ++col) {
      // Take the row above it
      int32_t without_this_play =
          row >= 1 ? num_combinations_for_score[row - 1][col] : 0;
      // Take current row but previous column
      int32_t with_this_play =
          col >= individual_play_scores[row]
              ? num_combinations_for_score[row]
                                          [col - individual_play_scores[row]]
              : 0;
      // Store array
      num_combinations_for_score[row][col] = with_this_play + without_this_play;
    }
  }
  return num_combinations_for_score.back().back();
}

}  // namespace algo