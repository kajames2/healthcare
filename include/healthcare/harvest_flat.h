#ifndef _HARVEST_FLAT_H_
#define _HARVEST_FLAT_H_

#include "harvest.h"
#include "health_state.h"

namespace healthcare {

class HarvestFlat : public Harvest {
public:
  HarvestFlat(int harvest) : harvest_(harvest) {}
  int GetHarvest(const HealthState &state) const override { return harvest_; };

private:
  int harvest_;
};

} // namespace healthcare
#endif // _HARVEST_FLAT_H_
