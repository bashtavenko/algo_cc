#include "stacks_queues/longest_path.h"
#include <sstream>
#include <stack>

namespace algo {

// dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext
int32_t LongestPath(absl::string_view path) {
  std::stack<int32_t> stack;
  stack.push(0);  // Base level with no prefix path
  std::string token;
  constexpr char kDelimiter = '\n';
  std::stringstream ss{std::string(path)};
  int32_t max_length = 0;

  while (std::getline(ss, token, kDelimiter)) {
    // Find level by counting tabs
    const int32_t level = token.find_first_not_of('\t');
    token = token.substr(level);  // Remove tabs

    // Adjust stack to match the current level
    while (stack.size() > level + 1) {
      stack.pop();
    }

    int32_t current_length = stack.top() + token.size() + 1;
    stack.push(current_length);

    // Check if it's a file
    if (token.find('.') != std::string::npos) {
      max_length = std::max(max_length,
                            current_length - 1);  // -1 to exclude trailing '/'
    }
  }
  return max_length;
}

}  // namespace algo