#include "regeneration_fractional.h"
#include <cmath>

#include <iostream>
#include <memory>

namespace healthcare {

RegenerationFractional::RegenerationFractional(double k)
    : k_(k), RegenerationCached(300) {
  FillCache();
}
RegenerationFractional::RegenerationFractional(double k, int max_investment)
    : k_(k), RegenerationCached(max_investment) {
  FillCache();
}

int RegenerationFractional::CalculateHealthRegained(
    int health, int health_investment) const {
  return (100 - health) * health_investment / (health_investment + k_);
}

int RegenerationFractional::CalculateRegainCost(int health,
                                                int health_regained) const {
  return std::ceil((k_ * health_regained) / (100 - health - health_regained));
}

} // namespace healthcare
