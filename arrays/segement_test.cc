#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <vector>
#include "arrays/segment.h"

namespace algo {
namespace {

TEST(GetLargestWithBudget, Works) {
  EXPECT_THAT(GetLargestWithBudget(std::vector<int32_t>{3, 1, 1, 2, 1, 1}, 4),
              Segment(3, 5));
}

}  // namespace
}  // namespace algo