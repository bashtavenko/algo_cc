#include "strings/mnemonic.h"
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {
using ::testing::ContainerEq;

TEST(PhoneMnemonic, Works) {
  const std::vector<std::string> want = {"AD", "AE", "AF", "BD", "BE",
                                         "BF", "CD", "CE", "CF"};
  EXPECT_THAT(PhoneMnemonic("23"), ContainerEq(want));
}

}  // namespace
}  // namespace algo