#include "healthcare/harvest_ranged_decorator.h"

#include <memory>
#include <utility>

#include "healthcare/age_range.h"

namespace healthcare {

HarvestRangedDecorator::HarvestRangedDecorator(
    AgeRange range, std::unique_ptr<const Harvest> harvest)
    : range_(range), harvest_(std::move(harvest)) {}

int HarvestRangedDecorator::GetHarvest(int age, int health) const {
  if (!InRange(range_, age)) {
    return 0;
  }
  return harvest_->GetHarvest(age, health);
}

}  // namespace healthcare
