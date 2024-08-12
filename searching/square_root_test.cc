#include "searching/square_root.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {
static constexpr double kNear = 0.1;

TEST(RealRoot, Works) {
  double result = SquareRoot(5.0);
  EXPECT_THAT(result, testing::DoubleNear(2.3, kNear));
}
}  // namespace
}  // namespace algo