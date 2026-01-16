#include "gflags/gflags.h"
#include "glog/logging.h"

template <typename T, size_t N>
class PoolAllocator {
 public:
  PoolAllocator() {
    for (size_t i = 0; i < N - 1; ++i) nodes_[i].next = &nodes_[i + 1];
    nodes_[N - 1].next = nullptr;
    free_list_ = &nodes_[0];
  }

  T* Allocate() {
    if (!free_list_) return nullptr;
    Node* node = free_list_;
    free_list_ = free_list_->next;
    return reinterpret_cast<T*>(&node->storage);
  }

  void Deallocate(T* ptr) {
    Node* node = reinterpret_cast<Node*>(ptr);
    node->next = free_list_;
    free_list_ = node;
  }

 private:
  union Node {
    // Essentially C array char foo[4];
    alignas(T) char storage[sizeof(T)];
    Node* next;
  };

  Node nodes_[N];
  Node* free_list_;
};

class Trajectory {
 public:
  Trajectory(int id) : id_(id) {}
  void Print() const { LOG(INFO) << "Trajectory " << id_; }

 private:
  int id_;
};

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  FLAGS_logtostderr = 1;

  PoolAllocator<Trajectory, 10> pool;

  // Allocate. Ideally this should be std::unique_ptr and custom deleter.
  Trajectory* t1 = new (pool.Allocate()) Trajectory(1);  // placement new
  Trajectory* t2 = new (pool.Allocate()) Trajectory(2);

  t1->Print();
  t2->Print();

  // Deallocate
  t1->~Trajectory();
  pool.Deallocate(t1);

  t2->~Trajectory();
  pool.Deallocate(t2);
}