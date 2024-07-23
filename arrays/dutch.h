#ifndef ALGO_CC_ARRAYS_DUTCH_H_
#define ALGO_CC_ARRAYS_DUTCH_H_

#include <cstdint>
#include <vector>

// 4.1 Dutch national flag
namespace algo {
enum class Color { kRed, kWhite, kBlue };
void DutchFlagPartition(size_t pivot_index, std::vector<Color>* data);
}  // namespace algo

#endif  // ALGO_CC_ARRAYS_DUTCH_H_
