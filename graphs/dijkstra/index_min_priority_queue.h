// Basic indexed minimum priority queue.
#ifndef ALGO_CC_GRAPHS_DIJKSTRA_INDEX_MIN_PRIORITY_QUEUE_H_
#define ALGO_CC_GRAPHS_DIJKSTRA_INDEX_MIN_PRIORITY_QUEUE_H_

#include <cstdint>
#include <vector>
#include "absl/types/optional.h"

namespace algo {
template <typename T>
class IndexMinPriorityQueue {
 public:
  explicit IndexMinPriorityQueue(int32_t max_n);

  void Insert(int32_t k, T item);
  void Change(int32_t k, T item);
  bool Contains(int32_t k) const;
  void Delete(int32_t k);
  absl::optional<T> Min() const;
  absl::optional<int32_t> MinIndex() const;
  int32_t DelMin();  // It used a lot in Dijkstra's
  bool Empty() const;
  int32_t Size() const;

 private:
  void Swim(int32_t i);
  void Sink(int32_t i);
  void Exchange(int32_t i, int32_t j);
  bool Greater(int32_t i, int32_t j) const;

  int32_t max_n_;
  int32_t n_;
  std::vector<int32_t> pq_;  // binary heap using 1-based indexing
  std::vector<int32_t> qp_;  // inverse: qp[pq[i]] = pq[qp[i]] = i
  std::vector<T> keys_;      // items with priorities
};

}  // namespace algo

#endif  // ALGO_CC_GRAPHS_DIJKSTRA_INDEX_MIN_PRIORITY_QUEUE_H_
