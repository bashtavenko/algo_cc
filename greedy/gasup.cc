#include "greedy/gasup.h"
#include <cstdint>
#include <vector>

namespace algo {

struct CityAndGas {
  int32_t city = 0;
  int32_t remaining_gallons = 0;
};

static constexpr int32_t kMPG = 20;

int32_t FindAmpleCity(const std::vector<int32_t>& gallons,
                      const std::vector<int32_t>& distances) {
  CityAndGas cityAndGas;

  const int32_t num_cities = gallons.size();
  int32_t remaining_gallons = 0;
  for (int32_t i = 1; i < num_cities; ++i) {
    remaining_gallons += gallons[i - 1] - distances[i - 1] / kMPG;
    if (remaining_gallons < cityAndGas.remaining_gallons) {
      cityAndGas = {.city = i, .remaining_gallons = remaining_gallons};
    }
  }
  return cityAndGas.city;
}

}  // namespace algo
