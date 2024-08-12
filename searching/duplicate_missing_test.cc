#include "searching/duplicate_missing.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <vector>

namespace algo {
namespace {

TEST(FindDuplicateAndMissing, Works) {
  std::vector<int32_t> data{5, 3, 0, 1, 2};
  DuplicateAndMissing result = FindDuplicateAndMissing(data);
  EXPECT_THAT(result.missing, 4);

  data = {3, 3, 0, 1, 2, 4};
  result = FindDuplicateAndMissing(data);
  EXPECT_THAT(result.duplicate, 3);
}

}  // namespace
}  // namespace algo