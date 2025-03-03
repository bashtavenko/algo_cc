#include "graphs/visit_rooms.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(CanVisitAllRooms, Example1) {
  EXPECT_TRUE(
      CanVisitAllRooms(std::vector<std::vector<int32_t>>{{1}, {2}, {3}, {}}));
}

TEST(CanVisitAllRooms, Example2) {
  EXPECT_FALSE(CanVisitAllRooms(
      std::vector<std::vector<int32_t>>{{1, 3}, {3, 0, 1}, {2}, {0}}));
}

}  // namespace
}  // namespace algo