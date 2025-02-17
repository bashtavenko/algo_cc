#include "recursion/hanoi.h"
#include <functional>
#include <stack>

namespace algo {

std::vector<std::vector<size_t>> ComputeTowerOfHanoi(size_t num_rings) {
  // Stack is natural since we only push or pop
  std::vector<std::stack<size_t>> pegs(kNumPegs);
  // Initialize pegs
  // 1 - smallest, 2 - medium, 3 - large [3, 2, 1]
  for (size_t i = num_rings; i >= 1; --i) {
    // Push to stack from the large ring
    pegs[0].push(i);
  }
  std::vector<std::vector<size_t>> result;

  std::function<void(size_t, size_t, size_t, size_t)> compute =
      [&](size_t num_rings_to_move, size_t from_peg, size_t to_peg,
          size_t use_peg) {
        if (num_rings_to_move > 0) {
          compute(num_rings_to_move - 1, from_peg, use_peg, to_peg);
          pegs[to_peg].push(pegs[from_peg].top());
          pegs[from_peg].pop();
          result.emplace_back(std::vector<size_t>{from_peg, to_peg});
          compute(num_rings_to_move - 1, use_peg, to_peg, from_peg);
        }
      };

  compute(num_rings, 0, 1, 2);
  return result;
}

}  // namespace algo