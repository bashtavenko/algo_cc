#ifndef ALGO_CC_GEOMETRY_H
#define ALGO_CC_GEOMETRY_H
#include <cstdint>
#include <iosfwd>
#include "absl/strings/str_format.h"

namespace geometry {

// Point members and some operations
struct Point {
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

  // AbslStringify provides ostream operator and type deduction with %v
  // without duplication in ostream.
  // https://abseil.io/tips/215
  template <typename Sink>
  friend void AbslStringify(Sink& sink, const Point& point) {
    absl::Format(&sink, "(%v, %v)", point.x, point.y);
  }
};

// Determines whether two-line segments intersect.
// Line segment
struct Line {
  Point p0;
  Point p1;

  Line(const Point& p0, const Point& p1) : p0(p0), p1(p1) {};
  bool operator==(const Line& line) const {
    return line.p1 == p1 && line.p0 == p0;
  }

  template <typename Sink>
  friend void AbslStringify(Sink& sink, const Line& line) {
    absl::Format(&sink, "(%v -> %v)", line.p0, line.p1);
  }
};

// Determines whether a pair of segments intersects.
bool SegmentIntersect(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

// Determines whether any pair of segments intersect.
// Assuming that there are no vertical line segments and no three or more
// input segments intersect at a single point.
bool AnySegmentsIntersect(std::vector<Line>& segments);

} // namespace geometry


#endif //ALGO_CC_GEOMETRY_H