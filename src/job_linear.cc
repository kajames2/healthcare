#include "healthcare/job_linear.h"

#include <cmath>

namespace healthcare {
JobLinear::JobLinear(double job_rate)
    : job_rate_(job_rate) {}

int JobLinear::GetEarnings(int age, int health) const {
  return std::round(health * job_rate_);
}
}  // namespace healthcare
