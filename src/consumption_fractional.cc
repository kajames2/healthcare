#include "healthcare/consumption_fractional.h"

namespace healthcare {

ConsumptionFractional::ConsumptionFractional(double j) : j_(j) {}

double ConsumptionFractional::GetLifeEnjoyment(int health,
                                               int life_investment) const {
  return health * life_investment / (life_investment + j_);
}

}  // namespace healthcare
