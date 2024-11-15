#include "hacker_rank/one_month/week_2/super_digit.h"
#include <functional>
#include <string>

// Problematic with conversion and concatenating which can cause
// very large string to concatenate.
int SuperDigitBruteForce(const std::string& n, int k) {
  //  9+8+7+5 = 29
  //  2 + 9 = 11
  std::function<int(const std::string&)> recurse = [&](const std::string& s) {
    if (s.length() == 1) return std::stoi(s);

    int sum = 0;
    for (size_t i = 0; i < s.length(); ++i) {
      sum += std::stoi(std::string{s[i]});
    }
    return recurse(std::to_string(sum));
  };

  std::string p;
  for (int i = 0; i < k; ++i) {
    p += n;
  }

  return recurse(p);
}

int SuperDigitOkay(const std::string& n, int k) {
  // Helper function to calculate the super digit recursively
  // Key insight - recurse on integer rather than string
  std::function<int(int)> recurse = [&](int sum) {
    if (sum < 10) return sum;  // Single digit
    int new_sum = 0;
    while (sum > 0) {
      new_sum += sum % 10;
      sum /= 10;
    }
    return recurse(new_sum);  // Recursively call with the sum of digits
  };

  // Calculate the sum of digits in string `n`
  int initial_sum = 0;
  for (char digit : n) {
    // Fastest and the most efficient way to convert character digit to int.
    initial_sum += digit - '0';
  }

  // Multiply by `k` to account for the repetition
  int total_sum = initial_sum * k;

  // Find and return the super digit of the total sum
  return recurse(total_sum);
}

// Final case that passes all the unit test.
// No recursion.
// Modulo 9 Optimization: Instead of recursively reducing the sum, we use the
// fact that the super digit corresponds to the sum modulo 9, with the exception
// that if the result is 0, the super digit is 9 (unless the sum is 0).
// For example:
// super_digit(9875)   	9 + 8 + 7 + 5 = 29
// super_digit(29) 	2 + 9 = 11
// super_digit(11)	1 + 1 = 2
// super_digit(2)	= 2
// 29 % 9 = 2. No reason to recurse.
int SuperDigit(const std::string& n, int k) {
  // Calculate the sum of digits in the string `n`
  long long initial_sum = 0;
  for (char digit : n) {
    initial_sum += digit - '0';  // Convert char to int and sum it
  }

  // Multiply the sum of digits by `k`
  long long total_sum = initial_sum * k;

  // Find the super digit using modulo 9 properties
  auto super_digit = [](long long sum) {
    // If sum is divisible by 9 and non-zero, the super digit is 9
    return (sum % 9 == 0 && sum != 0) ? 9 : sum % 9;
  };

  return super_digit(total_sum);
}