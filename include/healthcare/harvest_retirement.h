#ifndef _HEALTHCARE_HARVEST_RETIREMENT_H_
#define _HEALTHCARE_HARVEST_RETIREMENT_H_

#include "healthcare/harvest.h"
#include "healthcare/health_state.h"

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
}  // namespace healthcare
#endif  // _HEALTHCARE_HARVEST_RETIREMENT_H_
