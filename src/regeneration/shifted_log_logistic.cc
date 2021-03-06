#include "healthcare/regeneration/shifted_log_logistic.h"

#include <cmath>

namespace healthcare {
namespace regeneration {
ShiftedLogLogistic::ShiftedLogLogistic(double alpha, double beta)
    : alpha_(alpha), beta_(beta) {}

int ShiftedLogLogistic::GetHealthRegained(int health,
                                          int health_investment) const {
  if (health == 0) {
    return 0;
  }
  double shift = alpha_ * std::pow((100 - health) / static_cast<double>(health),
                                   -1 / beta_);
  return static_cast<int>(
      100 / (1 + std::pow((health_investment + shift) / alpha_, -beta_)) -
      health);
}

int ShiftedLogLogistic::GetRegainCost(int health, int health_regained) const {
  double term1 = std::pow(100.0 / (health + health_regained) - 1, -1 / beta_);
  double term2 = std::pow(100.0 / health - 1, -1 / beta_);
  return std::ceil(alpha_ * (term1 + term2));
}

}  // namespace regeneration
}  // namespace healthcare
