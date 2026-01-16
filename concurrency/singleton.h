#ifndef CONCURRENCY_SINGLETON_H_
#define CONCURRENCY_SINGLETON_H_

#include <mutex>

namespace concurrency {

class Singleton {
 public:
  static Singleton& GetInstance() {
    static Singleton instance;
    return instance;
  }

  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  int GetValue() {
    std::lock_guard<std::mutex> lock(mu_);
    return value_;
  }

  void Increment() {
    std::lock_guard<std::mutex> lock(mu_);
    value_++;
  }

 private:
  Singleton() : value_(0) {}

  std::mutex mu_;
  int value_;
};

}  // namespace concurrency

#endif  // CONCURRENCY_SINGLETON_H_
