#include "arrays/buy_sell_once.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

namespace algo {
namespace {

TEST(BuyAndSellStockOnce, Works) {
  EXPECT_THAT(BuyAndSellStockOnce(std::vector<int32_t>{2, 3, 10, 6, 4, 8, 1}),
              8);
}

}  // namespace
}  // namespace algo