#include "healthcare/harvest_linear.h"

#include <cmath>

namespace healthcare {
HarvestLinear::HarvestLinear(double harvest_rate)
    : harvest_rate_(harvest_rate) {}

int HarvestLinear::GetHarvest(int age, int health) const {
  return std::round(health * harvest_rate_);
}
}  // namespace healthcare
