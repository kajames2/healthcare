#ifndef _HEALTHCARE_HARVEST_LINEAR_H_
#define _HEALTHCARE_HARVEST_LINEAR_H_

#include "healthcare/harvest.h"
#include "healthcare/health_state.h"

namespace healthcare {

class HarvestLinear : public Harvest {
 public:
  explicit HarvestLinear(double harvest_rate);
  int GetHarvest(const HealthState& state) const override;

 private:
  double harvest_rate_;
};

}  // namespace healthcare
#endif  // _HEALTHCARE_HARVEST_LINEAR_H_
