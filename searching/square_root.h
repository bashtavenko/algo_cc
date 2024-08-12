// 11.5 Compute real square root
// This is similar to int_square_root with a few tweaks:
// 1. Need comparator and enums
// 2. Use normalization for precision
// 3. Need 1.0 as lower bound as opposed to 0.
#ifndef ALGO_CC_SEARCHING_SQUARE_ROOT_H_
#define ALGO_CC_SEARCHING_SQUARE_ROOT_H_

namespace algo {

double SquareRoot(double x);

}  // namespace algo

#endif  // ALGO_CC_SEARCHING_SQUARE_ROOT_H_
