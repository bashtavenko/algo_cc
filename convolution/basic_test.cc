#include <cstdint>
#include <vector>
#include "gmock/gmock-matchers.h"
#include "gtest/gtest.h"

namespace algo {
namespace {
using ::testing::ElementsAreArray;

enum class Padding {
  // kValid - padding means that kernel fully overlaps the image.
  // No padding, smaller output.
  // Matlab 'valid' in conv2
  kValid,
  // kSame - padding to keep output size the same as input.
  kSame,
  // kFull - padding to allow kernel to overlap borders, larger output
  kFull
};

std::vector<std::vector<int32_t>> Conv2DRectangularValid(
    const std::vector<std::vector<int32_t>>& image,
    const std::vector<std::vector<int32_t>>& kernel) {
  const int image_size = image.size();
  const int kernel_size = kernel.size();
  const int output_rows = image_size - kernel_size + 1;
  const int output_cols = image_size - kernel_size + 1;

  std::vector<std::vector<int32_t>> output(
      output_rows, std::vector<int32_t>(output_cols, 0));
  for (int i = 0; i < output_rows; ++i) {
    for (int j = 0; j < output_cols; ++j) {
      int32_t sum = 0;
      for (int ki = 0; ki < kernel_size; ++ki) {
        for (int kj = 0; kj < kernel_size; ++kj) {
          sum += image[i + ki][j + kj] * kernel[ki][kj];
        }
      }
      output[i][j] = sum;
    }
  }

  return output;
}

std::vector<std::vector<int32_t>> Conv2D(
    const std::vector<std::vector<int32_t>>& image,
    const std::vector<std::vector<int32_t>>& kernel, Padding padding) {
  const int32_t image_rows = image.size();
  const int32_t image_cols = image[0].size();
  const int32_t kernel_rows = kernel.size();
  const int32_t kernel_cols = kernel[0].size();

  int32_t pad_top = 0;
  int32_t pad_bottom = 0;
  int32_t pad_left = 0;
  int32_t pad_right = 0;

  if (padding == Padding::kValid) {
    pad_top = pad_bottom = pad_left = pad_right = 0;
  } else if (padding == Padding::kFull) {
    pad_top = kernel_rows - 1;
    pad_bottom = kernel_rows - 1;
    pad_left = kernel_cols - 1;
    pad_right = kernel_cols - 1;
  } else if (padding == Padding::kSame) {
    pad_top = (kernel_rows - 1) / 2;
    pad_bottom = (kernel_rows - 1) - pad_top;
    pad_left = (kernel_cols - 1) / 2;
    pad_right = (kernel_cols - 1) - pad_left;
  }

  const int32_t padded_rows = image_rows + pad_top + pad_bottom;
  const int32_t padded_cols = image_cols + pad_left + pad_right;

  std::vector<std::vector<int32_t>> padded_image(
      padded_rows, std::vector<int32_t>(padded_cols, 0));
  for (int i = 0; i < image_rows; ++i) {
    for (int j = 0; j < image_cols; ++j) {
      padded_image[i + pad_top][j + pad_left] = image[i][j];
    }
  }

  const int32_t output_rows = padded_rows - kernel_rows + 1;
  const int32_t output_cols = padded_cols - kernel_cols + 1;

  std::vector<std::vector<int32_t>> output(
      output_rows, std::vector<int32_t>(output_cols, 0));

  for (int i = 0; i < output_rows; ++i) {
    for (int j = 0; j < output_cols; ++j) {
      int32_t sum = 0;
      for (int ki = 0; ki < kernel_rows; ++ki) {
        for (int kj = 0; kj < kernel_cols; ++kj) {
          sum += padded_image[i + ki][j + kj] * kernel[ki][kj];
        }
      }
      output[i][j] = sum;
    }
  }

  return output;
}

TEST(Conv2D, RegularWorks) {
  EXPECT_THAT(
      Conv2DRectangularValid(
          std::vector<std::vector<int32_t>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
          std::vector<std::vector<int32_t>>{{1, 1}, {1, 1}}),
      ElementsAreArray(std::vector<std::vector<int32_t>>{{12, 16}, {24, 28}}));
}

TEST(Conv2D, Regular_4_3_Works) {
  EXPECT_THAT(
      Conv2DRectangularValid(
          std::vector<std::vector<int32_t>>{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}},
          std::vector<std::vector<int32_t>>{{0, 1, 0}, {1, 1, 1}, {0, 1, 0}}),
      ElementsAreArray(std::vector<std::vector<int32_t>>{{5, 2}, {2, 2}}));
}

TEST(Conv2D, FullWorks) {
  EXPECT_THAT(
      Conv2D(std::vector<std::vector<int32_t>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
             std::vector<std::vector<int32_t>>{{1, 1}, {1, 1}}, Padding::kFull),
      ElementsAreArray(std::vector<std::vector<int32_t>>{
          {1, 3, 5, 3}, {5, 12, 16, 9}, {11, 24, 28, 15}, {7, 15, 17, 9}}));
}

TEST(Conv2D, SameWorks) {
  EXPECT_THAT(
      Conv2D(std::vector<std::vector<int32_t>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
             std::vector<std::vector<int32_t>>{{1, 1}, {1, 1}}, Padding::kSame),
      ElementsAreArray(std::vector<std::vector<int32_t>>{
          {12, 16, 9}, {24, 28, 15}, {15, 17, 9}}));
}

}  // namespace
}  // namespace algo