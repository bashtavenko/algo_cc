#include "hacker_rank/one_month/week_2/counter_game.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(CounterGame, Works) { EXPECT_THAT(CounterGame(123), "Louise"); }

}  // namespace