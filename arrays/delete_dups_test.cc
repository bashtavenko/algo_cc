#include "arrays/delete_dups.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {
using testing::Eq;

TEST(Dups, Works) {
  const auto want = std::vector<int32_t>{2, 3, 5, 7, 11, 13, 11, 11, 13};
  auto data = std::vector<int32_t>{2, 3, 5, 5, 7, 11, 11, 11, 13};
  EXPECT_THAT(DeleteDuplicates(data), testing::Eq(5));
  EXPECT_THAT(data, testing::Eq(want));
}
}  // namespace
}  // namespace algo
