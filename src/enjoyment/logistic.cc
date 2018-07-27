#include "healthcare/enjoyment/logistic.h"

#include <cmath>

namespace healthcare {
namespace enjoyment {

Logistic::Logistic(double k) : k_(k) {}

double Logistic::GetEnjoyment(int health, int life_investment) const {
  return health * 1.0 / (1.0 + std::exp(-1 * k_ * life_investment));
}

}  // namespace enjoyment
}  // namespace healthcare
