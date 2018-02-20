#include "healthcare/consumption_logistic.h"

#include <cmath>

namespace healthcare {

ConsumptionLogistic::ConsumptionLogistic(double k) : k_(k) {}

double ConsumptionLogistic::GetLifeEnjoyment(int health,
                                             int life_investment) const {
  return health * 1.0 / (1.0 + std::exp(-1 * k_ * life_investment));
}

}  // namespace healthcare
