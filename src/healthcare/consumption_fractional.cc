#include "consumption_fractional.h"
#include <cmath>

#include <iostream>
#include <memory>

namespace healthcare {

ConsumptionFractional::ConsumptionFractional(double j)
    : j_(j), ConsumptionCached(300) {
  FillCache();
}
ConsumptionFractional::ConsumptionFractional(double j, int max_investment)
    : j_(j), ConsumptionCached(max_investment) {
  FillCache();
}

double
ConsumptionFractional::CalculateLifeEnjoyment(int health,
                                              int life_investment) const {
  return health * life_investment / (life_investment + j_);
}

} // namespace healthcare
