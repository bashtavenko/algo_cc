// Given an integer array nums, return an array answer such that answer[i] is
// equal to the product of all the elements of nums except nums[i].
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
#ifndef ALGO_CC_ARRAYS_PRODUCT_EXCEPT_SELF_H_
#define ALGO_CC_ARRAYS_PRODUCT_EXCEPT_SELF_H_
#include <cstdint>
#include <vector>

namespace algo {

std::vector<int32_t> ProductExceptSelf(const std::vector<int32_t>& nums);

}  // namespace algo

#endif  // ALGO_CC_ARRAYS_PRODUCT_EXCEPT_SELF_H_
