#include "trie/trie.h"

namespace algo {

std::unique_ptr<Trie::Node>& Trie::Node::GetNext(const char8_t ch) {
  return data_[static_cast<uint8_t>(ch)];
}

bool Trie::Node::HasNext(const char8_t ch) const {
  return data_[static_cast<uint8_t>(ch)] != nullptr;
}

Trie::Trie() : root_(std::make_unique<Node>()) {}

bool Trie::Search(absl::string_view word) const {
  const Node* node = FindNode(word);
  return node != nullptr && node->is_end;
}

bool Trie::StartsWith(absl::string_view prefix) const {
  return FindNode(prefix) != nullptr;
}

void Trie::Insert(absl::string_view word) const {
  Node* node = root_.get();
  for (const char8_t ch : word) {
    if (!node->HasNext(ch)) {
      node->GetNext(ch) = std::make_unique<Node>();
    }
    node = node->GetNext(ch).get();
  }
  node->is_end = true;
}

Trie::Node* Trie::FindNode(absl::string_view s) const {
  Node* node = root_.get();
  for (const char8_t ch : s) {
    if (!node->HasNext(ch)) return nullptr;  // Prefix or word not found
    node = node->GetNext(ch).get();
  }
  return node;
}
}  // namespace algo
