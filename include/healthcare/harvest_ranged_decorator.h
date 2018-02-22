#ifndef _HEALTHCARE_HARVEST_RANGED_DECORATOR_H_
#define _HEALTHCARE_HARVEST_RANGED_DECORATOR_H_

#include <memory>

#include "healthcare/harvest.h"
#include "healthcare/age_range.h"

class HealthState;

namespace healthcare {
class HarvestRangedDecorator : public Harvest {
 public:
  HarvestRangedDecorator(AgeRange range,
                         std::unique_ptr<const Harvest> harvest);
  int GetHarvest(int age, int health) const override;

 private:
  std::unique_ptr<const Harvest> harvest_;
  AgeRange range_;
};
}  // namespace healthcare
#endif  // _HEALTHCARE_HARVEST_RANGED_DECORATOR_H_
