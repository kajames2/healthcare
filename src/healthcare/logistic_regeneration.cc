#include "logistic_regeneration.h"
#include <cmath>
#include <vector>

namespace healthcare {

LogisticRegeneration::LogisticRegeneration(double gamma, double delta, double r)
    : LogisticRegeneration(gamma, delta, r, 300) {}
LogisticRegeneration::LogisticRegeneration(double gamma, double delta, double r,
                                           int max_investment)
    : gamma_(gamma), delta_(delta), r_(r), CachedRegeneration(max_investment) {
  FillCache();
}

int LogisticRegeneration::CalculateHealthRegained(int health,
                                                  int health_investment) const {
  return static_cast<int>(
      gamma_ * (1 - std::exp(-1 * delta_ * health_investment)) /
      (1.0 + std::exp((-1) * delta_ * health_investment - r_)));
}

} // namespace healthcare
