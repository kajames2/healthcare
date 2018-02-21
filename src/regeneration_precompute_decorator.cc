#include "healthcare/regeneration_precompute_decorator.h"

namespace healthcare {

RegenerationPrecomputeDecorator::RegenerationPrecomputeDecorator(
    const Regeneration &regen)
    : regen_cache_(300) {
  Precompute(regen);
}

RegenerationPrecomputeDecorator::RegenerationPrecomputeDecorator(
    const Regeneration &regen, int max_investment)
    : regen_cache_(max_investment + 1) {
  Precompute(regen);
}

int RegenerationPrecomputeDecorator::GetHealthRegained(
    int health, int health_investment) const {
  return regen_cache_[health_investment][health];
}

int RegenerationPrecomputeDecorator::GetRegainCost(int health,
                                                   int health_regained) const {
  return cost_cache_[health_regained][health];
}

void RegenerationPrecomputeDecorator::Precompute(const Regeneration &regen) {
  for (int hi = 0; hi < regen_cache_.size(); ++hi) {
    for (int h = 0; h <= 100; ++h) {
      regen_cache_[hi][h] = regen.GetHealthRegained(h, hi);
    }
  }

  for (int h = 0; h <= 100; ++h) {
    for (int hr = 0; hr <= 100 - h; ++hr) {
      cost_cache_[hr][h] = regen.GetRegainCost(h, hr);
    }
  }
}
}  // namespace healthcare
