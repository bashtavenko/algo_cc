#include "searching/first_occurrence.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <vector>

namespace algo {
namespace {

TEST(FirstOccurrence, Works) {
  const std::vector<int32_t> data{-14, -10, 2,   108, 108,
                                  243, 285, 285, 285, 401};
  EXPECT_THAT(SearchFirst(data, 108), 3);
}

}  // namespace
}  // namespace algo