// We define super digit of an integer  using the following rules:
//
// Given an integer, we need to find the super digit of the integer.//
// If x has only  digit, then its super digit is x .
// Otherwise, the super digit of x is equal to the super digit of the sum of the
// digits of x.
//
//  Example of super digit of 9875
//
//	super_digit(9875)   	9 + 8 + 7 + 5 = 29
//	super_digit(29) 	2 + 9 = 11
//	super_digit(11)		1 + 1 = 2
//	super_digit(2)		= 2
//
#ifndef ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_2_SUPER_DIGIT_H_
#define ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_2_SUPER_DIGIT_H_
#include <string>

int SuperDigit(const std::string& n, int k);

#endif  // ALGO_CC_HACKER_RANK_ONE_MONTH_WEEK_2_SUPER_DIGIT_H_
