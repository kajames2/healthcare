#include "regeneration_shifted_logistic.h"

#include <cmath>
#include <vector>

namespace healthcare {

RegenerationShiftedLogistic::RegenerationShiftedLogistic(double k)
    : k_(k), RegenerationCached(300) {
  FillCache();
}
RegenerationShiftedLogistic::RegenerationShiftedLogistic(double k,
                                                         int max_investment)
    : k_(k), RegenerationCached(max_investment) {
  FillCache();
}

int RegenerationShiftedLogistic::CalculateHealthRegained(
    int health, int health_investment) const {
  return static_cast<int>(100 * std::exp(k_ * health_investment) /
                              (std::exp(k_ * health_investment) +
                               (100 - health) / static_cast<double>(health)) -
                          health);
}

int RegenerationShiftedLogistic::CalculateRegainCost(
    int health, int health_regained) const {
  return std::ceil(1 / k_ *
                   std::log(((100 - health) * (health_regained + health) /
                             static_cast<double>(health * (100 - health - health_regained)))));
}

} // namespace healthcare
