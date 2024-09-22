#include "arrays/buy_sell_once.h"
#include <limits>

namespace algo {

int32_t BuyAndSellStockOnce(const std::vector<int32_t>& prices) {
  int32_t min_price_so_far = std::numeric_limits<int32_t>::max();
  int32_t max_profit = 0;
  for (const int32_t& price : prices) {
    int max_profit_today = price - min_price_so_far;
    max_profit = std::max(max_profit, max_profit_today);
    min_price_so_far = std::min(min_price_so_far, price);
  }
  return max_profit;
}

}  // namespace algo
