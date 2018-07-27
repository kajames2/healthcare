#include "healthcare/shock/exponential_decay.h"

#include <cmath>

namespace healthcare {
namespace shock {

int ExponentialDecay::operator()(int fitness) const {
  return std::round(max_shock_ * std::exp(-rate_ * fitness));
}

}  // namespace shock
}  // namespace healthcare
