#include <gflags/gflags.h>
#include <glog/logging.h>
#include "absl/strings/str_format.h"

// Basic int to string conversion
// int hour_12 = std::stoi("7");
// std::string str = std::to_string(7);
// std::isalnum()
//
// String find
// if (token.find('.') != std::string::npos) {...}
//
// Chop \t
// const int32_t level = token.find_first_not_of('\t');
// token = token.substr(level);  // Remove tabs

bool IsPalindrom(absl::string_view s) {
  size_t lo = 0;
  size_t hi = s.size() - 1;
  while (lo < hi) {
    if (s[lo] != s[hi]) return false;
    ++lo;
    --hi;
  }
  return true;
}

bool IsPalindrom2(absl::string_view s) {
  size_t lo = 0;
  size_t hi = s.size() - 1;
  while (lo < hi) {
    while (!std::isalnum(s[lo]) && lo < hi) ++lo;
    while (!std::isalnum(s[hi]) && lo < hi) --hi;
    if (std::tolower(s[lo++]) != std::tolower(s[hi--])) return false;
  }
  return true;
}

void MakeAllSubstrings(absl::string_view s) {
  for (size_t len = 1; len < s.size(); ++len) {
    for (int i = 0; i < s.length() - len; ++i) {
      LOG(INFO) << s.substr(i, len);
    }
  }
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);
  FLAGS_logtostderr = 1;

  LOG(INFO) << IsPalindrom("abccba");
  LOG(INFO) << IsPalindrom2("A man, a plan, a canal, Panama");

  std::string str = "Fine";
  str.pop_back();
  LOG(INFO) << absl::StreamFormat("pop_back(): %s", str);
  LOG(INFO) << absl::StreamFormat("Reverse: %s",
                                  std::string{str.rbegin(), str.rend()});

  MakeAllSubstrings("abba");
}