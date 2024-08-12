#include "searching/search_smallest.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <vector>

namespace algo {
namespace {

TEST(SearchSmallest, Works) {
  const std::vector<int32_t> data{378, 478, 550, 631, 103,
                                  203, 220, 234, 279, 368};
  EXPECT_THAT(SearchSmallest(data), 4);
}

}  // namespace
}  // namespace algo