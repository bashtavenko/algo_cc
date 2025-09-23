#include "gflags/gflags.h"
#include "glog/logging.h"
#include "motion_planning/state_machine.h"

int main(int argc, char** argv) {
  using algo::StateMachine;

  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);
  FLAGS_logtostderr = true;

  StateMachine sm("Idle");

  sm.SetupTransition("Idle", "request_engagement", "Candidate",
                     []() { LOG(INFO) << "Evaluating conditions..."; });

  sm.SetupTransition("Candidate", "approve", "Engaged",
                     []() { LOG(INFO) << "Remote Assist engaged."; });

  sm.SetupTransition("Candidate", "reject", "Idle",
                     []() { LOG(INFO) << "Engagement denied"; });

  sm.SetupTransition("Engaged", "end_session", "Terminated",
                     []() { LOG(INFO) << "Session ended."; });

  // Simulate events
  sm.HandleEvent("request_engagement");
  sm.HandleEvent("approve");
  sm.HandleEvent("end_session");

  return EXIT_SUCCESS;
}
