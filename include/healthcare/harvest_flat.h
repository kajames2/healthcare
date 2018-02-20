#ifndef _HEALTHCARE_HARVEST_FLAT_H_
#define _HEALTHCARE_HARVEST_FLAT_H_

#include "healthcare/harvest.h"
#include "healthcare/health_state.h"

namespace healthcare {

class HarvestFlat : public Harvest {
 public:
  explicit HarvestFlat(int harvest) : harvest_(harvest) {}
  int GetHarvest(const HealthState &state) const override { return harvest_; };

 private:
  int harvest_;
};

}  // namespace healthcare
#endif  // _HEALTHCARE_HARVEST_FLAT_H_
