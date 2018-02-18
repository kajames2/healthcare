#ifndef _HARVEST_LINEAR_H_
#define _HARVEST_LINEAR_H_

#include "harvest.h"
#include "health_state.h"

namespace healthcare {

class HarvestLinear : public Harvest {
 public:
  HarvestLinear(double harvest_rate);
  int GetHarvest(const HealthState& state) const override;
 private:
  double harvest_rate_;
};

} // namespace healthcare
#endif // _HARVEST_LINEAR_H_
