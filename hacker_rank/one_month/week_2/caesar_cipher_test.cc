#include "hacker_rank/one_month/week_2/caesar_cipher.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace {

TEST(CaesarCipher, Works) {
  EXPECT_THAT(CaesarCipher("middle-Outz", 2), "okffng-Qwvb");
}
}  // namespace