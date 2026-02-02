#include "heaps/k_most_frequent.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(KMostFrequent, Works) {
  auto result =
      KMostFrequent(std::vector<int32_t>{2, 3, 5, 7, 1, 1, 1, 2, 3}, 2);
  EXPECT_THAT(result, testing::SizeIs(2));
}

}  // namespace
}  // namespace algo