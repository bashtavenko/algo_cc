#include "graphs/classic.h"
#include <limits>
#include <queue>
#include "absl/container/flat_hash_map.h"
#include "absl/container/flat_hash_set.h"

namespace algo {

template <typename T>
void Graph<T>::AddVertex(const T& vertex) {
  if (!HasVertex(vertex)) {
    graph_[vertex] = absl::flat_hash_set<T>();
  }
}

template <typename T>
void Graph<T>::AddEdge(const T& from, const T& to, bool bidirectional) {
  AddVertex(from);
  AddVertex(to);
  graph_[from].insert(to);
  if (bidirectional) {
    graph_[to].insert(from);
  }
}

template <typename T>
bool Graph<T>::RemoveEdge(const T& from, const T& to) {
  if (HasVertex(from)) {
    return graph_[from].erase(to) > 0;
  }
  return false;
}

template <typename T>
bool Graph<T>::RemoveVertex(const T& vertex) {
  if (!HasVertex(vertex)) {
    return false;
  }

  graph_.erase(vertex);
  for (auto& [_, neighbors] : graph_) {
    neighbors.erase(vertex);
  }
  return true;
}

template <typename T>
bool Graph<T>::HasVertex(const T& vertex) const {
  return graph_.contains(vertex);
}

template <typename T>
bool Graph<T>::HasEdge(const T& from, const T& to) const {
  if (HasVertex(from)) {
    return graph_.at(from).contains(to);
  }
  return false;
}

template <typename T>
std::vector<T> Graph<T>::GetVertices() const {
  std::vector<T> vertices;
  vertices.reserve(graph_.size());
  for (const auto& [vertex, _] : graph_) {
    vertices.push_back(vertex);
  }
  return vertices;
}

template <typename T>
std::vector<T> Graph<T>::GetNeighbors(const T& vertex) const {
  if (HasVertex(vertex)) {
    return std::vector<T>(graph_.at(vertex).begin(), graph_.at(vertex).end());
  }
  return {};
}

template <typename T>
bool Graph<T>::IsReachableDFS(const T& from, const T& to) const {
  if (!HasVertex(from) || !HasVertex(to)) return false;
  absl::flat_hash_set<T> visited;
  return RunDFS(from, to, visited);
}

template <typename T>
bool Graph<T>::IsReachableBFS(const T& from, const T& to) const {
  if (!HasVertex(from) || !HasVertex(to)) return false;
  absl::flat_hash_set<T> visited;
  return RunBFS(from, to, visited);
}

template <typename T>
bool Graph<T>::RunDFS(const T& current, const T& target,
                      absl::flat_hash_set<T>& visited) const {
  visited.insert(current);
  if (current == target) {
    return true;
  }
  for (const T& neighbor : graph_.at(current)) {
    if (!visited.contains(neighbor)) {
      if (RunDFS(neighbor, target, visited)) return true;
    }
  }
  return false;
}

template <typename T>
bool Graph<T>::RunBFS(const T& current, const T& target,
                      absl::flat_hash_set<T>& visited) const {
  std::queue<T> queue;
  visited.insert(current);
  queue.push(current);
  while (!queue.empty()) {
    T current = queue.front();
    queue.pop();
    if (current == target) return true;
    for (const T& neighbor : graph_.at(current)) {
      if (!visited.contains(neighbor)) {
        visited.insert(neighbor);
        queue.push(neighbor);
      }
    }
  }
  return false;
}

template <typename T>
std::vector<T> Graph<T>::ShortestPath(const T& from, const T& to) const {
  if (!HasVertex(from) || !HasVertex(to)) {
    return {};
  }

  absl::flat_hash_map<T, T> previous;
  absl::flat_hash_map<T, int> distance;
  std::queue<T> queue;

  for (const auto& [vertex, _] : graph_) {
    distance[vertex] = std::numeric_limits<int>::max();
  }

  distance[from] = 0;
  queue.push(from);

  while (!queue.empty()) {
    T current = queue.front();
    queue.pop();

    if (current == to) {
      break;
    }

    for (const T& neighbor : graph_.at(current)) {
      int new_distance = distance[current] + 1;
      if (new_distance < distance[neighbor]) {
        distance[neighbor] = new_distance;
        previous[neighbor] = current;
        queue.push(neighbor);
      }
    }
  }

  if (previous.find(to) == previous.end()) {
    return {};  // No path found
  }

  std::vector<T> path;
  for (T at = to; at != from; at = previous[at]) {
    path.push_back(at);
  }
  path.push_back(from);
  std::reverse(path.begin(), path.end());
  return path;
}

template <typename T>
void Graph<T>::Clear() {
  graph_.clear();
}

template <typename T>
size_t Graph<T>::Size() const {
  return graph_.size();
}

template <typename T>
bool Graph<T>::Empty() const {
  return graph_.empty();
}

// Explicit template specialization in .cc file.
template class Graph<int32_t>;

}  // namespace algo