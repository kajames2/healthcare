#include "healthcare/consumption_log_logistic.h"

#include <cmath>

namespace healthcare {

ConsumptionLogLogistic::ConsumptionLogLogistic(double alpha, double beta,
                                               double c)
    : alpha_(alpha), beta_(beta), c_(c) {}

double ConsumptionLogLogistic::GetLifeEnjoyment(int health,
                                                int life_investment) const {
  return c_ * health / (1 + std::pow((life_investment) / alpha_, -beta_));
}

}  // namespace healthcare
