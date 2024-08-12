#include "hash_tables/nearest_repeated.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <vector>

namespace algo {
namespace {

TEST(FindNearestRepeated, Works) {
  const std::string text(
      "All work and no play makes for no work no fun and no results");

  std::vector<std::string> data;
  std::string token;
  std::stringstream ss(text);

  while (std::getline(ss, token, ' ')) {
    data.emplace_back(token);
  }

  EXPECT_THAT(FindNearestRepeated(data), 2);
};

}  // namespace
}  // namespace algo