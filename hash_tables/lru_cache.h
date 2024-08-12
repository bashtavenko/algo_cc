// 12.3 LRU cache
// Least Recently Used cache. Discard  least recently used items first.
// We need ordered hash table.
// Two approaches:
// 1. Use cache of size n. Grow it until it is 2n and then find median age
//    of items and purge them.
// 2. Maintain a separate queue of keys. Hash table stores location in the
//    queue.

#ifndef ALGO_CC_HASH_TABLES_LRU_CACHE_H_
#define ALGO_CC_HASH_TABLES_LRU_CACHE_H_

#include <list>
#include "absl/container/flat_hash_map.h"
#include "absl/types/optional.h"

namespace algo {

class LRUCache {
 public:
  LRUCache(size_t capacity) : capacity_(capacity) {}

  absl::optional<int32_t> Lookup(char8_t key);
  void Insert(char8_t key, int32_t value);

  bool Erase(char8_t key);

 private:
  // Main block - double-linked list.
  std::list<char8_t> lru_queue_;

  // Second main block - hash table
  // 'a' -> [('a', 1), ('b, 2), ('c', 3)]
  // 'b' -> ...
  using Table =
      absl::flat_hash_map<char8_t,
                          std::pair<std::list<char8_t>::iterator, int32_t>>;
  size_t capacity_;
  Table table_;

  void MoveToFront(char8_t key, const Table::iterator& it);
};

}  // namespace algo

#endif  // ALGO_CC_HASH_TABLES_LRU_CACHE_H_
