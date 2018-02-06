#include "regeneration_logistic.h"
#include <cmath>
#include <vector>

namespace healthcare {

RegenerationLogistic::RegenerationLogistic(double gamma, double delta, double r)
    : gamma_(gamma), delta_(delta), r_(r), RegenerationCached(300) {
  FillCache();
}
RegenerationLogistic::RegenerationLogistic(double gamma, double delta, double r,
                                           int max_investment)
    : gamma_(gamma), delta_(delta), r_(r), RegenerationCached(max_investment) {
  FillCache();
}

int RegenerationLogistic::CalculateHealthRegained(int health,
                                                  int health_investment) const {
  return static_cast<int>(
      gamma_ * (1 - std::exp(-1 * delta_ * health_investment)) /
      (1.0 + std::exp((-1) * delta_ * health_investment - r_)));
}

} // namespace healthcare
