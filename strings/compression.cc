#include "strings/compression.h"
#include <string>

namespace algo {

// Input:  ["a","a","b","b","c","c","c"]
// Output: ["a","2","b","2","c","3"]
size_t Compress(std::vector<char8_t>& chars) {
  size_t write_index = 0;
  size_t read_index = 0;
  size_t n = chars.size();

  while (read_index < n) {
    char current_char = chars[read_index];
    size_t count = 0;

    // Count occurrences of current_char
    while (read_index < n && chars[read_index] == current_char) {
      ++read_index;
      ++count;
    }

    // Write the character since it needs to be moved
    chars[write_index++] = current_char;

    if (count > 1) {
      for (const char& c : std::to_string(count)) {
        chars[write_index++] = c;
      }
    }
  }

  return write_index;  // New length of the compressed array
}

}  // namespace algo