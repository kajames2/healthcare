#include "healthcare/consumption/precompute_decorator.h"

namespace healthcare {
namespace consumption {

PrecomputeDecorator::PrecomputeDecorator(const Consumption &consumption)
    : cache_(301) {
  Precompute(consumption);
}

PrecomputeDecorator::PrecomputeDecorator(const Consumption &consumption,
                                         int max_investment)
    : cache_(max_investment + 1) {
  Precompute(consumption);
}

double PrecomputeDecorator::GetLifeEnjoyment(int health,
                                             int life_investment) const {
  return cache_[life_investment][health];
}

void PrecomputeDecorator::Precompute(const Consumption &consumption) {
  for (int li = 0; li < cache_.size(); ++li) {
    for (int h = 0; h <= 100; ++h) {
      cache_[li][h] = consumption.GetLifeEnjoyment(h, li);
    }
  }
}

}  // namespace consumption
}  // namespace healthcare
