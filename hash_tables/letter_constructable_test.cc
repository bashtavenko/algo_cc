#include "hash_tables/letter_constructable.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {

TEST(IsLetterConstructable, Works) {
  EXPECT_TRUE(IsLetterConstructable("finished Initial",
                                    "Initial directory update finished"));

  EXPECT_FALSE(IsLetterConstructable("finished Initial", "Initial"));
}

}  // namespace
}  // namespace algo