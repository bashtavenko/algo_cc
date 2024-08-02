#include "stacks_queues/rpn_expression.h"
#include <cstdint>
#include <functional>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include "absl/strings/string_view.h"

namespace algo {

int32_t Evaluate(absl::string_view rpn_expression) {
  std::stack<int32_t> values;
  constexpr char kDelimiter = ' ';
  std::string token;

  std::unordered_map<std::string, std::function<int32_t(int32_t, int32_t)>>
      operators = {
          {"+", [](int32_t x, int32_t y) { return x + y; }},
          {"-", [](int32_t x, int32_t y) { return x - y; }},
          {"*", [](int32_t x, int32_t y) { return x * y; }},
          {"/", [](int32_t x, int32_t y) { return x / y; }},
      };

  // std::stringstream automatically handles type conversion
  // int vs char. It also skips whitespaces
  std::stringstream ss{std::string(rpn_expression)};

  while (std::getline(ss, token, kDelimiter)) {
    if (operators.find(token) != operators.end()) {
      const int32_t y = values.top();
      values.pop();
      const int32_t x = values.top();
      values.pop();
      values.emplace(operators[token](x, y));
    } else {
      // Token is a number
      values.emplace(std::stoi(token));
    }
  }
  return values.top();
}
}  // namespace algo
