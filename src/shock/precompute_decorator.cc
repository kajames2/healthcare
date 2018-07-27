#include "healthcare/shock/precompute_decorator.h"

namespace healthcare {
namespace shock {

PrecomputeDecorator::PrecomputeDecorator(const Shock &shock, int n_fitnesses)
    : cache_(n_fitnesses) {
  Precompute(shock);
}

void PrecomputeDecorator::Precompute(const Shock &shock) {
  for (int fit = 0; fit < cache_.size(); ++fit) {
    cache_[fit] = shock(fit);
  }
}

}  // namespace shock
}  // namespace healthcare
