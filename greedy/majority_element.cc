#include "greedy/majority_element.h"
#include <string>
#include <vector>

namespace algo {

std::string MajoritySearch(
    std::vector<std::string>::const_iterator input_stream_begin,
    const std::vector<std::string>::const_iterator input_stream_end) {
  std::string candidate;
  int32_t candidate_count = 0;
  while (input_stream_begin != input_stream_end) {
    std::string it = *input_stream_begin++;
    if (candidate_count == 0) {
      candidate = it;
      candidate_count = 1;
    } else if (candidate == it) {
      ++candidate_count;
    } else {
      --candidate_count;
    }
  }
  return candidate;
}

}  // namespace algo