#ifndef _HEALTHCARE_HARVEST_COMPOSITE_H_
#define _HEALTHCARE_HARVEST_COMPOSITE_H_

#include <memory>
#include <vector>

#include "healthcare/harvest.h"
#include "period_range.h"

class HealthState;

namespace healthcare {
class HarvestComposite : public Harvest {
 public:
  HarvestComposite();
  bool IsWorking(const HealthState &state) const override;
  int GetHarvest(const HealthState &state) const override;
  void AddHarvest(PeriodRange range, std::unique_ptr<const Harvest> harvest);

 private:
  int GetHarvestIndex(int period) const;
  std::vector<std::unique_ptr<const Harvest>> harvests_;
  std::vector<PeriodRange> ranges_;
};
}  // namespace healthcare
#endif  // _HEALTHCARE_HARVEST_COMPOSITE_H_
