#include "arrays/random_sampling.h"
#include "gtest/gtest.h"

namespace algo {
namespace {

TEST(RandomSampler, Works) {
  auto data = std::vector<int32_t>{3, 7, 5, 11};
  RandomSampling(3, data);
}

}  // namespace
}  // namespace algo