#include "arrays/delete_dups.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {
using testing::Eq;

TEST(Dups, Works) {
  auto data = std::vector<int32_t>{2, 3, 5, 5, 7, 11, 11, 11, 13};
  EXPECT_THAT(DeleteDuplicates(data), Eq(5));
  EXPECT_THAT(data, Eq(std::vector<int32_t>{2, 3, 5, 7, 11, 13, 11, 11, 13}));
}
}  // namespace
}  // namespace algo
