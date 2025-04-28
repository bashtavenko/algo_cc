#include "motion_planning/motion_planning.h"
#include <cmath>
#include <queue>

namespace algo {

double MinDistance(const Point2D& point, const LineSegment& segment) {
  double dx = segment.p2.x - segment.p1.x;
  double dy = segment.p2.y - segment.p1.y;
  const double length_squared = dx * dx + dy * dy;
  if (length_squared == 0.0) {
    // p1 == p2 case: the segment is just a point
    dx = point.x - segment.p1.x;
    dy = point.y - segment.p1.y;
    return std::sqrt(dx * dx + dy * dy);
  }

  // Find dot product from point to both line segments divided by length
  // The fraction
  // How far along the segment the perpendicular projection of the point
  // lands normalized so the entire segment is from 0 to 1.
  // (p - p1) dot (p2 - p1) / length_squared
  // projection parameter t
  // t = 0 means right at p1. t = 1 means right at p2. In between means in
  // between.
  double t = ((point.x - segment.p1.x) * dx + (point.y - segment.p1.y) * dy) /
             length_squared;
  // clamp t from [0,1]
  t = std::max(0.0, std::min(1.0, t));
  const double proj_x = segment.p1.x + t * dx;
  const double proj_y = segment.p1.y + t * dy;

  dx = point.x - proj_x;
  dy = point.y - proj_y;

  return std::sqrt(dx * dx + dy * dy);
}

std::vector<Point2D> FindKClosestPoints(const std::vector<Point2D>& points,
                                        const Point2D& reference, size_t k) {
  auto comparator = [&reference](const Point2D& a, const Point2D& b) {
    const double dx1 = a.x - reference.x;
    const double dy1 = a.y - reference.y;
    const double dx2 = b.x - reference.x;
    const double dy2 = b.y - reference.y;

    return (dx1 * dx1 + dy1 * dy1) < (dx2 * dx2 + dy2 * dy2);
  };

  std::priority_queue<Point2D, std::vector<Point2D>, decltype(comparator)>
      max_heap(comparator);
  for (const Point2D& point : points) {
    max_heap.emplace(point);
    if (max_heap.size() > k) {
      max_heap.pop();
    }
  }
  std::vector<Point2D> result;
  while (!max_heap.empty()) {
    result.emplace_back(max_heap.top());
    max_heap.pop();
  }

  return {result.rbegin(), result.rend()};
}

bool IsPointInConvexPolygon(const Point2D& point,
                            const std::vector<Point2D>& polygon_vertices) {
  if (polygon_vertices.size() < 3) {
    return false;  // Not a polygon
  }
  // Function to determine which side of a line a point is on
  // Cross product produces a vector perpendicular to the give vectors.
  // The sign of cross product tells the relative position of the point
  // with respect to edge. If all cross products have the same sign,
  // the point P is inside the convex hall. If any cross product has a
  // different sign, the point is outside the convex polygon.
  auto cross_product = [](const Point2D& p1, const Point2D& p2,
                          const Point2D& p) {
    return (p2.x - p1.x) * (p.y - p1.y) - (p2.y - p1.y) * (p.x - p1.x);
  };
  // Assume vertices are given in order (clockwise or counterclockwise)
  // Get the sign of the first edge to determine which way we're going
  const double first_cross =
      cross_product(polygon_vertices[0], polygon_vertices[1], point);
  const bool sign = first_cross > 0;
  // Check that point is on the same side of all edges
  for (size_t i = 1; i < polygon_vertices.size(); ++i) {
    const Point2D& current = polygon_vertices[i];
    const Point2D& next = polygon_vertices[(i + 1) % polygon_vertices.size()];
    const double cross = cross_product(current, next, point);
    // If sign changes or point is on edge (cross == 0), point is outside or on
    // boundary
    if ((cross > 0) != sign && cross != 0) {
      return false;
    }
  }
  return true;
}

TrajectoryPoint Interpolate(const TrajectoryPoint& p1,
                            const TrajectoryPoint& p2, double time) {
  // Calculate interpolation factor (between 0 and 1)
  double alpha = (time - p1.time) / (p2.time - p1.time);
  // Clamp alpha to [0,1] if necessary
  alpha = std::max(0.0, std::min(1.0, alpha));
  // Create interpolated point
  TrajectoryPoint result;
  result.time = time;
  result.position.x = p1.position.x + alpha * (p2.position.x - p1.position.x);
  result.position.y = p1.position.y + alpha * (p2.position.y - p1.position.y);

  return result;
}

}  // namespace algo