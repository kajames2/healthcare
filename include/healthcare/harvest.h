#ifndef _HEALTHCARE_HARVEST_H_
#define _HEALTHCARE_HARVEST_H_

#include "healthcare/health_state.h"

namespace healthcare {
class Harvest {
 public:
  virtual int GetHarvest(const HealthState &state) const = 0;
  virtual bool IsWorking(const HealthState &state) const { return true; }
  int GetWorkingHarvest(const HealthState &state) const {
    return this->IsWorking(state) ? GetHarvest(state) : 0;
  }
  virtual ~Harvest() {}
};
}  // namespace healthcare
#endif  // _HEALTHCARE_HARVEST_H_
