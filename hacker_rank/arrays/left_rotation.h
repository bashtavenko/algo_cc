// A left rotation operation on an array shifts each of the array's elements
// unit to the left.
//
// For example, if 2 left rotations are performed on array [1, 2, 3, 4, 5],
// then the array would become [3, 4, 5, 1, 2]
//
// Note that the lowest index item moves to the
// highest index in a rotation. This is called a circular array.
//
// Given an array  of  integers and a number, perform  left rotations on the
// array. Return the updated array to be printed as a single line of
// space-separated integers.
//

#ifndef ALGO_CC_HACKER_RANK_ARRAYS_LEFT_ROTATION_H_
#define ALGO_CC_HACKER_RANK_ARRAYS_LEFT_ROTATION_H_

#include <vector>

std::vector<int> RotateLeftFirstTry(const std::vector<int>& a, int k);
std::vector<int> RotateLeft(const std::vector<int>& a, int k);
std::vector<int> RotateLeftSTD(const std::vector<int>& a, int k);

#endif  // ALGO_CC_HACKER_RANK_ARRAYS_LEFT_ROTATION_H_
