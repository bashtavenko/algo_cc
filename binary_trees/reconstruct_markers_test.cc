#include "binary_trees/reconstruct_markers.h"
#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <cstdint>
#include <vector>
#include "absl/types/optional.h"

namespace algo {
namespace {

TEST(Reconstruct, Works) {
  auto result = Reconstruct(
      std::vector<absl::optional<int32_t>>{1, 2, {}, {}, 3, {}, {}});
  EXPECT_THAT(result->data, 1);
}

}  // namespace
}  // namespace algo
