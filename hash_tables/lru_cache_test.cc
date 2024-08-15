#include "hash_tables/lru_cache.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {
using ::testing::Optional;

TEST(LRUCache, Works) {
  auto cache = LRUCache(2);
  cache.Insert('a', 1);
  cache.Insert('b', 2);
  // This should evict 'a', leaving us with 'b' and 'c'
  cache.Insert('c', 3);

  EXPECT_THAT(cache.Lookup('a'), std::nullopt);
  EXPECT_THAT(cache.Lookup('b'), Optional(2));
  EXPECT_THAT(cache.Lookup('c'), Optional(3));

  // This should evict 'b'
  cache.Insert('d', 4);
  EXPECT_THAT(cache.Lookup('b'), std::nullopt);
}

}  // namespace
}  // namespace algo