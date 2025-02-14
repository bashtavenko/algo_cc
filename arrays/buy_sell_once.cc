#include "arrays/buy_sell_once.h"
#include <limits>

namespace algo {

int32_t BuyAndSellStockOnce(const std::vector<int32_t>& prices) {
  int32_t current_min = std::numeric_limits<int32_t>::max();
  int32_t current_profit = 0;
  for (const int32_t& price : prices) {
    int profit_today = price - current_min;
    current_profit = std::max(current_profit, profit_today);
    current_min = std::min(current_min, price);
  }
  return current_profit;
}

}  // namespace algo
