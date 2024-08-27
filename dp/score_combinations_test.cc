#include "dp/score_combinations.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <vector>

namespace algo {
namespace {

TEST(NumCombinationsForFinalScore, Works) {
  EXPECT_THAT(NumCombinationsForFinalScore(12, std::vector<int32_t>{2, 3, 7}),
              4);
}

}  // namespace
}  // namespace algo