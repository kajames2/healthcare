#include "fractional_regeneration.h"
#include <cmath>

#include <iostream>
#include <memory>

namespace healthcare {

FractionalRegeneration::FractionalRegeneration(double k)
    : FractionalRegeneration(k, 300) {}
FractionalRegeneration::FractionalRegeneration(double k, int max_investment)
    : k_(k), CachedRegeneration(max_investment) {
  FillCache();
}

int FractionalRegeneration::CalculateHealthRegained(
    int health, int health_investment) const {
  return health * health_investment / (health_investment + k_);
}

} // namespace healthcare
