#include "gflags/gflags.h"
#include "glog/logging.h"

// Alternative is to use std::pmr (Polymorphic Memory Resources)
// std::pmr::polymorphic_allocator
template <typename T, size_t N>
class PoolAllocator {
 public:
  PoolAllocator() {
    for (size_t i = 0; i < N - 1; ++i) {
      pool_[i].next = &pool_[i + 1];
    }
    pool_[N - 1].next = nullptr;
    free_list_ = &pool_[0];
  }

  std::shared_ptr<T> Allocate() {
    if (!free_list_) return nullptr;
    Node* node = free_list_;
    free_list_ = free_list_->next;
    return std::shared_ptr<T>(reinterpret_cast<T*>(&node->storage),
                              [&](T* ptr) { Deallocate(ptr); });
  }

  void Deallocate(T* ptr) {
    LOG(INFO) << "Deallocating...";
    Node* node = reinterpret_cast<Node*>(ptr);
    node->next = free_list_;
    free_list_ = node;
  }

 private:
  union Node {
    // Essentially C array char foo[4];
    alignas(T) char storage[sizeof(T)];
    Node* next;
    Node() {}
    ~Node() {}
  };

  Node pool_[N];
  Node* free_list_;
};

class Trajectory {
 public:
  Trajectory() : id_(0) {}
  void SetId(int32_t id) { id_ = id;};
  void Print() const { LOG(INFO) << "Trajectory " << id_; }

 private:
  int32_t id_;
};

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  FLAGS_logtostderr = 1;

  PoolAllocator<Trajectory, 10> pool;
  std::shared_ptr<Trajectory> t1 = pool.Allocate();
  t1->SetId(42);
  std::shared_ptr<Trajectory> t2 = (pool.Allocate());
  t2->SetId(43);

  t1->Print();
  t2->Print();
}