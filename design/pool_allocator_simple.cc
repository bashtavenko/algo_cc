// This is much simpler than templated allocator `pool_allocator`.
#include <memory>
#include <mutex>
#include <vector>
#include "gflags/gflags.h"
#include "glog/logging.h"

class Buffer {
 public:
  explicit Buffer(size_t size) : data(size) {}
  std::vector<uint8_t> data;
};

class BufferPool {
 public:
  BufferPool(size_t pool_size, size_t buffer_size) {
    buffers_.reserve(pool_size);
    free_list_.reserve(pool_size);

    for (size_t i = 0; i < pool_size; ++i) {
      buffers_.emplace_back(buffer_size);
      free_list_.push_back(&buffers_.back());
    }
  }

  // Acquires a buffer from the pool.
  std::shared_ptr<Buffer> Acquire() {
    std::lock_guard lock(mutex_);

    if (free_list_.empty()) return nullptr;

    Buffer* buf = free_list_.back();
    free_list_.pop_back();

    // Lambda deleter
    // Or nested struct deleter
    //return std::shared_ptr<Buffer>(buf, BufferDeleter());
    return std::shared_ptr<Buffer>(buf, [this](Buffer* b) { Release(b); });
  }

 private:
  // TODO: We assume that BufferPool MUST outlive every shared_ptr<Buffer>
  void Release(Buffer* buffer) {
    std::lock_guard lock(mutex_);
    free_list_.push_back(buffer);
  }

  // Alternatively, instead of struct deleter could work as well
  struct BufferDeleter {
    BufferPool* pool;

    void operator()(Buffer* buffer) const {
      pool->Release(buffer); // Needs access to private release()
    }
  };


  std::vector<Buffer> buffers_;
  std::vector<Buffer*> free_list_;
  std::mutex mutex_;
};


int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  FLAGS_logtostderr = 1;

  constexpr size_t kPoolSize = 2;
  constexpr size_t kSize = 10;
  Buffer buffer(kSize);
  BufferPool pool(kPoolSize, kSize);
  std::shared_ptr<Buffer> buf = pool.Acquire();
  std::shared_ptr<Buffer> buf2 = pool.Acquire();
  std::shared_ptr<Buffer> buf3 = pool.Acquire();
}