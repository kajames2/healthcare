#include "consumption_precompute_decorator.h"

namespace healthcare {

ConsumptionPrecomputeDecorator::ConsumptionPrecomputeDecorator(
    const Consumption &consumption)
    : cache_(300) {
  Precompute(consumption);
}
ConsumptionPrecomputeDecorator::ConsumptionPrecomputeDecorator(
    const Consumption &consumption, int max_investment)
    : cache_(max_investment + 1) {
  Precompute(consumption);
};

double
ConsumptionPrecomputeDecorator::GetLifeEnjoyment(int health,
                                                 int life_investment) const {
  return cache_[life_investment][health];
};

void ConsumptionPrecomputeDecorator::Precompute(
    const Consumption &consumption) {
  for (int li = 0; li < cache_.size(); ++li) {
    for (int h = 0; h <= 100; ++h) {
      cache_[li][h] = consumption.GetLifeEnjoyment(h, li);
    }
  }
}
}
