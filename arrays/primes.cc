#include "arrays/primes.h"
#include <deque>
#include <vector>

namespace algo {
std::vector<int32_t> Generate(uint16_t n) {
  std::vector<int32_t> primes;

  std::deque<bool> is_prime(n + 1, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (auto p = 2; p <= n; ++p) {
    if (is_prime[p]) {
      primes.emplace_back(p);
      for (auto i = p; i <= n; i += p) {
        is_prime[i] = false;
      }
    }
  }
  return primes;
}
}  // namespace algo
