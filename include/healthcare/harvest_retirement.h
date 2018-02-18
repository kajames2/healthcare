#ifndef _HARVEST_RETIREMENT_H_
#define _HARVEST_RETIREMENT_H_

#include "harvest.h"
#include "health_state.h"

namespace healthcare {
class HarvestRetirement : public Harvest {
public:
  HarvestRetirement(int n_working_periods, double earning_frac);
  bool IsWorking(const HealthState &state) const override { return false; }
  int GetHarvest(const HealthState &state) const override;

private:
  double earning_frac_;
  int n_working_periods_;
};
} // namespace healthcare
#endif // _HARVEST_RETIREMENT_H_
