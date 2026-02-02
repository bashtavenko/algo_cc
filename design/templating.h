#ifndef ALGO_CC_TEMPLATING_H
#define ALGO_CC_TEMPLATING_H

#include <numeric>
#include <type_traits>
#include <cassert>

namespace algo {

template <typename Container>
float GetAverageSimple(const Container& c) {
  double sum = 0.0;
  for (auto v : c) sum += v;
  return sum / c.size();
}

template <typename Container>
auto GetAverage(const Container& c) {
  using T = Container::value_type;
  static_assert(std::is_arithmetic_v<T>, "Container must hold numeric types");

  assert(!c.empty());

  // We don't know what type of value is in the container, int, float, double
  using sum_type = std::conditional_t<std::is_integral_v<T>, long double, T>;
  sum_type sum = std::accumulate(c.begin(), c.end(), sum_type{0});
  return sum / static_cast<sum_type>(c.size());
}

}  // namespace algo

#endif  // ALGO_CC_TEMPLATING_H
