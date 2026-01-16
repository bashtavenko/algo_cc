#include "concurrency/singleton.h"
#include <gtest/gtest.h>
#include <thread>
#include <vector>
#include <atomic>

namespace concurrency {
namespace {

TEST(SingletonTest, SameInstance) {
  Singleton& s1 = Singleton::GetInstance();
  Singleton& s2 = Singleton::GetInstance();
  EXPECT_EQ(&s1, &s2);
}

TEST(SingletonTest, ThreadSafety) {
  constexpr int kNumThreads = 10;
  constexpr int kIncrementsPerThread = 1000;
  std::vector<std::thread> threads;
  
  for (int i = 0; i < kNumThreads; ++i) {
    threads.emplace_back([kIncrementsPerThread]() {
      for (int j = 0; j < kIncrementsPerThread; ++j) {
        Singleton::GetInstance().Increment();
      }
    });
  }

  for (auto& t : threads) {
    t.join();
  }

  EXPECT_EQ(Singleton::GetInstance().GetValue(), kNumThreads * kIncrementsPerThread);
}

}  // namespace
}  // namespace concurrency
