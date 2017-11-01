#include "increasing_decay_consumption.h"
#include <cmath>

namespace healthcare {
IncreasingDecayConsumption::IncreasingDecayConsumption(double alpha,
                                                       double beta, double c)
    : IncreasingDecayConsumption(alpha, beta, c, 300) {}
IncreasingDecayConsumption::IncreasingDecayConsumption(double alpha,
                                                       double beta, double c,
                                                       int max_investment)
    : alpha_(alpha), beta_(beta), c_(c), CachedConsumption(max_investment) {
  FillCache();
}

double
IncreasingDecayConsumption::CalculateLifeEnjoyment(int health,
                                                   int life_investment) const {
  return c_ * (beta_ * health / 100.0 + (1 - beta_)) *
         (1 - std::exp(-alpha_ * life_investment));
}

} // namespace healthcare
