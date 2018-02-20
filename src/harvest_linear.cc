#include "healthcare/harvest_linear.h"

#include <cmath>

#include "healthcare/health_state.h"

namespace healthcare {
HarvestLinear::HarvestLinear(double harvest_rate)
    : harvest_rate_(harvest_rate) {}

int HarvestLinear::GetHarvest(const HealthState &state) const {
  return std::round(state.health * harvest_rate_);
}
}  // namespace healthcare
