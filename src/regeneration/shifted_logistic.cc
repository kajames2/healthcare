#include "healthcare/regeneration/shifted_logistic.h"

#include <cassert>
#include <cmath>

namespace healthcare {
namespace regeneration {

ShiftedLogistic::ShiftedLogistic(double k) : k_(k) {}

int ShiftedLogistic::GetHealthRegained(int health,
                                       int health_investment) const {
  if (health == 0) {
    return 0;
  }
  return static_cast<int>(100 * std::exp(k_ * health_investment) /
                              (std::exp(k_ * health_investment) +
                               (100 - health) / static_cast<double>(health)) -
                          health);
}

int ShiftedLogistic::GetRegainCost(int health, int health_regained) const {
  assert(health_regained >=0);
  if (health_regained > 0 && (health == 0 || health == 99 || health == 100)) {
    return 10000;
  }
  if (health == 0 || health == 100) {
    return 0;
  }
  return std::ceil(1 / k_ *
                   std::log(((100 - health) * (health_regained + health) /
                             static_cast<double>(
                                 health * (100 - health - health_regained)))));
}

}  // namespace regeneration
}  // namespace healthcare
