#include <gflags/gflags.h>
#include <glog/logging.h>
#include "absl/strings/str_format.h"

bool IsPalindrom(absl::string_view s) {
  for (int32_t i = 0, j = s.size() - 1; i < j; ++i, --j) {
    if (s[i] != s[j]) return false;
  }
  return true;
}

bool IsPalindrom2(absl::string_view s) {
  size_t i = 0;
  size_t j = s.size();
  while (i < j) {
    while (!std::isalnum(s[i]) && i < j) ++i;
    while (!std::isalnum(s[j]) && i < j) --j;
    if (std::tolower(s[i++]) != std::tolower(s[j--])) return false;
  }
  return true;
}

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, /*remove_flags=*/true);

  LOG(INFO) << IsPalindrom("abccba");
  LOG(INFO) << IsPalindrom2("A man, a plan, a canal, Panama");

  std::string str = "Fine";
  str.pop_back();
  LOG(INFO) << absl::StreamFormat("pop_back(): %s", str);
  LOG(INFO) << absl::StreamFormat("Reverse: %s",
                                  std::string{str.rbegin(), str.rend()});
}