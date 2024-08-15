#include "hash_tables/palidrom.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <string>

namespace algo {
namespace {

TEST(CanFormPalidrome, Works) {
  EXPECT_TRUE(CanFormPalidrome("level"));
  EXPECT_TRUE(CanFormPalidrome("rotator"));
  EXPECT_TRUE(CanFormPalidrome("edified"));
}

}  // namespace
}  // namespace algo