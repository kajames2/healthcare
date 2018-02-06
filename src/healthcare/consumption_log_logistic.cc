#include "consumption_log_logistic.h"

#include <cmath>
#include <vector>

namespace healthcare {

ConsumptionLogLogistic::ConsumptionLogLogistic(double alpha, double beta,
                                               double c)
    : alpha_(alpha), beta_(beta), c_(c), ConsumptionCached(300) {
  FillCache();
}
ConsumptionLogLogistic::ConsumptionLogLogistic(double alpha, double beta,
                                               double c, int max_investment)
    : alpha_(alpha), beta_(beta), c_(c), ConsumptionCached(max_investment) {
  FillCache();
}

double
ConsumptionLogLogistic::CalculateLifeEnjoyment(int health,
                                               int life_investment) const {
  return c_ * health / (1 + std::pow((life_investment) / alpha_, -beta_));
}

} // namespace healthcare
