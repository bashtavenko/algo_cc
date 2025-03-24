#include "hash_tables/occupied_desks.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(OccupiedDesks, Example1) {
  EXPECT_EQ(OccupiedDesks(12, {2, 6, 7, 11}), 6);
}

}  // namespace
}  // namespace algo