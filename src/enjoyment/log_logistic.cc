#include "healthcare/enjoyment/log_logistic.h"

#include <cmath>

namespace healthcare {
namespace enjoyment {

LogLogistic::LogLogistic(double alpha, double beta, double c)
    : alpha_(alpha), beta_(beta), c_(c) {}

double LogLogistic::GetEnjoyment(int health, int life_investment) const {
  return c_ * health / (1 + std::pow((life_investment) / alpha_, -beta_));
}

}  // namespace enjoyment
}  // namespace healthcare
