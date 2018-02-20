#include "healthcare/consumption_increasing_decay.h"

#include <cmath>

namespace healthcare {
ConsumptionIncreasingDecay::ConsumptionIncreasingDecay(double alpha,
                                                       double beta, double c)
    : alpha_(alpha), beta_(beta), c_(c) {}

double ConsumptionIncreasingDecay::GetLifeEnjoyment(int health,
                                                    int life_investment) const {
  return c_ * (beta_ * health / 100.0 + (1 - beta_)) *
         (1 - std::exp(-alpha_ * life_investment));
}

}  // namespace healthcare
