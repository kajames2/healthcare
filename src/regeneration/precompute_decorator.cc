#include "healthcare/regeneration/precompute_decorator.h"

namespace healthcare {
namespace regeneration {

PrecomputeDecorator::PrecomputeDecorator(const Regeneration &regen)
    : regen_cache_(300) {
  Precompute(regen);
}

PrecomputeDecorator::PrecomputeDecorator(const Regeneration &regen,
                                         int max_investment)
    : regen_cache_(max_investment + 1) {
  Precompute(regen);
}

int PrecomputeDecorator::GetHealthRegained(int health,
                                           int health_investment) const {
  return regen_cache_[health_investment][health];
}

int PrecomputeDecorator::GetRegainCost(int health, int health_regained) const {
  return cost_cache_[health_regained][health];
}

void PrecomputeDecorator::Precompute(const Regeneration &regen) {
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

}  // namespace regeneration
}  // namespace healthcare
