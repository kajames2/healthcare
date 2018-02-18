#include "harvest_linear.h"
#include "health_state.h"

#include <cmath>

namespace healthcare {
HarvestLinear::HarvestLinear(double harvest_rate)
    : harvest_rate_(harvest_rate) {}

int HarvestLinear::GetHarvest(const HealthState &state) const {
  return std::round(state.health * harvest_rate_);
}
}
