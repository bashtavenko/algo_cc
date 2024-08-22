// Classical graph boilerplate.
//
#ifndef ALGO_CC_GRAPHS_CLASSIC_H_
#define ALGO_CC_GRAPHS_CLASSIC_H_

#include "absl/container/flat_hash_map.h"
#include "absl/container/flat_hash_set.h"

namespace algo {

template <typename T>
class Graph {
 public:
  void AddVertex(const T& vertex);
  void AddEdge(const T& from, const T& to, bool bidirectional = false);
  bool RemoveEdge(const T& from, const T& to);
  bool RemoveVertex(const T& vertex);

  bool HasVertex(const T& vertex) const;
  bool HasEdge(const T& from, const T& to) const;

  std::vector<T> GetVertices() const;
  std::vector<T> GetNeighbors(const T& vertex) const;

  bool IsReachableDFS(const T& from, const T& to) const;
  std::vector<T> ShortestPath(const T& from, const T& to) const;

  void Clear();
  size_t Size() const;
  bool Empty() const;

 private:
  absl::flat_hash_map<T, absl::flat_hash_set<T>> graph_;
  // Returns true if two vertices are reachable.
  // Requires client to provide a visited set.
  bool RunDFS(const T& current, const T& target,
              absl::flat_hash_set<T>& visited) const;
};
}  // namespace algo

#endif  // ALGO_CC_GRAPHS_CLASSIC_H_
