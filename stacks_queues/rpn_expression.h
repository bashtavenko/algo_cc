// 8.2 Evaluate RPN expression
// Reversed polish (RPN or postfix) notation
// https://en.wikipedia.org/wiki/Reverse_Polish_notation
// 3 4 *
// Operators follow operands
// Go left to right, only need operands (values) stack
// Once have an operator, pop twice
#ifndef ALGO_CC_STACKS_QUEUES_RPN_EXPRESSION_H_
#define ALGO_CC_STACKS_QUEUES_RPN_EXPRESSION_H_
#include <cstdint>
#include "absl/strings/string_view.h"

namespace algo {

int32_t Evaluate(absl::string_view rpn_expression);

}  // namespace algo

#endif  // ALGO_CC_STACKS_QUEUES_RPN_EXPRESSION_H_
