#include "hacker_rank/one_month/week_2/counter_game.h"
#include <string>
std::string CounterGame(long n) {
  // Go from 1 past n and then back off.
  // Alternative:  1L << (63 - __builtin_clzl(n))
  auto largest_power_of_2 = [](long n) {
    long power = 1;
    while (power <= n) {
      power <<= 1;  // Keep shifting left (doubling) until power exceeds n
    }
    return power >> 1;  // The previous power of 2 is the largest ≤ n
  };

  int moves = 0;
  while (n > 1) {
    if ((n & (n - 1)) == 0) {
      n /= 2;  // If n is a power of 2, divide by 2
    } else {
      n -= largest_power_of_2(n);  // Reduce by largest one
    }
    moves++;
  }
  return (moves % 2 == 1) ? "Louise" : "Richard";
}