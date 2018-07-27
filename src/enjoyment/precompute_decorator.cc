#include "healthcare/enjoyment/precompute_decorator.h"

namespace healthcare {
namespace enjoyment {

PrecomputeDecorator::PrecomputeDecorator(const Enjoyment &enjoyment)
    : cache_(301) {
  Precompute(enjoyment);
}

PrecomputeDecorator::PrecomputeDecorator(const Enjoyment &enjoyment,
                                         int max_investment)
    : cache_(max_investment + 1) {
  Precompute(enjoyment);
}

void PrecomputeDecorator::Precompute(const Enjoyment &enjoyment) {
  for (int li = 0; li < cache_.size(); ++li) {
    for (int h = 0; h <= 100; ++h) {
      cache_[li][h] = enjoyment.GetEnjoyment(h, li);
    }
  }
}

}  // namespace enjoyment
}  // namespace healthcare
