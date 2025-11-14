// Louise and Richard have developed a numbers game. They pick a number and check
// to see if it is a power of 2. If it is, they divide it by 2. If not, they
// reduce it by the next lower number which is a power of 2. Whoever reduces the
// number to 1 wins the game. Louise always starts.
//
// Given an initial value, determine who wins the game.
//
// Example
// n = 123
//
// It's Louise's turn first. She determines that  132 is not a power of 2. The
// next lower power of  is 128, so she subtracts that from 132 and passes 4 to
// Richard. 4  is a power of 2, so Richard divides it by 2  and passes 2 to
// Louise. Likewise,  2 is a power so she divides it by  2 and reaches 1 . She
// wins the game.
//
// Update If they initially set counter to 1, Richard wins. Louise cannot make a
// move so she loses.
// This is the most horrible interview problem that I have ever seen.
//
#include <string>
std::string CounterGame(long n);

#ifndef ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_2_COUNTER_GAME_H_
#define ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_2_COUNTER_GAME_H_

#endif  // ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_2_COUNTER_GAME_H_
