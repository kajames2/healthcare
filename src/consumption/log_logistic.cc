#include "healthcare/consumption/log_logistic.h"

#include <cmath>

namespace healthcare {
namespace consumption {

LogLogistic::LogLogistic(double alpha, double beta, double c)
    : alpha_(alpha), beta_(beta), c_(c) {}

double LogLogistic::GetLifeEnjoyment(int health, int life_investment) const {
  return c_ * health / (1 + std::pow((life_investment) / alpha_, -beta_));
}

}  // namespace consumption
}  // namespace healthcare
