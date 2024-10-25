#include "hacker_rank/one_month/week_2/sum_xor.h"

long SumXorBruteForce(long n) {
  long count = 0l;
  for (long i = 0; i < n; ++i) {
    if (n + i == (n ^ i)) ++count;
  }
  return count;
}

// Key insights
// For the equation n + x == n ^ x to hold, no carry bits should occur when
// adding n and x.
//
// This means that whenever there’s a 1 bit in n, the corresponding bit in x
// must be 0, because adding 1 + 1 would result in a carry (which violates the
// equation). On the other hand, for every 0 bit in n, x can either be 0 or 1
// because adding 0 + 0 or 0 + 1 will not produce a carry.
long SumXor(long n) {
  // Count zero bits. n = 4 => 0x100
  // There are two zero bits
  long count = 0;

  while (n > 0) {
    if ((n & 1) == 0) {  // If the least significant bit is 0
      count++;
    }
    n >>= 1;  // Shift right by 1 to check the next bit
  }

  // Why 2^count?
  // Each 0 bit in n gives us two possibilities for the corresponding bit in x
  // (0 or 1), which leads to 2 choices for that position. If there are count
  // such 0 bits in n, the total number of valid x values is the product of
  // those choices, which is 2^count.
  return 1L << count;  // Return 2^count
}