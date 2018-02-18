#include "regeneration_logistic.h"
#include <cmath>

namespace healthcare {

RegenerationLogistic::RegenerationLogistic(double gamma, double delta, double r)
    : gamma_(gamma), delta_(delta), r_(r) {}

int RegenerationLogistic::GetHealthRegained(int health,
                                            int health_investment) const {
  return static_cast<int>(
      gamma_ * (1 - std::exp(-1 * delta_ * health_investment)) /
      (1.0 + std::exp((-1) * delta_ * health_investment - r_)));
}

int RegenerationLogistic::GetRegainCost(int health, int health_regained) const {
  return std::ceil(1 / delta_ *
                   std::log((health_regained * std::exp(-r_) + gamma_) /
                            (gamma_ - health_regained)));
}

} // namespace healthcare
