#include "healthcare/regeneration/shifted_logistic_rounded.h"

#include <cmath>
#include <numeric>

namespace healthcare {
namespace regeneration {

ShiftedLogisticRounded::ShiftedLogisticRounded(double k)
    : cost_vec_(101), k_(k) {
  for (int h = 1; h <= 100; ++h) {
    cost_vec_[h] = CalculateRegainCost(h - 1, 1);
  }
  std::partial_sum(cost_vec_.begin(), cost_vec_.end(), cost_vec_.begin());
}

int ShiftedLogisticRounded::GetHealthRegained(int health,
                                              int health_investment) const {
  int cur_investment = cost_vec_[health];
  auto it = std::find_if(cost_vec_.begin(), cost_vec_.end(),
                         [health_investment, cur_investment](int cost) {
                           return health_investment < cost - cur_investment;
                         });
  return std::distance(cost_vec_.begin(), it) - health - 1;
}

int ShiftedLogisticRounded::GetRegainCost(int health,
                                          int health_regained) const {
  return cost_vec_[health + health_regained] - cost_vec_[health];
}

int ShiftedLogisticRounded::CalculateRegainCost(int health,
                                                int health_regained) const {
  if (health_regained > 0 && (health == 0 || health == 99 || health == 100)) {
    return 10000;
  }
  if (health == 0 || health == 100) {
    return 0;
  }
  return std::round(1 / k_ *
                    std::log(((100 - health) * (health_regained + health) /
                              static_cast<double>(
                                  health * (100 - health - health_regained)))));
}

}  // namespace regeneration
}  // namespace healthcare
