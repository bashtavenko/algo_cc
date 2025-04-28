#include <memory>
#include "gflags/gflags.h"
#include "glog/logging.h"

class Map {};
class Pose {};
class Trajectory {};

// Classical plugin factory
class Planner {
 public:
  virtual ~Planner() = default;
  virtual Trajectory Plan(const Map&, const Pose&) = 0;
};

class AStarPlanner : public Planner {
 public:
  Trajectory Plan(const Map&, const Pose&) override;
};

class RRTPlanner : public Planner {
 public:
  Trajectory Plan(const Map&, const Pose&) override;
};

// This is static factory
// Pros: simple, compile-time safety
// Cons: recompile every time to add a new planner
// Alternative: registration system, run-time configurable
class PlannerFactory {
 public:
  static std::unique_ptr<Planner> Create(std::string_view name) {
    if (name == "AStar") return std::make_unique<AStarPlanner>();
    if (name == "RRT") return std::make_unique<RRTPlanner>();
    return nullptr;
  }
};

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  FLAGS_logtostderr = 1;

  // TODO: define all classes
  // std::unique_ptr<Planner> planner = PlannerFactory::Create("AStar");
}