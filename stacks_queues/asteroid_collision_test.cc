#include "stacks_queues/asteroid_collision.h"
#include "include/gmock/gmock-matchers.h"
#include "include/gtest/gtest.h"

namespace algo {
namespace {
using ::testing::UnorderedElementsAreArray;

TEST(AsteroidCollision, Example1) {
  EXPECT_THAT(AsteroidCollision(std::vector<int32_t>{5, 10, -5}),
              UnorderedElementsAreArray(std::vector<int32_t>{5, 10}));
}

TEST(AsteroidCollision, Example2) {
  EXPECT_THAT(AsteroidCollision(std::vector<int32_t>{8, -8}),
              UnorderedElementsAreArray(std::vector<int32_t>{}));
}

}  // namespace
}  // namespace algo