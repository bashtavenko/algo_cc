// 8.3 test a string on wll-formedness
#ifndef ALGO_CC_STACKS_QUEUES_WELL_FORMEDNESS_H_
#define ALGO_CC_STACKS_QUEUES_WELL_FORMEDNESS_H_

#include "absl/strings/string_view.h"

namespace algo {

bool IsWellFormed(absl::string_view s);

}  // namespace algo

#endif  // ALGO_CC_STACKS_QUEUES_WELL_FORMEDNESS_H_
