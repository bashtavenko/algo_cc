#include "strings/reverse_words.h"
#include <algorithm>
#include <string>

namespace algo {

void ReverseWords(std::string* s) {
  std::reverse(s->begin(), s->end());

  size_t start = 0;
  size_t end;
  // string::npos - largest possible value for string
  while ((end = s->find(" ", start)) != std::string::npos) {
    std::reverse(s->begin() + start, s->begin() + end);
    start = end + 1;
  }
  // Reverse words
  std::reverse(s->begin() + start, s->end());
}
}  // namespace algo
