#include "stacks_queues/longest_path.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(LongestPath, Example1) {
  EXPECT_EQ(LongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"), 20);
}

TEST(LongestPath, Example2) {
  EXPECT_EQ(
      LongestPath(
          "dir\n\tsubdir1\n\t\tfile1."
          "ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"),
      32);
}

TEST(LongestPath, Example3) { EXPECT_EQ(LongestPath("a"), 0); }

}  // namespace
}  // namespace algo