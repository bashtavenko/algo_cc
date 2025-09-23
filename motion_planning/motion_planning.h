#ifndef HOME_S15O_ALGO_CC_MOTION_PLANNING_H_
#define HOME_S15O_ALGO_CC_MOTION_PLANNING_H_
#include <cmath>
#include <cstdint>
#include <ostream>
#include <queue>
#include <vector>

namespace algo {

struct Point2D {
  double x;
  double y;

  // These are for unit testing
  bool operator==(const Point2D& rhs) const { return x == rhs.x && y == rhs.y; }

  friend std::ostream& operator<<(std::ostream& os, const Point2D& p) {
    os << "x:" << p.x << ", y:" << p.y;
    return os;
  }
};

struct Vehicle {
  Point2D position;
  double heading;
  double length;
  double width;
};

struct LineSegment {
  Point2D p1;
  Point2D p2;
};

struct TrajectoryPoint {
  Point2D position;
  double time;

  bool operator==(const TrajectoryPoint& rhs) const {
    return position.x == rhs.position.x && position.y == rhs.position.y &&
           time == rhs.time;
  }

  friend std::ostream& operator<<(std::ostream& os, const TrajectoryPoint& p) {
    os << "position:" << p.position.x << ", " << p.position.y << ", " << p.time;
    return os;
  }
};

// Convex polygon
struct Obstacle {
  std::vector<Point2D> vertices;
};

// RA topics
struct AssistProposal {
  std::string id;
  std::string type;  // "waypoint" or "stop"
  double x;
  double y;
  double speed;
};

class SafetyFilter {
 public:
  bool Validate(const AssistProposal& p);
};

class RemoteAssistModule {
 public:
  void RequestEngagement();
  void ReceiveProposal(const AssistProposal& p);
  void ProcessProposals();
  void EndSession();

 private:
  bool engaged_ = false;
  std::queue<AssistProposal> inbox_;
  SafetyFilter filter_;
};

bool WillCollide(const Vehicle& vehicle,
                 const std::vector<Obstacle>& obstacles);

double MinDistance(const Point2D& point, const LineSegment& segment);

std::vector<Point2D> FindKClosestPoints(const std::vector<Point2D>& points,
                                        const Point2D& reference, size_t k);

// Assume that polygon vertices form a convex polygon and the vertices
// are given in order (clockwise or counterclockwise).
bool IsPointInConvexPolygon(const Point2D& point,
                            const std::vector<Point2D>& polygon_vertices);

TrajectoryPoint Interpolate(const TrajectoryPoint& p1,
                            const TrajectoryPoint& p2, double time);

}  // namespace algo

#endif  // HOME_S15O_ALGO_CC_MOTION_PLANNING_H_
