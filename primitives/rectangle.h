#ifndef ALGO_CC_PRIMITIVES_RECTANGLE_H_
#define ALGO_CC_PRIMITIVES_RECTANGLE_H_

#include <cstdint>
#include "absl/strings/str_format.h"
#include "absl/types/optional.h"

namespace algo {

struct Rectangle {
  int32_t x;
  int32_t y;
  int32_t width;
  int32_t height;

  absl::optional<Rectangle> IsIntersect(const Rectangle& other) {
    if (!IsIntersectCheck(other)) return {};

    return Rectangle{
        .x = std::max(x, other.x),
        .y = std::max(y, other.y),
        .width =
            std::min(x + width, other.x + other.width) - std::max(x, other.x),
        .height =
            std::min(y + height, other.y + other.height) - std::max(y, other.y),
    };
  }

  bool operator==(const Rectangle& other) const {
    return (x == other.x && y == other.y && width == other.width &&
            height == other.height);
  }

  template <typename Sink>
  friend void AbslStringify(Sink& sink, const Rectangle& r) {
    absl::Format(&sink, "(x = %i, y = %i, width = %i, height = %i)", r.x, r.y,
                 r.width, r.height);
  }

  friend std::ostream& operator<<(std::ostream& os, const Rectangle& r) {
    os << absl::StreamFormat("%v", r);
    return os;
  }

 private:
  bool IsIntersectCheck(const Rectangle& other) const {
    return x <= other.x + other.width && x + width >= other.x &&
           y <= other.y + other.height && y + height > other.y;
  }
};

#endif  // ALGO_CC_PRIMITIVES_RECTANGLE_H_
}  // namespace algo