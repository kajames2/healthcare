#include "harvest_composite.h"
#include "harvest.h"
#include "health_state.h"

#include <vector>

namespace healthcare {
HarvestComposite::HarvestComposite()
    : harvest_strats_() {
  null_harvest_ = std::make_unique<NullHarvest>();
}

int HarvestComposite::CalculateHarvest(const HealthState &state) const {
  return GetHarvestInRange(state.period).GetHarvest(state);
}

int HarvestComposite::GetWorkingHarvest(const HealthState &state) const {
    return GetHarvestInRange(state.period).GetWorkingHarvest(state);
}

void HarvestComposite::AddHarvest(std::shared_ptr<const Harvest> state) {
  harvest_strats_.push_back(state);
}

bool HarvestComposite::InRange(int period) const {
  for (auto strat : harvest_strats_) {
    if (strat->InRange(period))
      return true;
  }
  return false;
}

const Harvest&
HarvestComposite::GetHarvestInRange(int period) const {
  for (auto strat : harvest_strats_) {
    if (strat->InRange(period))
      return *strat;
  }
  return *null_harvest_;
}
} // namespace healthcare
