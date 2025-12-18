#include <cstdint>
#include <numeric>
#include <vector>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace algo
{
  namespace
  {
    using ::testing::DoubleNear;
    constexpr float kMaxAbsError = 1e-5;

    // You are given an integer array nums consisting of n elements, and an integer
    // k.

    // Find a contiguous subarray whose length is equal to k that has the maximum
    // average value and return this value.Any answer with a calculation error
    // less than 10-5 will be accepted.
    //
    // [1, 12, -5, -6, 50, 3]
    // // 12.75
    double MaxAverageSubArrayRecalc(const std::vector<int32_t>& nums, int32_t k)
    {
      // min() - smallest positive value
      // lowest() - most negative value
      auto max_avg = std::numeric_limits<int32_t>::lowest();
      for (int32_t i = 0; i <= static_cast<int32_t>(nums.size()) - k; ++i)
      {
        max_avg = std::max(
          max_avg, std::accumulate(nums.begin() + i, nums.begin() + i + k, 0));
      }
      return static_cast<double>(max_avg) / k;
    }

    double MaxAverageSubArray(const std::vector<int32_t>& nums, int32_t k)
    {
      // Calculate a sum of the first window
      double window_sum = 0;
      for (int i = 0; i < k; ++i)
      {
        window_sum += nums[i];
      }
      double max_sum = window_sum;

      // Slide the window and update maxSum
      for (int i = k; i < static_cast<int32_t>(nums.size()); ++i)
      {
        window_sum = window_sum - nums[i - k] + nums[i];
        max_sum = std::max(max_sum, window_sum);
      }

      // Return the maximum average
      return max_sum / k;
    }

    TEST(MaxAverageSubarray, WorksRecalc)
    {
      EXPECT_THAT(
        MaxAverageSubArrayRecalc(std::vector<int32_t>{1, 12, -5, -6, 50, 3}, 4),
        DoubleNear(12.75, kMaxAbsError));
    }

    TEST(MaxAverageSubarray, Works)
    {
      EXPECT_THAT(MaxAverageSubArray(std::vector<int32_t>{1, 12, -5, -6, 50, 3}, 4),
                  DoubleNear(12.75, kMaxAbsError));
    }

    TEST(MaxAverageSubarray, Edge)
    {
      EXPECT_THAT(MaxAverageSubArray(std::vector<int32_t>{-1}, 1),
                  DoubleNear(-1, kMaxAbsError));
    }
  } // namespace
} // namespace algo
