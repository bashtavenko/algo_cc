#include "arrays/primes.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(Primes, Works) {
  auto const expected = std::vector<int32_t>{2, 3, 5, 7, 11};
  EXPECT_THAT(Generate(11), expected);
}
}  // namespace
}  // namespace algo
