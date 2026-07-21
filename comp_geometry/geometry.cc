#include "comp_geometry/geometry.h"
#include <set>

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

bool AnySegmentsIntersect(std::vector<Line>& segments) {
  // Given a line segment and x-coordindate, it returns y-value at that x
  auto y_at_sweep_x = [](const Line& l, int32_t x) {
    // no vertical segments assumed
    double t = static_cast<double>(x - l.p0.x) / static_cast<double>(l.p1.x - l.p0.x);
    return l.p0.y + t * static_cast<double>(l.p1.y - l.p0.y);
  };

  // Make sure p0 must is the left endpoint.
  for (auto& l : segments) {
    if (l.p1.x < l.p0.x) std::swap(l.p0, l.p1);
  }

  int32_t sweep_x = 0;
  auto cmp = [&](const Line* a, const Line* b) {
    double ya = y_at_sweep_x(*a, sweep_x);
    double yb = y_at_sweep_x(*b, sweep_x);
    if (ya != yb) return ya < yb;
    return a < b;  // stable tie-break, keeps strict weak ordering
  };
  std::set<const Line*, decltype(cmp)> status(cmp);

  enum class EventType { kLeft, kRight };
  struct Event {
    int32_t x, y;
    EventType type;
    const Line* seg;
  };

  std::vector<Event> events;
  events.reserve(segments.size() * 2);
  for (const auto& s : segments) {
    events.push_back({s.p0.x, s.p0.y, EventType::kLeft, &s});
    events.push_back({s.p1.x, s.p1.y, EventType::kRight, &s});
  }
  std::ranges::sort(events, [](const Event& a, const Event& b) {
    if (a.x != b.x) return a.x < b.x;
    if (a.type != b.type) return a.type == EventType::kLeft;  // left before right on ties
    return a.y < b.y;
  });

  for (const auto& e : events) {
    sweep_x = e.x;
    if (e.type == EventType::kLeft) {
      auto [it, ok] = status.insert(e.seg);
      auto above = std::next(it);
      auto below = (it == status.begin()) ? status.end() : std::prev(it);
      if (above != status.end() &&
          SegmentIntersect(e.seg->p0, e.seg->p1, (*above)->p0, (*above)->p1))
        return true;
      if (below != status.end() &&
          SegmentIntersect(e.seg->p0, e.seg->p1, (*below)->p0, (*below)->p1))
        return true;
    } else {
      auto it = status.find(e.seg);
      auto above = std::next(it);
      auto below = (it == status.begin()) ? status.end() : std::prev(it);
      if (above != status.end() && below != status.end() &&
          SegmentIntersect((*above)->p0, (*above)->p1, (*below)->p0, (*below)->p1))
        return true;
      status.erase(it);
    }
  }
  return false;
}

}  // namespace geometry