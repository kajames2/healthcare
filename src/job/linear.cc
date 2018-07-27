#include "healthcare/job/linear.h"

#include <cmath>

namespace healthcare {
namespace job {

Linear::Linear(float rate, int intercept) : rate_(rate), intercept_(intercept) {}

int Linear::GetEarnings(int age, int health) const {
  return std::round(health * rate_ + intercept_);
}

}  // namespace job
}  // namespace healthcare
