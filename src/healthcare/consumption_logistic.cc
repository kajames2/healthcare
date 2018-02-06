#include "consumption_logistic.h"
#include "consumption_cached.h"
#include <cmath>

namespace healthcare {

ConsumptionLogistic::ConsumptionLogistic(double k)
    : k_(k), ConsumptionCached(300) {
  FillCache();
}

ConsumptionLogistic::ConsumptionLogistic(double k, int max_investment)
    : k_(k), ConsumptionCached(max_investment) {
  FillCache();
}

double ConsumptionLogistic::CalculateLifeEnjoyment(int health,
                                                   int life_investment) const {
  return health * 1.0 / (1.0 + std::exp(-1 * k_ * life_investment));
}

} // namespace healthcare
