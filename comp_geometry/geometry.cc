#include "comp_geometry/geometry.h"

namespace geometry {

bool SegmentIntersect(const Point& p1, const Point& p2, const Point& p3,
                      const Point& p4) {
  auto on_segment = [](const Point& i, const Point& j, const Point& k) {
    if (std::min(i.x, j.x) <= k.x && k.x <= std::max(i.x, j.x) &&
        std::min(i.y, j.y) <= k.y && k.y <= std::max(i.y, j.y)) {
      return true;
    }
    return false;
  };
  const int32_t d1 = p3.CrossProduct(p4, p1);
  const int32_t d2 = p3.CrossProduct(p4, p2);
  const int32_t d3 = p1.CrossProduct(p2, p3);
  const int32_t d4 = p1.CrossProduct(p2, p4);

  if ((d1 > 0 && d2 < 0 || d1 < 0 && d2 > 0) &&
      (d3 > 0 && d4 < 0 || d3 < 0 && d4 > 0)) {
    return true;
  } else if (d1 == 0 && on_segment(p3, p4, p1)) {
    return true;
  } else if (d2 == 0 && on_segment(p3, p4, p2)) {
    return true;
  } else if (d3 == 0 && on_segment(p1, p2, p3)) {
    return true;
  } else if (d4 == 0 && on_segment(p1, p2, p4)) {
    return true;
  } else {
    return false;
  }
}

}  // namespace geometry