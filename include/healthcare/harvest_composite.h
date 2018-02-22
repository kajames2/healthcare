#ifndef _HEALTHCARE_HARVEST_COMPOSITE_H_
#define _HEALTHCARE_HARVEST_COMPOSITE_H_

#include <vector>

#include "healthcare/harvest.h"
#include "healthcare/harvest_ranged_decorator.h"

class HealthState;

namespace healthcare {
class HarvestComposite : public Harvest {
 public:
  HarvestComposite();
  int GetHarvest(int age, int health) const override;
  void AddHarvest(HarvestRangedDecorator harvest);

 private:
  std::vector<HarvestRangedDecorator> harvests_;
};
}  // namespace healthcare
#endif  // _HEALTHCARE_HARVEST_COMPOSITE_H_
