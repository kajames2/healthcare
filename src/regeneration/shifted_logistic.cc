#include "healthcare/regeneration/shifted_logistic.h"

#include <cmath>

namespace healthcare {
namespace regeneration {

ShiftedLogistic::ShiftedLogistic(double k) : k_(k) {}

int ShiftedLogistic::GetHealthRegained(int health,
                                       int health_investment) const {
  return static_cast<int>(100 * std::exp(k_ * health_investment) /
                              (std::exp(k_ * health_investment) +
                               (100 - health) / static_cast<double>(health)) -
                          health);
}

int ShiftedLogistic::GetRegainCost(int health, int health_regained) const {
  return std::ceil(1 / k_ *
                   std::log(((100 - health) * (health_regained + health) /
                             static_cast<double>(
                                 health * (100 - health - health_regained)))));
}

}  // namespace regeneration
}  // namespace healthcare
