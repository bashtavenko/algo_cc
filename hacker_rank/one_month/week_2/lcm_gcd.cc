#include "hacker_rank/one_month/week_2/lcm_gcd.h"
#include <functional>

std::vector<int> GetX(const std::vector<int>& a, const std::vector<int>& b) {
  std::function<int(int, int)> run_gcd = [&](int x, int y) {
    return y == 0 ? x : run_gcd(y, x % y);
  };

  std::function<int(int, int)> run_lcm = [&](int x, int y) {
    return (x * y) / run_gcd(x, y);
  };

  // Calculate LCM of 'a'
  int lcm = a[0];
  for (size_t i = 1; i < a.size(); ++i) {
    lcm = run_lcm(lcm, a[i]);
  }

  // Calculate GCD of 'b'
  int gcd = b[0];
  for (size_t i = 1; i < b.size(); ++i) {
    gcd = run_gcd(gcd, b[i]);
  }

  std::vector<int> result;
  for (int multiple = lcm; multiple <= gcd; multiple += lcm) {
    if (gcd % multiple == 0) result.push_back(multiple);
  }
  return result;
}