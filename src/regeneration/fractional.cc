#include "healthcare/regeneration/fractional.h"

#include <cmath>

namespace healthcare {
namespace regeneration {

Fractional::Fractional(double k) : k_(k) {}

int Fractional::GetHealthRegained(int health, int health_investment) const {
  return ((100 - health) * health_investment) / (health_investment + k_);
}

int Fractional::GetRegainCost(int health, int health_regained) const {
  if (health == 100) {return 0;}
  return std::ceil((k_ * health_regained) / (100 - health - health_regained));
}

}  // namespace regeneration
}  // namespace healthcare
