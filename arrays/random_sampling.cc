#include "arrays/random_sampling.h"
#include <random>

namespace algo {

void RandomSampling(size_t k, std::vector<int32_t>& a) {
  std::default_random_engine seed((std::random_device())());
  for (size_t i = 0; i < k; ++i) {
    size_t new_index =
        std::uniform_int_distribution<size_t>{i, a.size() - 1}(seed);
    std::swap(a[i], a[new_index]);
  }
}

}  // namespace algo
