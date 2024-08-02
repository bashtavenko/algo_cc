#include "stacks_queues/stack_max.h"
#include <stack>
#include "absl/types/optional.h"

namespace algo {

bool Stack::Empty() const { return element_with_cache_max_.empty(); }

absl::optional<int32_t> Stack::Max() const {
  if (Empty()) return {};
  return element_with_cache_max_.top().max;
}

absl::optional<int32_t> Stack::Pop() {
  int32_t element = element_with_cache_max_.top().element;
  element_with_cache_max_.pop();  // Pop does not return the value
  return element;
};

void Stack::Push(int32_t x) {
  // The real gist is this
  element_with_cache_max_.push(ElementWithCacheMax{
      .element = x, .max = std::max(x, Empty() ? x : Max().value())});
}

}  // namespace algo
