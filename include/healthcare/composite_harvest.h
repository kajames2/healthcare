#ifndef _COMPOSITE_HARVEST_H_
#define _COMPOSITE_HARVEST_H_

#include <memory>
#include <vector>

#include "harvest.h"
#include "health_state.h"

namespace healthcare {
class CompositeHarvest : public Harvest {
public:
  CompositeHarvest();
  CompositeHarvest(std::vector<std::shared_ptr<Harvest>> harvest_strats);
  int GetWorkingHarvest(const HealthState &state) const override;
  void AddHarvest(std::shared_ptr<const Harvest> harvest);
  bool InRange(int period) const override;

protected:
  int CalculateHarvest(const HealthState &state) const override;

private:
  class NullHarvest;
  const Harvest& GetHarvestInRange(int period) const;

  std::vector<std::shared_ptr<const Harvest>> harvest_strats_;
  std::unique_ptr<NullHarvest> null_harvest_;

  class NullHarvest : public Harvest {
   public:
    bool InRange(int period) const override { return false; }
   protected:
    int CalculateHarvest(const HealthState& state) const override { return -1; }
  };
};
} // namespace healthcare
#endif // _COMPOSITE_HARVEST_H_
