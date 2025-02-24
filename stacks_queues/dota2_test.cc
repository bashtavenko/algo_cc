#include "stacks_queues/dota2.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(PredictPartyVictory, Example1) {
  EXPECT_THAT(PredictPartyVictory("RD"), "Radiant");
}

TEST(PredictPartyVictory, Example2) {
  EXPECT_THAT(PredictPartyVictory("RDD"), "Dire");
}

TEST(PredictPartyVictory, Example3) {
  EXPECT_THAT(PredictPartyVictory("D"), "Dire");
}

}  // namespace
}  // namespace algo