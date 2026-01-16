#include <gmock/gmock-matchers.h>
#include <gtest/gtest.h>
#include <thread>
#include <vector>
#include "stacks_queues/bounded_queue.h"

namespace algo {
namespace {

TEST(BoundedQeue, ProducerConsumer) {
  BoundedQueue<int32_t> queue(3);

  std::vector<int> produced = {1, 2, 3, 4, 5};
  std::vector<int> consumed;
  consumed.reserve(produced.size());

  // Producer thread
  std::thread producer([&]() {
    for (int x : produced) {
      queue.Push(x);
    }
  });

  // Consumer thread
  std::thread consumer([&]() {
    for (size_t i = 0; i < produced.size(); ++i) {
      consumed.push_back(queue.Pop());
    }
  });

  producer.join();
  consumer.join();

  ASSERT_EQ(consumed.size(), produced.size());
  EXPECT_EQ(consumed, produced);
}


} // namespace
} // namespace algo