#include "regeneration_shifted_log_logistic.h"

#include <cmath>
#include <vector>

namespace healthcare {

RegenerationShiftedLogLogistic::RegenerationShiftedLogLogistic(double alpha,
                                                               double beta)
    : alpha_(alpha), beta_(beta), RegenerationCached(300) {
  FillCache();
}
RegenerationShiftedLogLogistic::RegenerationShiftedLogLogistic(
    double alpha, double beta, int max_investment)
    : alpha_(alpha), beta_(beta), RegenerationCached(max_investment) {
  FillCache();
}

int RegenerationShiftedLogLogistic::CalculateHealthRegained(
    int health, int health_investment) const {
  if (health == 0) {
    return 0;
  }
  double shift = alpha_ * std::pow((100 - health) / static_cast<double>(health),
                                   -1 / beta_);
  return static_cast<int>(
      100 / (1 + std::pow((health_investment + shift) / alpha_, -beta_)) -
      health);
}

int RegenerationShiftedLogLogistic::CalculateRegainCost(
    int health, int health_regained) const {
  double term1 = std::pow(100.0 / (health + health_regained) - 1, -1 / beta_);
  double term2 = std::pow(100.0 / health - 1, -1 / beta_);
  return std::ceil(alpha_ * (term1 + term2));
}

} // namespace healthcare
