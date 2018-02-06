#ifndef _HARVEST_RETIREMENT_H_
#define _HARVEST_RETIREMENT_H_

#include "harvest.h"
#include "health_state.h"

namespace healthcare {
class HarvestRetirement : public Harvest {
public:
  HarvestRetirement(int first_period, double earning_frac);
  int GetWorkingHarvest(const HealthState &state) const override { return 0; }
  bool InRange(int period) const override;

protected:
  int CalculateHarvest(const HealthState &state) const override;

private:
  double earning_frac_;
  int first_period_;
};
} // namespace healthcare
#endif // _HARVEST_RETIREMENT_H_
