#include "regeneration_fractional.h"
#include <cmath>

namespace healthcare {

RegenerationFractional::RegenerationFractional(double k) : k_(k) {}

int RegenerationFractional::GetHealthRegained(int health,
                                              int health_investment) const {
  return (100 - health) * health_investment / (health_investment + k_);
}

int RegenerationFractional::GetRegainCost(int health,
                                          int health_regained) const {
  return std::ceil((k_ * health_regained) / (100 - health - health_regained));
}

} // namespace healthcare
