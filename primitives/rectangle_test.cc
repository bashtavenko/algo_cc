#include "primitives/rectangle.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {

TEST(Rectangle, Works) {
  Rectangle a = {.x = 0, .y = 50, .width = 50, .height = 10};
  Rectangle b = {.x = 0, .y = 40, .width = 100, .height = 40};
  Rectangle c = {.x = 200, .y = 0, .width = 20, .height = 20};

  auto const expected = Rectangle{.x = 0, .y = 50, .width = 50, .height = 10};
  EXPECT_THAT(a.IsIntersect(b), expected);
  EXPECT_THAT(a.IsIntersect(c), absl::nullopt);
}
}  // namespace
}  // namespace algo
