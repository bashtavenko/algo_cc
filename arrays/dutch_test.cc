#include "arrays/dutch.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <vector>
#include "absl/strings/str_format.h"

namespace algo {

// This is required for testing, but it could be a part of the header.
std::string_view ColorToString(Color color) {
  switch (color) {
    case Color::kRed:
      return "Red";
    case Color::kWhite:
      return "White";
    case Color::kBlue:
      return "Blue";
    default:
      return "Unknown";
  }
}

std::ostream& operator<<(std::ostream& os, Color color) {
  os << absl::StreamFormat("%s", ColorToString(color));
  return os;
}

namespace {
TEST(Dutch, Works) {
  using enum Color;
  auto data =
      std::vector<Color>{kRed, kWhite, kBlue, kRed, kBlue, kWhite, kWhite};
  const auto expected =
      std::vector<Color>{kRed, kRed, kBlue, kBlue, kWhite, kWhite, kWhite};
  DutchFlagPartition(3, data);
  EXPECT_THAT(data, expected);
}
}  // namespace
}  // namespace algo
