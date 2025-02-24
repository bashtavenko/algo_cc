#include "strings/compression.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {
using ::testing::Eq;

TEST(Compress, Example1Works) {
  const std::string example1("aabbccc");
  auto chars = std::vector<char8_t>(example1.begin(), example1.end());
  EXPECT_THAT(Compress(chars), Eq(6));
}

TEST(Compress, Example2Works) {
  const std::string example("abbbbbbbbbbbb");
  auto chars = std::vector<char8_t>(example.begin(), example.end());
  EXPECT_THAT(Compress(chars), Eq(4));
}

TEST(Compress, Example3Works) {
  const std::string example("a");
  auto chars = std::vector<char8_t>(example.begin(), example.end());
  EXPECT_THAT(Compress(chars), Eq(1));
}

}  // namespace
}  // namespace algo