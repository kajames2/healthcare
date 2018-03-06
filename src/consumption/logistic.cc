#include "healthcare/consumption/logistic.h"

#include <cmath>

namespace healthcare {
namespace consumption {

Logistic::Logistic(double k) : k_(k) {}

double Logistic::GetLifeEnjoyment(int health, int life_investment) const {
  return health * 1.0 / (1.0 + std::exp(-1 * k_ * life_investment));
}

}  // namespace consumption
}  // namespace healthcare
