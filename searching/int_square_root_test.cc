#include "searching/int_square_root.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {

TEST(SquareRoot, Works) {
  EXPECT_THAT(SquareRoot(16), 4);
  EXPECT_THAT(SquareRoot(300), 17);
  EXPECT_THAT(SquareRoot(21), 4);
  EXPECT_THAT(SquareRoot(25), 5);
}

}  // namespace
}  // namespace algo