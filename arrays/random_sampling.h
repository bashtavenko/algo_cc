// 5.12 Sampling offline data
#ifndef ALGO_CC_ARRAYS_RANDOM_SAMPLING_H_
#define ALGO_CC_ARRAYS_RANDOM_SAMPLING_H_

#include <cstdint>
#include <vector>

namespace algo {

// Sample k-samples for the given array
void RandomSampling(size_t k, std::vector<int32_t>& a);

}  // namespace algo

#endif  // ALGO_CC_ARRAYS_RANDOM_SAMPLING_H_
