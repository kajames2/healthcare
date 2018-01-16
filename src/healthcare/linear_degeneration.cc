#include "linear_degeneration.h"
#include <cmath>

namespace healthcare {

LinearDegeneration::LinearDegeneration(
    double degen_intercept)
    : degen_intercept_(degen_intercept),
      degen_slope_(0) {}

LinearDegeneration::LinearDegeneration(
    double degen_intercept, double degen_slope)
    : degen_intercept_(degen_intercept),
      degen_slope_(degen_slope) {}

int LinearDegeneration::GetDegeneration(int period) const {
  return std::round(degen_intercept_ + degen_slope_ * period);
}

} // namespace healthcare
