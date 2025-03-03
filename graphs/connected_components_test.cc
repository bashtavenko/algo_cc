#include "graphs/connected_components.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(FindConnectedComponents, Example1) {
  EXPECT_THAT(FindConnectedComponents(std::vector<std::vector<int32_t>>{
                  {1, 1, 0}, {1, 1, 0}, {0, 0, 1}}),
              2);
}

TEST(FindConnectedComponents, Example2) {
  EXPECT_THAT(FindConnectedComponents(std::vector<std::vector<int32_t>>{
                  {1, 0, 0}, {0, 1, 0}, {0, 0, 1}}),
              3);
}
}  // namespace
}  // namespace algo