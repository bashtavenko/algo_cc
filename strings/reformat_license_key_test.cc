#include "strings/reformat_license_key.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(Reformat, Example1) {
  EXPECT_THAT(Reformat("5F3Z-2e-9-w", 4), "5F3Z-2E9W");
}

TEST(Reformat, Example2) { EXPECT_THAT(Reformat("2-5g-3-J", 2), "2-5G-3J"); }

}  // namespace
}  // namespace algo