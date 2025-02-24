#include "searching/find_peak.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {

TEST(FindPeak, Example1) {
  EXPECT_THAT(FindPeak(std::vector<int32_t>{1, 2, 3, 1}), 2);
}

TEST(FindPeak, Example2) {
  EXPECT_THAT(FindPeak(std::vector<int32_t>{1, 2, 1, 3, 5, 6, 4}), 5);
}

TEST(FindPeak, Example3) { EXPECT_THAT(FindPeak(std::vector<int32_t>{1}), 0); }

}  // namespace
}  // namespace algo