#include "hash_tables/equal_pairs.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(EqualPairs, Example1) {
  EXPECT_THAT(EqualPairs(std::vector<std::vector<int32_t>>{
                  {3, 2, 1}, {1, 7, 6}, {2, 7, 7}}),
              1);
}

TEST(EqualPairs, Example2) {
  EXPECT_THAT(EqualPairs(std::vector<std::vector<int32_t>>{
                  {3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}}),
              3);
}

}  // namespace
}  // namespace algo