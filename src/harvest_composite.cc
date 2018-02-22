#include "healthcare/harvest_composite.h"

#include <memory>
#include <utility>
#include <vector>

#include "healthcare/harvest_ranged_decorator.h"


namespace healthcare {
HarvestComposite::HarvestComposite() : harvests_() {}

int HarvestComposite::GetHarvest(int age, int health) const {
  int net_harvest = 0;
  for (auto& harvest : harvests_) {
    net_harvest += harvest.GetHarvest(age, health);
  }
  return net_harvest;
}

void HarvestComposite::AddHarvest(HarvestRangedDecorator harvest) {
  harvests_.push_back(std::move(harvest));
}

}  // namespace healthcare
