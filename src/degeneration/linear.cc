#include "healthcare/degeneration/linear.h"
#include <cmath>

namespace healthcare {
namespace degeneration {

Linear::Linear(double degen_intercept)
    : degen_intercept_(degen_intercept), degen_slope_(0) {}

Linear::Linear(double degen_intercept, double degen_slope)
    : degen_intercept_(degen_intercept), degen_slope_(degen_slope) {}

int Linear::GetDegeneration(int age, int health) const {
  return std::round(degen_intercept_ + degen_slope_ * age);
}

}  // namespace degeneraton
}  // namespace healthcare
