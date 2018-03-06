#include "healthcare/job/linear.h"

#include <cmath>

namespace healthcare {
namespace job {

Linear::Linear(double rate) : rate_(rate) {}

int Linear::GetEarnings(int age, int health) const {
  return std::round(health * rate_);
}

}  // namespace job
}  // namespace healthcare
