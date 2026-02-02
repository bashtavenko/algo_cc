#include "design/templating.h"
#include <deque>
#include <list>
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

using ::testing::FloatNear;

TEST(GetAverageSimple, Works) {
  EXPECT_THAT(GetAverageSimple(std::vector{1, 2, 3, 4, 5}), FloatNear(3, 0.1));

  EXPECT_THAT(GetAverageSimple(std::deque{1, 2, 3, 4, 5}), FloatNear(3, 0.1));

  EXPECT_THAT(GetAverageSimple(std::list{1, 2, 3, 4, 5}), FloatNear(3, 0.1));
}

TEST(GetAverage, Works) {
  // It does not compile if strings are used
  // GetAverage(std::vector{"a", "b"});

  EXPECT_THAT(static_cast<float>(GetAverage(std::vector{1, 2, 3, 4, 5})),
              FloatNear(3, 0.1));
}

}  // namespace
}  // namespace algo