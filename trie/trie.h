// Basic trie
//
#ifndef TRIE_H
#define TRIE_H

#include <memory>
#include <string>
#include "absl/strings/string_view.h"

namespace algo {
class Trie {
  static constexpr int32_t R = 256;
  class Node {
   public:
    bool is_end = false;  // Mark end of word for search
    std::unique_ptr<Node>& GetNext(char8_t ch);
    bool HasNext(char8_t ch) const;

   private:
    std::unique_ptr<Node> data_[R];
  };

 public:
  Trie();
  void Insert(absl::string_view word) const;
  bool Search(absl::string_view word) const;
  bool StartsWith(absl::string_view prefix) const;

 private:
  Node* FindNode(absl::string_view s) const;
  std::unique_ptr<Node> root_;
};
}  // namespace algo

#endif  // TRIE_H
