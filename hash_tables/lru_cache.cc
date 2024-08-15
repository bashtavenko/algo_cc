#include "hash_tables/lru_cache.h"
#include <list>
#include "absl/container/flat_hash_map.h"
#include "absl/types/optional.h"

namespace algo {

absl::optional<int32_t> LRUCache::Lookup(char8_t key) {
  auto it = table_.find(key);
  if (it == table_.end()) return {};

  // Have key. Re-add it on lookup, that's the trick.
  // if it was [a, b] and we looked up 'b', it will be [b, a]
  int32_t value = it->second.second;
  // Since key has just been accessed, move it to front.
  MoveToFront(key, it);
  return value;
}

void LRUCache::Insert(char8_t key, int32_t value) {
  auto it = table_.find(key);
  if (it != table_.end()) {
    MoveToFront(key, it);
  } else {
    if (table_.size() == capacity_) {
      table_.erase(lru_queue_.back());
      lru_queue_.pop_back();
    }
  }
  lru_queue_.emplace_front(key);
  table_[key] = {lru_queue_.begin(), value};
};

bool LRUCache::Erase(char8_t key) {
  auto it = table_.find(key);
  if (it == table_.end()) return false;
  table_.erase(it);
  return true;
}

void LRUCache::MoveToFront(char8_t key, const Table::iterator& it) {
  lru_queue_.erase(it->second.first);
  lru_queue_.emplace_front(key);
  it->second.first = lru_queue_.begin();
}

}  // namespace algo