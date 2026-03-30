// 12.3 LRU cache
//  Eviction policy - Least Recently Used cache. Discard least recently used
//  items first.
// We need ordered hash table.
// Two approaches:
// 1. Use cache of size n. Grow it until it is 2n and then find the median age
//    of items and purge them.
// 2. Maintain a separate queue of keys. Hash table stores location in the
//    queue.
//    Key idea - on lookup move the new value to front
//    If it was [a, b] and we looked up 'b', it will be [b, a]
//    On insert pop extra if needed
//    Design
//    1. linked list (need to re-arrange position)
//    2. hash map which points to the linked list

#ifndef ALGO_CC_HASH_TABLES_LRU_CACHE_H_
#define ALGO_CC_HASH_TABLES_LRU_CACHE_H_

#include <list>
#include "absl/container/flat_hash_map.h"
#include <mutex>

namespace algo {

class LRUCache {
 public:
  LRUCache(size_t capacity) : capacity_(capacity) {}

  absl::optional<int32_t> Lookup(char8_t key);
  void Insert(char8_t key, int32_t value);

  bool Erase(char8_t key);

 private:
  // Main block - double-linked list of values
  // a<->b<->c<->d
  std::list<char8_t> lru_queue_;

  // The second main block - hash table
  // It has a regular key and value plus linkage to lru_queue
  // For each key it has not only the value but where it came from.
  // {'a': 1, 'b': 2}
  // 'a' -> (100, 1)   'a' - key; 1 - value; 100 - iterator
  // 'b' -> (102, 2)
  //  We cannot change the order of the hash map, therefore, we need
  //  to keep order in the linked list.
  using Table =
      std::unordered_map<char8_t,
                          std::pair<std::list<char8_t>::iterator, int32_t>>;
  size_t capacity_;
  Table table_;

  // Moves key lru_cache to front. Updates key in table_
  void MoveToFront(char8_t key, const Table::iterator& it);

  mutable std::mutex mutex_;
};

}  // namespace algo

#endif  // ALGO_CC_HASH_TABLES_LRU_CACHE_H_
