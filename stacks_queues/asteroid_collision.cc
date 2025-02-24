#include "stacks_queues/asteroid_collision.h"
#include <valarray>

namespace algo {

// Input: asteroids = [5,10,-5]
// Output: [5,10]
// [8,-8]
// [5, -2, -1, 3, 7, -10, 2]
// [5, -2, -1, 3, 10, 2]
// [5, -2, 3, 10, 2]
// [5, 3, 10, 2]
std::vector<int32_t> AsteroidCollision(const std::vector<int32_t>& asteroids) {
  // Assume valid input and asteroid.size() >= 2
  // Both std::vector and std::stack work the same, but std::vector
  // lets us indexing access, iterators, etc
  std::vector<int32_t> stack;

  for (int32_t a : asteroids) {
    bool destroyed = false;

    // Only process collisions if current asteroid is moving left
    // and there's a positive asteroid at the top of the stack.
    while (!stack.empty() && a < 0 && stack.back() > 0) {
      if (stack.back() < -a) {
        // Top of the stack explodes.
        stack.pop_back();
        continue;  // Check the next asteroid in the stack.
      } else if (stack.back() == -a) {
        // Both asteroids explode.
        stack.pop_back();
      }
      // The current asteroid 'a' is destroyed.
      destroyed = true;
      break;
    }

    if (!destroyed) {
      // If not destroyed, push the current asteroid onto the stack.
      stack.push_back(a);
    }
  }

  return stack;
}
}  // namespace algo