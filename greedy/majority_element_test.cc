#include "greedy/majority_element.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "absl/strings/string_view.h"

namespace algo {
namespace {

std::vector<std::string> MakeData(absl::string_view s) {
  std::vector<std::string> data;
  for (const auto& c : s) {
    data.push_back(std::string{c});
  }
  return data;
}

TEST(MajoritySearch, Works) {
  std::vector<std::string> data = MakeData("bacaaaabaac");
  EXPECT_THAT(MajoritySearch(data.begin(), data.end()), "a");
  data = MakeData("bbbbcaa");
  EXPECT_THAT(MajoritySearch(data.begin(), data.end()), "b");
}

}  // namespace
}  // namespace algo