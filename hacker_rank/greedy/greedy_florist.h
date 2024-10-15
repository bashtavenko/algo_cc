// A group of friends want to buy a bouquet of flowers. The florist wants to
// maximize his number of new customers and the money he makes. To do this, he
// decides he'll multiply the price of each flower by the number of that
// customer's previously purchased flowers plus 1. The first flower will be
// original price, (0 + 1) x original_price, the next will be (1 + 1) x original
// price and so on.
// When I buy the first flower, I pay the original price
// If I buy a second flower, I'd pay (1 + 1) x original_price, i.e. 2 *
// original_price. If you buy a third flower, it will be (2 + 1) x original
// price
//  The first flower costs $2 (the original price).
// The second flower you buy would cost $3 (2 × $2 = $4).
// The third flower would cost even more (3 × $2 = $6), and it keeps increasing
// for each additional flower you purchase.
//
// ******
// Price increase on subsequent purchases.
// ****
// Given the size of the group of friends, the number of flowers they want to
// purchase and the original prices of the flowers, determine the minimum cost
// to purchase for all the flowers. The number of flowers they want equals the
// length of the c array.
//
// Example: c = [1, 2, 3, 4] k = 3 The length of c = 4, so they want to
// buy 4 flowers total. Each will buy one of the flowers priced [2, 3, 4] at the
// original price. Having each purchased x = 1 flower, the first flower in the
// list c[0], will now cost (current_price
// + previous_purchase) x c[0] = (1 + 1) x 1 = 2. The total cast is 2 + 3 + 4 +
// 2 = 11

#ifndef ALGO_CC_HACKER_RANK_GREEDY_GREEDY_FLORIST_H_
#define ALGO_CC_HACKER_RANK_GREEDY_GREEDY_FLORIST_H_
#include <vector>

int GetMinimumCost(int k, std::vector<int> c);

#endif  // ALGO_CC_HACKER_RANK_GREEDY_GREEDY_FLORIST_H_
