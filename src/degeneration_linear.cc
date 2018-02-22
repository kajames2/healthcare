#include "healthcare/degeneration_linear.h"
#include <cmath>

namespace healthcare {

DegenerationLinear::DegenerationLinear(double degen_intercept)
    : degen_intercept_(degen_intercept), degen_slope_(0) {}

DegenerationLinear::DegenerationLinear(double degen_intercept,
                                       double degen_slope)
    : degen_intercept_(degen_intercept), degen_slope_(degen_slope) {}

int DegenerationLinear::GetDegeneration(int age) const {
  return std::round(degen_intercept_ + degen_slope_ * age);
}

}  // namespace healthcare
