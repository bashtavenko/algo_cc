#include "motion_planning/state_machine.h"
#include <functional>
#include "absl/strings/str_format.h"
#include "glog/logging.h"

namespace algo {

StateMachine::StateMachine(const std::string& initial_state)
    : current_state_(initial_state) {}

void StateMachine::SetupTransition(const std::string& current_state,
                                   const std::string& event,
                                   const std::string& next_state,
                                   Action action) {
  transitions_[{current_state, event}] = {next_state, action};
}

void StateMachine::HandleEvent(const std::string& event) {
  const auto it = transitions_.find({current_state_, event});
  if (it == transitions_.end()) {
    LOG(INFO) << absl::StreamFormat(
        "No transition defined for state %s on event %s", current_state_,
        event);
  }
  const auto& [next_state, action] = it->second;
  if (action) action();
  LOG(INFO) << absl::StrFormat("Transition: %s -> %s on event %s",
                               current_state_, next_state, event);
  current_state_ = next_state;
}

std::string StateMachine::State() const { return current_state_; }

}  // namespace algo
