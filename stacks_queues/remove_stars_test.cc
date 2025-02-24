#include "stacks_queues/remove_stars.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace algo {

TEST(RemoveStars, Example1) {
  EXPECT_THAT(RemoveStars("leet**cod*e"), "lecoe");
}

TEST(RemoveStars, Example2) { EXPECT_THAT(RemoveStars("erase*****"), ""); }

}  // namespace algo
}  // namespace algo