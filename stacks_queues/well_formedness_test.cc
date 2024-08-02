#include "stacks_queues/well_formedness.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(WellFormedness, Works) {
  EXPECT_TRUE(IsWellFormed("{}()[]"));
  EXPECT_FALSE(IsWellFormed("{)"));
}

}  // namespace
}  // namespace algo
