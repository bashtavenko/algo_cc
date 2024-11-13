#include "graphs/dijkstra/index_min_priority_queue.h"
#include <glog/logging.h>

namespace algo {

template <typename T>
IndexMinPriorityQueue<T>::IndexMinPriorityQueue(int32_t max_n)
    : max_n_(max_n),
      n_(0),
      pq_(max_n + 1, -1),
      qp_(max_n + 1, -1),
      keys_(max_n + 1) {}

template <typename T>
void IndexMinPriorityQueue<T>::Insert(int32_t k, T item) {
  if (Contains(k)) LOG(FATAL) << "Index already exists.";  // Crash is ok
  qp_[k] = ++n_;
  pq_[n_] = k;
  keys_[k] = item;
  Swim(n_);
}

template <typename T>
void IndexMinPriorityQueue<T>::Change(int32_t k, T item) {
  if (!Contains(k))
    LOG(FATAL) << "Index is not in the priority queue";  // Crash is ok
  keys_[k] = item;
  Swim(qp_[k]);
  Sink(qp_[k]);
}

template <typename T>
bool IndexMinPriorityQueue<T>::Contains(int32_t k) const {
  return qp_[k] != -1;
}

template <typename T>
void IndexMinPriorityQueue<T>::Delete(int32_t k) {
  if (!Contains(k)) LOG(FATAL) << "Index is not in the priority queue";
  int i = qp_[k];
  Exchange(i, n_--);
  Swim(i);
  Sink(i);
  qp_[k] = -1;
  pq_[n_ + 1] = -1;
}

template <typename T>
absl::optional<T> IndexMinPriorityQueue<T>::Min() const {
  if (Empty()) return std::nullopt;
  return keys_[pq_[1]];
}

template <typename T>
absl::optional<int32_t> IndexMinPriorityQueue<T>::MinIndex() const {
  if (Empty()) return std::nullopt;
  return pq_[1];
}

template <typename T>
int32_t IndexMinPriorityQueue<T>::DelMin() {
  CHECK(!Empty());
  int min_index = pq_[1];
  Exchange(1, n_--);
  Sink(1);
  qp_[min_index] = -1;
  pq_[n_ + 1] = -1;
  return min_index;
}

template <typename T>
bool IndexMinPriorityQueue<T>::Empty() const {
  return n_ == 0;
}

template <typename T>
int32_t IndexMinPriorityQueue<T>::Size() const {
  return n_;
}

template <typename T>
void IndexMinPriorityQueue<T>::Swim(int32_t i) {
  while (i > 1 && Greater(i / 2, i)) {
    Exchange(i, i / 2);
    i /= 2;
  }
}

template <typename T>
void IndexMinPriorityQueue<T>::Sink(int32_t i) {
  while (2 * i <= n_) {
    int j = 2 * i;
    if (j < n_ && Greater(j, j + 1)) ++j;
    if (!Greater(i, j)) break;
    Exchange(i, j);
    i = j;
  }
}

template <typename T>
void IndexMinPriorityQueue<T>::Exchange(int32_t i, int32_t j) {
  std::swap(pq_[i], pq_[j]);
  qp_[pq_[i]] = i;
  qp_[pq_[j]] = j;
}

template <typename T>
bool IndexMinPriorityQueue<T>::Greater(int32_t i, int32_t j) const {
  return keys_[pq_[i]] > keys_[pq_[j]];
}

template class IndexMinPriorityQueue<double>;

}  // namespace algo