#include "sorting/array_intersection.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <vector>

namespace algo {
namespace {

TEST(Intersect, Works) {
  const std::vector<int32_t> a{2, 3, 3, 5, 5, 6, 7, 7, 8, 12};
  const std::vector<int32_t> b{5, 5, 6, 8, 8, 9, 10, 10};
  const std::vector<int32_t> want_vertices{5, 6, 8};
  EXPECT_THAT(Intersect(a, b), want_vertices);
}

}  // namespace
}  // namespace algo