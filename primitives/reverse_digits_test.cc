#include "primitives/reverse_digits.h"

#include <gtest/gtest.h>

namespace algo {
namespace {

TEST(Reverse, Works) {
  EXPECT_EQ(2311, Reverse(1132));
}

} // namespace
} // namespace algo


