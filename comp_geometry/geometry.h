#ifndef ALGO_CC_GEOMETRY_H
#define ALGO_CC_GEOMETRY_H
#include <cstdint>
#include <iosfwd>
#include "absl/strings/str_format.h"

namespace geometry {
// Point members and some operations
struct Point {
  Point() = default;
  Point(int32_t x, int32_t y) : x(x), y(y) {}

  int32_t x;
  int32_t y;

  bool operator==(const Point& other) const {
    return x == other.x && y == other.y;
  }

  // Computes the cross-product of the given point.
  // Returns positive if clockwise, negative if counterclockwise.
  // Returns 0 if co-linear.
  // Example
  //            p2
  //    p1
  //
  //            p0
  //   Clockwise, positive value
  //            p2
  //                    p1
  //
  //            p0
  //   Counterclockwise, negative value
  //            p2
  //            p1
  //            p0
  //  Co-linear, zero
  int32_t CrossProduct(const Point& point1, const Point& point2) const {
    return (point1.x - x) * (point2.y - y) - (point2.x - x) * (
             point1.y - y);
  }

  template <typename Sink>
  friend void AbslStringify(Sink& sink, const Point& point) {
    absl::Format(&sink, "x: %v y: %v", point.x, point.y);
  }

  friend std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << absl::StreamFormat("x: %i  y: %i)", point.x, point.y);
    return os;
  }
};

// Determines whether two-line segments intersect.
bool SegmentIntersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

} // namespace geometry


#endif //ALGO_CC_GEOMETRY_H