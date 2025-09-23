// Simple state machine
#ifndef ALGO_CC_STATE_MACHINE_H
#define ALGO_CC_STATE_MACHINE_H

#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

namespace algo {

// First is to set it up, then on every event invokes callable.
//  Idle  < -------      |
//   | request           |
//  Candidate  -- denied |
//   | approve
//  Engaged
//   | end_session
//  Terminated

class StateMachine {
 public:
  using Action = std::function<void()>;
  using TransitionKey = std::pair<std::string, std::string>;  // {state, event}
  struct PairHash {
    std::size_t operator()(const TransitionKey& k) const {
      return std::hash<std::string>()(k.first) ^
             std::hash<std::string>()(k.second);
    }
  };
  // Initialize state machine with initial state.
  explicit StateMachine(const std::string& initial_state);

  // One-time configuration to set up state, transition, events and action.
  void SetupTransition(const std::string& current_state,
                       const std::string& event, const std::string& next_state,
                       Action action = nullptr);

  // Given an event invoke the next state.
  void HandleEvent(const std::string& event);

  // Returns current state
  std::string State() const;

 private:
  std::string current_state_;
  // { "Idle request_engagement" : "Candidate func"}
  // { "Candidate approve" : "approve func"}
  // { "Candidate reject" : "idle func"}
  std::unordered_map<TransitionKey, std::pair<std::string, Action>, PairHash>
      transitions_;
};

}  // namespace algo

#endif  // ALGO_CC_STATE_MACHINE_H
