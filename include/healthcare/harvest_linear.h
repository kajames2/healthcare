#ifndef _HARVEST_LINEAR_H_
#define _HARVEST_LINEAR_H_

#include "harvest.h"
#include "health_state.h"

namespace healthcare {

class HarvestLinear : public Harvest {
 public:
  HarvestLinear(int first_period, int last_period, double harvest_rate);
  bool InRange(int period) const override;
 protected:
  int CalculateHarvest(const HealthState& state) const override;
 private:
  int first_period_;
  int last_period_;
  double harvest_rate_;
};

} // namespace healthcare
#endif // _HARVEST_LINEAR_H_
