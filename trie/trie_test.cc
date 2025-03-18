#include "trie/trie.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(Trie, Example1) {
  auto trie = std::make_unique<Trie>();
  trie->Insert("apple");
  EXPECT_TRUE(trie->Search("apple"));
  EXPECT_FALSE(trie->Search("app"));
  EXPECT_TRUE(trie->StartsWith("app"));
  trie->Insert("app");
  EXPECT_TRUE(trie->Search("app"));
}

}  // namespace
}  // namespace algo