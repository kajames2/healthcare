#include "harvest_linear.h"
#include "health_state.h"

#include <cmath>

namespace healthcare {
HarvestLinear::HarvestLinear(int first_period, int last_period, double harvest_rate)
    : harvest_rate_(harvest_rate)
    , first_period_(first_period)
    , last_period_(last_period) {}

int HarvestLinear::CalculateHarvest(const HealthState& state) const {
  return std::round(state.health * harvest_rate_);
}

bool HarvestLinear::InRange(int period) const {
  return first_period_ <= period && period <= last_period_;
}
}
