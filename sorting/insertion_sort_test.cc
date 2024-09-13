#include "sorting/insertion_sort.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>

TEST(SortInsertion, Works) {
  std::vector<int32_t> data{5, 2, 4, 6, 1, 3};
  std::vector<int32_t> want{1, 2, 3, 4, 5, 6};
  SortInsertion(data);
  EXPECT_THAT(data, want);
}