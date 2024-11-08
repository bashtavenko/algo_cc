#include "hacker_rank/one_month/week_4/lego_blocks.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(LegoBlocks, Works) {
  EXPECT_THAT(LegoBlocks(2, 3), 9);  // WIP, it should be 9
  // TODO: SIGABRT
  //  EXPECT_THAT(LegoBlocks(2, 2), 3);
}

}  // namespace
