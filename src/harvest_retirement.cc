#include "healthcare/harvest_retirement.h"

#include <cmath>

#include "healthcare/health_state.h"

namespace healthcare {
HarvestRetirement::HarvestRetirement(int n_working_periods, double earning_frac)
    : n_working_periods_(n_working_periods), earning_frac_(earning_frac) {}

int HarvestRetirement::GetHarvest(const HealthState &state) const {
  return std::round(state.total_working_harvest * earning_frac_ /
                    n_working_periods_);
}
}  // namespace healthcare
