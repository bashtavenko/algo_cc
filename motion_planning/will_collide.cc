#include <cmath>
#include "motion_planning/motion_planning.h"

namespace algo {

bool WillCollide(const Vehicle& vehicle,
                 const std::vector<Obstacle>& obstacles) {
  auto get_vehicle_corners = [&](const Vehicle& vehicle) {
    std::vector<Point2D> corners(4);

    // Half dimensions
    const double half_length = vehicle.length / 2.0;
    const double half_width = vehicle.width / 2.0;
    // Pre-calculate sin and cos of heading
    const double cos_heading = std::cos(vehicle.heading);
    const double sin_heading = std::sin(vehicle.heading);
    // Calculate four corners (relative to center, then rotated by heading)
    corners[0].x = vehicle.position.x +
                   (half_length * cos_heading - half_width * sin_heading);
    corners[0].y = vehicle.position.y +
                   (half_length * sin_heading + half_width * cos_heading);
    corners[1].x = vehicle.position.x +
                   (half_length * cos_heading + half_width * sin_heading);
    corners[1].y = vehicle.position.y +
                   (half_length * sin_heading - half_width * cos_heading);
    corners[2].x = vehicle.position.x +
                   (-half_length * cos_heading + half_width * sin_heading);
    corners[2].y = vehicle.position.y +
                   (-half_length * sin_heading - half_width * cos_heading);
    corners[3].x = vehicle.position.x +
                   (-half_length * cos_heading - half_width * sin_heading);
    corners[3].y = vehicle.position.y +
                   (-half_length * sin_heading + half_width * cos_heading);
    return corners;
  };

  // Get min and max for a polygon
  auto project_polygon = [&](const std::vector<Point2D>& polygon,
                             const Point2D& axis, double& min, double& max) {
    // Project the first point
    double dot = polygon[0].x * axis.x + polygon[0].y * axis.y;
    min = max = dot;

    // Project the rest of the points
    for (size_t i = 1; i < polygon.size(); ++i) {
      dot = polygon[i].x * axis.x + polygon[i].y * axis.y;
      min = std::min(min, dot);
      max = std::max(max, dot);
    }
  };

  auto polygons_separated = [&](const std::vector<Point2D>& polygon_a,
                                const std::vector<Point2D>& polygon_b,
                                const Point2D& axis) {
    double min_a;
    double max_a;
    double min_b;
    double max_b;
    project_polygon(polygon_a, axis, min_a, max_a);
    project_polygon(polygon_b, axis, min_b, max_b);

    // Check for separation
    return max_a < min_b || max_b < min_a;
  };

  auto polygon_intersect = [&](const std::vector<Point2D>& polygon_a,
                               const std::vector<Point2D>& polygon_b) {
    // Implement Separating Axis Theorem here
    // Check all axes from polygon A
    for (size_t i = 0; i < polygon_a.size(); ++i) {
      size_t j = (i + 1) % polygon_a.size();
      Point2D edge = {polygon_a[j].x - polygon_a[i].x,
                      polygon_a[j].y - polygon_a[i].y};
      Point2D normal = {-edge.y, edge.x};  // Perpendicular
      if (polygons_separated(polygon_a, polygon_b, normal)) return false;
    }
    // Check all axes from polygon B
    for (size_t i = 0; i < polygon_b.size(); ++i) {
      size_t j = (i + 1) % polygon_b.size();
      Point2D edge = {polygon_b[j].x - polygon_b[i].x,
                      polygon_b[j].y - polygon_b[i].y};
      Point2D normal = {-edge.y, edge.x};  // Perpendicular

      if (polygons_separated(polygon_a, polygon_b, normal)) return false;
    }

    // No separating axis found, polygons intersect
    return true;
  };

  // Generate vehicle corners
  std::vector<Point2D> vehicleCorners = get_vehicle_corners(vehicle);

  // Check collision with each obstacle
  for (const auto& obstacle : obstacles) {
    if (polygon_intersect(vehicleCorners, obstacle.vertices)) {
      return true;
    }
  }
  return false;
}

}  // namespace algo