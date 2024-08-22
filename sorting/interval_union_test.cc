#include "sorting/interval_union.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <vector>

namespace algo {
namespace {

TEST(MakeUnion, Works) {
  const std::vector<Interval> data = {
      {Interval{{true, 0}, {true, 3}}},
      {Interval{{false, 1}, {false, 1}}},
      {Interval{{false, 2}, {false, 4}}},
      {Interval{{false, 3}, {true, 4}}},
  };

  const std::vector<Interval> want{{{true, 0}, {true, 4}}};
  EXPECT_THAT(MakeUnion(data), want);
}

}  // namespace
}  // namespace algo