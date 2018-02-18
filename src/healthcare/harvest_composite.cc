#include "harvest_composite.h"
#include "harvest.h"
#include "health_state.h"
#include "period_range.h"

#include <vector>

namespace healthcare {
HarvestComposite::HarvestComposite() : harvests_(), ranges_() {}

bool HarvestComposite::IsWorking(const HealthState &state) const {
  int i = GetHarvestIndex(state.period);
  if (i == ranges_.size()) {
    return false;
  }
  return harvests_[i]->IsWorking(state);
}

int HarvestComposite::GetHarvest(const HealthState &state) const {
  int i = GetHarvestIndex(state.period);
  if (i == ranges_.size()) {
    return 0;
  }
  return harvests_[i]->GetHarvest(state);
}

void HarvestComposite::AddHarvest(PeriodRange range,
                                  std::unique_ptr<const Harvest> state) {
  ranges_.push_back(range);
  harvests_.push_back(std::move(state));
}

int HarvestComposite::GetHarvestIndex(int period) const {
  for (int i = 0; i < ranges_.size(); ++i) {
    if (InRange(ranges_[i], period)) {
      return i;
    }
  }
  return ranges_.size();
}
} // namespace healthcare
