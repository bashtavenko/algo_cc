#include "hacker_rank/one_month/week_4/transmitters.h"
#include <vector>
#include "algorithm"

int Transmitters(std::vector<int> x, int k) {
  std::sort(x.begin(), x.end());
  int count = 0;
  int i = 0;
  int n = x.size();

  while (i < n) {
    // Place the transmitter at the furthest house within range of x[i]
    // Because array is sorted, we can check the value of houses
    int loc = x[i] + k;  // loc may not be a real location of the house
    while (i < n && x[i] <= loc) ++i;

    count++;

    // Move i to the next house outside the range of this transmitter
    loc = x[--i] + k;
    while (i < n && x[i] <= loc) ++i;
  }

  return count;
}